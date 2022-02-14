#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define IDOSOS 0
#define CUIDADORES 1

Lista *carregarIdosos();
Lista *carregarCuidadores();

int main()
{

    printf("EDCare\n\n");

    Lista *idosos = carregarIdosos();
    // Lista *cuidadores = inicializarLista();

    printf("Idosos carregados:\n");
    imprimirLista(idosos);

    return 0;
}

Lista *carregarIdosos()
{

    Lista *idosos = inicializarLista();

    // Abrir arquivos
    FILE *arq_apoio = fopen("in/apoio.txt", "r");

    char linha[100];

    int contador = 0;
    while (fgets(linha, 100, arq_apoio))
    {
        // se for a primeira linha
        if (contador == 0)
        {
            // Enquanto encontrar nomes, adiciona na lista idosos
            char *nomeAtual = strtok(linha, ";");
            while (nomeAtual != NULL)
            {
                inserirFim(idosos, nomeAtual);
                nomeAtual = strtok(NULL, ";");
            }
        }

        contador++;
    }

    fclose(arq_apoio);

    return idosos;
}

Lista *carregarCuidadores()
{

    Lista *cuidadores = inicializarLista();

    FILE *arq_cuidadores = fopen("in/cuidadores.txt", "r");
}