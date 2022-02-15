#include "edcare.h"

struct edcare {
    Lista *idosos;
    Lista *cuidadores;
    int leituraAtual;
};

EDCare *inicializarEDCare() {
    EDCare *edcare = malloc(sizeof(EDCare));

    edcare->idosos = inicializarLista(LISTA_IDOSOS);
    edcare->cuidadores = inicializarLista(LISTA_CUIDADORES);

    edcare->leituraAtual = -1;

    return edcare;
}

void carregarIdosos(EDCare *edcare) {
    // Abrir arquivo
    FILE *arq_apoio = fopen("in/apoio.txt", "r");

    char linha[100];

    int contador = 0;
    while (fgets(linha, 100, arq_apoio)) {
        // se for a primeira linha
        if (contador == 0) {
            // Enquanto encontrar nomes, cria idosos e adiciona na lista
            char *nomeAtual = strtok(linha, " ;\n");
            while (nomeAtual != NULL) {
                Idoso *idoso = inicializarIdoso(nomeAtual);
                inserirFim(edcare->idosos, idoso);
                nomeAtual = strtok(NULL, " ;\n");
            }
        }
        // próximas linhas: carregar amigos
        else {
            // primeiro nome (idoso a ser encontrado)
            char *nomeAtual = strtok(linha, " ;\n");
            // printf("nomeAtual: '%s'\n", nomeAtual);

            Idoso *idosoAtual = encontrarNome(edcare->idosos, nomeAtual);
            // printf("idosoAtual: '%s'\n\n", nomeIdoso(idosoAtual));

            nomeAtual = strtok(NULL, " ;\n");

            // se encontrado, enquanto houverem amigos na linha
            while (nomeAtual != NULL) {
                // insere o idoso na lista de amigos, se encontrado
                Idoso *amigo = encontrarNome(edcare->idosos, nomeAtual);

                // printf("nomeAtual: '%s'\n", nomeAtual);
                // printf("amigo: '%s'\n\n", nomeIdoso(amigo));

                if (amigo) {
                    inserirFim(meusAmigos(idosoAtual), amigo);

                    // também insere o idoso atual na lista do amigo
                    inserirFim(meusAmigos(amigo), idosoAtual);
                }

                nomeAtual = strtok(NULL, " ;\n");
            }
        }

        contador++;
    }

    fclose(arq_apoio);
}

void carregarCuidadores(EDCare *edcare) {
    // Abrir arquivos
    FILE *arq_cuidadores = fopen("in/cuidadores.txt", "r");

    char linha[100];

    int contador = 0;
    while (fgets(linha, 100, arq_cuidadores)) {
        // se for a primeira linha
        if (contador == 0) {
            // Enquanto encontrar nomes, cria cuidadores e adiciona na lista
            char *nomeAtual = strtok(linha, " ;\n");
            while (nomeAtual != NULL) {
                Cuidador *cuidador = inicializarCuidador(nomeAtual);
                // printf("cuidador criado: '%s'\n", nomeCuidador(cuidador));
                if (cuidador)
                    inserirFim(edcare->cuidadores, cuidador);

                nomeAtual = strtok(NULL, " ;\n");
            }
        }
        // próximas linhas: adicionar cuidadores aos idosos
        else {
            // primeiro nome (idoso a ser encontrado)
            char *nomeAtual = strtok(linha, " ;\n");
            // printf("nomeAtual: '%s'\n", nomeAtual);

            Idoso *idosoAtual = encontrarNome(edcare->idosos, nomeAtual);
            // printf("idosoAtual: '%s'\n\n", nomeAtual);

            nomeAtual = strtok(NULL, " ;\n");
            // printf("nomeAtual: '%s'\n", nomeAtual);

            // se encontrado, enquanto houverem cuidadores na linha
            while (nomeAtual != NULL) {
                // insere o idoso na lista de amigos, se encontrado
                Cuidador *cuidador = encontrarNome(edcare->cuidadores, nomeAtual);
                // printf("cuidador: '%s'\n\n", nomeCuidador(cuidador));

                if (cuidador) {
                    inserirFim(meusCuidadores(idosoAtual), cuidador);
                }

                nomeAtual = strtok(NULL, " ;\n");
                // printf("nomeAtual: '%s'\n", nomeAtual);
            }
        }
        contador++;
    }

    fclose(arq_cuidadores);
}

void proximaLeitura(EDCare *edcare) {
    edcare->leituraAtual++;

    Idoso *idoso = listaN(edcare->idosos, 0);
    FILE *arq = leiturasIdoso(idoso);

    if (!idoso) {
        printf("idoso nao encontrado\n");
        return;
    }

    if (!arq) {
        printf("arquivo não encontrado\n");
        return;
    }

    printf("idoso: %s\n", nomeIdoso(idoso));

    char linha[100];
    float temperatura;
    int latitude, longitude, queda;

    fgets(linha, 100, leiturasIdoso(idoso));

    sscanf(linha, "%f;%d;%d;%d", &temperatura, &latitude, &longitude, &queda);

    // se queda, acionar cuidador
    if (queda) {
        // encontrar cuidador mais próximo
    }
    // se febre alta, resetar febreBaixa e acionar cuidador
    else if (temperatura > 38) {
        resetarFebreBaixa(idoso);

        // encontrar cuidador mais próximo
        fprintf(saidaIdoso(idoso), "queda, acionou %s\n", "CuidadorX");

    }
    // febre baixa, acionar amigo ou cuidador se for recorrente
    else if (temperatura > 37) {
        incrementarFebreBaixa(idoso);

        if (febreBaixa(idoso) >= 4) {
            // encontrar cuidador mais próximo
            fprintf(saidaIdoso(idoso), "febre baixa pela quarta vez, acionou %s\n", "CuidadorX");
        }
        // encontrar amigo mais próximo
        else {
            fprintf(saidaIdoso(idoso), "febre baixa, acionou amigo %s\n", "XXX");
        }

    } else {
        fprintf(saidaIdoso(idoso), "tudo ok\n");
    }
}

Lista *listaIdosos(EDCare *edcare) {
    return edcare->idosos;
}

Lista *listaCuidadores(EDCare *edcare) {
    return edcare->cuidadores;
}

void destruirEDCare(EDCare *edcare) {
    destruirLista(edcare->idosos);
    destruirLista(edcare->cuidadores);
    free(edcare);
}