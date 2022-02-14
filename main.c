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

void carregarIdosos();
void carregarCuidadores();

int main() {
    printf("EDCare\n\n");

    EDCare *edcare = inicializarEDCare();

    carregarIdosos(listaIdosos(edcare));
    carregarCuidadores(listaCuidadores(edcare));

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
            char *nomeAtual = strtok(linha, ";");
            while (nomeAtual != NULL) {
                Idoso *idoso = inicializarIdoso(nomeAtual);
                inserirFim(lista, idoso);
                nomeAtual = strtok(NULL, ";");
            }
        }

        contador++;
    }

    fclose(arq_apoio);
}

void carregarCuidadores(Lista *lista) {
    // Abrir arquivos
    FILE *arq_cuidadores = fopen("in/cuidadores.txt", "r");

    char linha[100];

    int contador = 0;
    while (fgets(linha, 100, arq_cuidadores)) {
        // se for a primeira linha
        if (contador == 0) {
            // Enquanto encontrar nomes, cria cuidadores e adiciona na lista
            char *nomeAtual = strtok(linha, ";");
            while (nomeAtual != NULL) {
                Cuidador *cuidador = inicializarCuidador(nomeAtual);
                inserirFim(lista, cuidador);
                nomeAtual = strtok(NULL, ";");
            }
        }

        contador++;
    }

    fclose(arq_cuidadores);
}
