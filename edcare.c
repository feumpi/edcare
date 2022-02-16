#include "edcare.h"

struct edcare {
    Lista *idosos;
    Lista *cuidadores;
    int leituraAtual;
    int quantidadeIdosos;
    int quantidadeCuidadoes;
    int quantidadeLeituras;
    int acabou;
};

EDCare *inicializarEDCare() {
    EDCare *edcare = malloc(sizeof(EDCare));

    edcare->idosos = inicializarLista(LISTA_IDOSOS);
    edcare->cuidadores = inicializarLista(LISTA_CUIDADORES);

    edcare->leituraAtual = -1;
    edcare->quantidadeIdosos = 0;
    edcare->quantidadeCuidadoes = 0;
    edcare->quantidadeLeituras = 0;

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
                edcare->quantidadeIdosos++;
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
                Idoso *amigo = encontrarNome(edcare->idosos, nomeAtual);

                // insere o idoso na lista de amigos, se encontrado
                if (amigo) {
                    inserirFim(meusAmigos(idosoAtual), amigo);
                    incrementarAmigos(idosoAtual);

                    // também insere o idoso atual na lista do amigo
                    inserirFim(meusAmigos(amigo), idosoAtual);
                    incrementarAmigos(amigo);
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
                if (cuidador) {
                    inserirFim(edcare->cuidadores, cuidador);
                    edcare->quantidadeCuidadoes++;

                    // Se apenas 1 cuidador carregado, determinar a quantidade de leituras
                    if (edcare->quantidadeCuidadoes == 1) {
                        // abrir o arquivo leituras do cuidador, contar as linhas, salvar e voltar pro começo
                        int linhas = 0;
                        char c;

                        // enquanto não achar o fim do arquivo, lê um novo char e incrementa linhas de for \n
                        while (!feof(leiturasCuidador(cuidador))) {
                            c = getc(leiturasCuidador(cuidador));
                            if (c == '\n') linhas++;
                        }

                        // salva a quantidade de linhas (leituras)
                        edcare->quantidadeLeituras = linhas;

                        // volta pro começo do arquivo
                        rewind(leiturasCuidador(cuidador));
                    }
                }

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
                    incrementarCuidadores(idosoAtual);
                }

                nomeAtual = strtok(NULL, " ;\n");
                // printf("nomeAtual: '%s'\n", nomeAtual);
            }
        }
        contador++;
    }

    fclose(arq_cuidadores);
}

void realizarLeituras(EDCare *edcare) {
    while (edcare->leituraAtual < edcare->quantidadeLeituras - 1) {
        edcare->leituraAtual++;

        // Para cada idoso da lista
        for (int i = 0; i < edcare->quantidadeIdosos; i++) {
            Idoso *idoso = listaN(edcare->idosos, i);

            // Ignora idoso que já faleceu
            if (idosoFaleceu(idoso)) {
                continue;
            }

            char leitura[100];
            float temperatura;
            int falecimento = 0, queda = 0, latitude, longitude;

            leituraIdoso(idoso, &falecimento, &queda, &temperatura, &latitude, &longitude);

            // Se houve falecimento, interromper tratamento do idoso
            if (falecimento) {
                imprimirSaida(idoso, "falecimento");
                continue;
            }

            char saida[100];

            // se queda, acionar cuidador
            if (queda) {
                sprintf(saida, "queda, acionou %s", "CuidadorX");
                imprimirSaida(idoso, saida);
                // encontrar cuidador mais próximo
            }
            // se febre alta, resetar febreBaixa e acionar cuidador
            else if (temperatura >= 38) {
                resetarFebreBaixa(idoso);

                // encontrar cuidador mais próximo
                sprintf(saida, "febre alta, acionou %s", "CuidadorX");
                imprimirSaida(idoso, saida);

            }
            // febre baixa, acionar amigo ou cuidador se for recorrente
            else if (temperatura >= 37) {
                incrementarFebreBaixa(idoso);

                if (febreBaixa(idoso) >= 4) {
                    // encontrar cuidador mais próximo
                    sprintf(saida, "febre baixa pela quarta vez, acionou %s", "CuidadorX");
                    imprimirSaida(idoso, saida);
                }
                // encontrar amigo mais próximo (considerar possivel falecimento)
                else {
                    sprintf(saida, "febre baixa, acionou amigo %s", "XXX");
                    imprimirSaida(idoso, saida);
                }

            } else {
                sprintf(saida, "tudo ok");
                imprimirSaida(idoso, saida);
            }
        }
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