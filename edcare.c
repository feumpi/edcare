#include "edcare.h"

struct edcare {
    int casoTeste;
    Lista *idosos;
    Lista *cuidadores;
    int leituraAtual;
    int quantidadeIdosos;
    int quantidadeCuidadores;
    int quantidadeLeituras;
    int acabou;
};

EDCare *inicializarEDCare(int casoTeste) {
    EDCare *edcare = malloc(sizeof(EDCare));

    edcare->casoTeste = casoTeste;

    edcare->idosos = inicializarLista(LISTA_IDOSOS);
    edcare->cuidadores = inicializarLista(LISTA_CUIDADORES);

    edcare->leituraAtual = -1;
    edcare->quantidadeIdosos = 0;
    edcare->quantidadeCuidadores = 0;
    edcare->quantidadeLeituras = 0;

    return edcare;
}

void carregarIdosos(EDCare *edcare) {
    // Carrega o arquivo da rede de apoio, para o caso de teste especificado
    char caminho[50];
    sprintf(caminho, "in/%d/apoio.txt", edcare->casoTeste);
    FILE *arq_apoio = fopen(caminho, "r");

    char linha[100];

    int contador = 0;
    while (fgets(linha, 100, arq_apoio)) {
        // se for a primeira linha (nomes de todos os idosos)
        if (contador == 0) {
            // Enquanto encontrar nomes, cria idosos e adiciona na lista
            char *nomeAtual = strtok(linha, " ;\n");
            while (nomeAtual != NULL) {
                Idoso *idoso = inicializarIdoso(nomeAtual, edcare->casoTeste);
                inserirFim(edcare->idosos, idoso);
                edcare->quantidadeIdosos++;
                nomeAtual = strtok(NULL, " ;\n");
            }

            printf("%d idosos carregados: ", edcare->quantidadeIdosos);
            imprimirLista(edcare->idosos);
        }
        // próximas linhas: carregar amigos
        else {
            // primeiro nome (idoso a ser encontrado)
            char *nomeAtual = strtok(linha, " ;\n");

            // encontra o idoso na lista
            Idoso *idosoAtual = encontrarNome(edcare->idosos, nomeAtual);

            // próximo nome: amigo do idoso
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

                // avança para o próximo nome, se houver
                nomeAtual = strtok(NULL, " ;\n");
            }
        }

        contador++;
    }

    fclose(arq_apoio);
}

void carregarCuidadores(EDCare *edcare) {
    // Carrega o arquivo de cuidadores, para o caso de teste especificado
    char caminho[50];
    sprintf(caminho, "in/%d/cuidadores.txt", edcare->casoTeste);
    FILE *arq_cuidadores = fopen(caminho, "r");

    char linha[100];

    int contador = 0;
    while (fgets(linha, 100, arq_cuidadores)) {
        // se for a primeira linha (nomes de todos os cuidadores)
        if (contador == 0) {
            // Enquanto encontrar nomes, cria cuidadores e adiciona na lista
            char *nomeAtual = strtok(linha, " ;\n");
            while (nomeAtual != NULL) {
                Cuidador *cuidador = inicializarCuidador(nomeAtual, edcare->casoTeste);

                if (cuidador) {
                    inserirFim(edcare->cuidadores, cuidador);
                    edcare->quantidadeCuidadores++;

                    // Após carregar o primeiro cuidador, determinar a quantidade de leituras totais do caso
                    // Necessário pois os idosos podem ter quantidade de leituras diferentes devido ao falecimento
                    if (edcare->quantidadeCuidadores == 1) {
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

            printf("%d cuidadores carregados: ", edcare->quantidadeCuidadores);
            imprimirLista(edcare->cuidadores);

        }
        // próximas linhas: adicionar cuidadores aos idosos
        else {
            // primeiro nome (idoso a ser encontrado)
            char *nomeAtual = strtok(linha, " ;\n");

            Idoso *idosoAtual = encontrarNome(edcare->idosos, nomeAtual);
            // printf("idosoAtual: '%s'\n\n", nomeAtual);

            // próximo nome: cuidador
            nomeAtual = strtok(NULL, " ;\n");

            // se encontrado, enquanto houverem cuidadores na linha
            while (nomeAtual != NULL) {
                // insere o idoso na lista de amigos, se encontrado
                Cuidador *cuidador = encontrarNome(edcare->cuidadores, nomeAtual);
                // printf("cuidador: '%s'\n\n", nomeCuidador(cuidador));

                if (cuidador) {
                    inserirFim(meusCuidadores(idosoAtual), cuidador);
                    incrementarCuidadores(idosoAtual);
                }

                // avança para o nome do próximo cuidador, se houver
                nomeAtual = strtok(NULL, " ;\n");
            }
        }
        contador++;
    }

    fclose(arq_cuidadores);
}

void realizarLeituras(EDCare *edcare) {
    printf("\nO caso de teste possui %d leituras\n", edcare->quantidadeLeituras);

    // Para cada leitura do caso
    while (edcare->leituraAtual < edcare->quantidadeLeituras - 1) {
        edcare->leituraAtual++;

        printf("Rodando leitura %d...\n", edcare->leituraAtual + 1);

        // Para cada idoso da lista
        for (int i = 0; i < edcare->quantidadeIdosos; i++) {
            Idoso *idoso = listaN(edcare->idosos, i);

            // Ignora idoso que já faleceu
            if (idosoFaleceu(idoso)) {
                continue;
            }

            // Obtém a próxima leitura do idoso atual
            Leitura *leitura = leituraIdoso(idoso, edcare->leituraAtual);

            // Se houver falecimento, interromper tratamento do idoso
            if (leituraFalecimento(leitura)) {
                imprimirSaida(idoso, "falecimento");
                continue;
            }

            char saida[100];

            // se queda, acionar cuidador mais próximo
            if (leituraQueda(leitura)) {
                sprintf(saida, "queda, acionou %s", nomeCuidador(cuidadorMaisProximo(idoso, leituraLatitude(leitura), leituraLongitude(leitura))));
                imprimirSaida(idoso, saida);
                // encontrar cuidador mais próximo
            }
            // se febre alta, resetar febreBaixa e acionar cuidador mais próximo
            else if (leituraTemperatura(leitura) >= 38) {
                resetarFebreBaixa(idoso);

                sprintf(saida, "febre alta, acionou %s", nomeCuidador(cuidadorMaisProximo(idoso, leituraLatitude(leitura), leituraLongitude(leitura))));
                imprimirSaida(idoso, saida);

            }
            // febre baixa, acionar amigo ou cuidador se for recorrente
            else if (leituraTemperatura(leitura) >= 37) {
                incrementarFebreBaixa(idoso);

                // se a febre baixa já ocorreu 4 ou mais vezes, cuidador mais próximo
                if (febreBaixa(idoso) >= 4) {
                    sprintf(saida, "febre baixa pela quarta vez, acionou %s", nomeCuidador(cuidadorMaisProximo(idoso, leituraLatitude(leitura), leituraLongitude(leitura))));
                    imprimirSaida(idoso, saida);
                }
                // se não for recorrente, amigo mais próximo
                else {
                    sprintf(saida, "febre baixa, acionou amigo %s", nomeIdoso(amigoMaisProximo(idoso, leituraLatitude(leitura), leituraLongitude(leitura))));
                    imprimirSaida(idoso, saida);
                }

            }
            // nada ocorreu
            else {
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
    // Destrói as listas de idosos e cuidadores, e também os próprios elementos
    destruirLista(edcare->idosos, 1);
    destruirLista(edcare->cuidadores, 1);

    // Libera o objeto EDCare
    free(edcare);
}