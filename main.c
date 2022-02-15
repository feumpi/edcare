#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cuidador.h"
#include "edcare.h"
#include "idoso.h"
#include "leitura.h"
#include "lista.h"

#define IDOSOS 0
#define CUIDADORES 1

void carregarIdosos(Lista *lista);
void carregarCuidadores(Lista *cuidadores, Lista *idosos);

// FIXME: carregar as listas de amigos e de cuidadores para dentro das listas dos idosos (SEGFAULT)

int main() {
    printf("EDCare\n\n");

    EDCare *edcare = inicializarEDCare();

    carregarIdosos(listaIdosos(edcare));
    carregarCuidadores(listaCuidadores(edcare), listaIdosos(edcare));

    imprimirLista(listaIdosos(edcare));
    imprimirLista(listaCuidadores(edcare));

    /* Idoso *idoso = encontrarNome(listaIdosos(edcare), "Joao");

    if (idoso) {
        printf("Amigos de %s:\n", nomeIdoso(idoso));
        imprimirLista(meusAmigos(idoso));
    } */

    return 0;
}

void carregarIdosos(Lista *lista) {
    // Abrir arquivos
    FILE *arq_apoio = fopen("in/apoio.txt", "r");

    char linha[100];

    int contador = 0;
    while (fgets(linha, 100, arq_apoio)) {
        // se for a primeira linha
        if (contador == 0) {
            // Enquanto encontrar nomes, cria idosos e adiciona na lista
            char *nomeAtual = strtok(linha, ";\n");
            while (nomeAtual != NULL) {
                Idoso *idoso = inicializarIdoso(nomeAtual);
                inserirFim(lista, idoso);
                nomeAtual = strtok(NULL, ";\n");
            }
        }
        // próximas linhas: carregar amigos
        else {
            // primeiro nome (idoso a ser encontrado)
            char *nomeAtual = strtok(linha, ";\n");
            printf("nomeAtual: '%s'\n", nomeAtual);

            Idoso *idosoAtual = encontrarNome(lista, nomeAtual);
            printf("idosoAtual: '%s'\n\n", nomeIdoso(idosoAtual));

            nomeAtual = strtok(NULL, ";\n");

            // se encontrado, enquanto houverem amigos na linha
            while (nomeAtual != NULL) {
                // insere o idoso na lista de amigos, se encontrado
                Idoso *amigo = encontrarNome(lista, nomeAtual);

                // printf("nomeAtual: '%s'\n", nomeAtual);
                // printf("amigo: '%s'\n\n", nomeIdoso(amigo));

                if (amigo) {
                    inserirFim(meusAmigos(idosoAtual), amigo);

                    // também insere o idoso atual na lista do amigo
                    inserirFim(meusAmigos(amigo), idosoAtual);
                }

                nomeAtual = strtok(NULL, ";\n");
            }
        }

        contador++;
    }

    fclose(arq_apoio);
}

void carregarCuidadores(Lista *cuidadores, Lista *idosos) {
    // Abrir arquivos
    FILE *arq_cuidadores = fopen("in/cuidadores.txt", "r");

    char linha[100];

    int contador = 0;
    while (fgets(linha, 100, arq_cuidadores)) {
        // se for a primeira linha
        if (contador == 0) {
            // Enquanto encontrar nomes, cria cuidadores e adiciona na lista
            char *nomeAtual = strtok(linha, ";\n");
            while (nomeAtual != NULL) {
                Cuidador *cuidador = inicializarCuidador(nomeAtual);

                if (cuidador)
                    inserirFim(cuidadores, cuidador);

                nomeAtual = strtok(NULL, ";\n");
            }
        }
        // próximas linhas: adicionar cuidadores aos idosos
        /* else {
            // primeiro nome (idoso a ser encontrado)
            char *nomeAtual = strtok(linha, ";");
            Idoso *idosoAtual = encontrarNome(idosos, nomeAtual);

            // se encontrado, enquanto houverem cuidadores na linha
            while (nomeAtual != NULL) {
                // insere o idoso na lista de amigos, se encontrado
                Cuidador *cuidador = encontrarNome(cuidadores, nomeAtual);
                inserirFim(meusCuidadores(idosoAtual), cuidador);

                nomeAtual = strtok(NULL, ";");
            }
        } */
        contador++;
    }

    fclose(arq_cuidadores);
}
