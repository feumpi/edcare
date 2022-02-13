#include <stdio.h>
#include "lista.h"

int main()
{

    printf("EDCare\n");

    Lista *lista = inicializarLista();

    inserirFim(lista, "Joao");
    inserirFim(lista, "Maria");
    inserirFim(lista, "Carlos");

    imprimirLista(lista);

    removerNaPosicao(lista, 1);

    imprimirLista(lista);

    destruirLista(lista);

    return 0;
}