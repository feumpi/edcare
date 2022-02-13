//  listaMat.c: implementação do TAD Lista de chares. Nesta implementação, não serão criadas e nem liberadas nomees. Isso será função do cliente testador. Apenas manipulem células da lista, como explicado nos vídeos.

#include "lista.h"
#include <stdlib.h>

struct lista
{
    Celula *prim;
    Celula *ult;
};

struct celula
{
    char *cont;
    Celula *prox;
};

Lista *inicializarLista()
{
    Lista *lista = malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void imprimirLista(Lista *lista)
{
    printf("----------\n");
    for (Celula *celula = lista->prim; celula != NULL; celula = celula->prox)
    {
        printf("%s", celula->cont);
        printf("\n");
    }
    printf("----------\n\n");
}

void inserirInicio(Lista *lista, char *nome)
{
    Celula *celula = malloc(sizeof(Celula));
    celula->cont = nome;

    celula->prox = lista->prim;
    lista->prim = celula;

    //!lista->ult equivalente a lista->ult == NULL
    if (!lista->ult)
        lista->ult = celula;
}

void inserirFim(Lista *lista, char *nome)
{
    Celula *celula = malloc(sizeof(Celula));
    celula->cont = nome;
    celula->prox = NULL;

    if (lista->ult)
    {
        lista->ult->prox = celula;
    }

    lista->ult = celula;

    if (!lista->prim)
        lista->prim = celula;
}

char *removerNaPosicao(Lista *lista, int pos)
{
    char *nome;

    Celula *atual = lista->prim;
    Celula *anterior = NULL;

    int posAtual = 0;

    while (atual && posAtual != pos)
    {
        anterior = atual;
        atual = atual->prox;
        posAtual++;
    }

    if (!atual)
        return NULL;

    nome = atual->cont;

    //Igual ao primeiro e último (único elemento)
    if (atual == lista->prim && atual == lista->ult)
    {
        lista->prim = NULL;
        lista->ult = NULL;
    }
    //Igual a somente o primeiro
    else if (atual == lista->prim)
    {
        lista->prim = atual->prox;
    }
    //Igual a somente o último
    else if (atual == lista->ult)
    {
        lista->ult = anterior;
        anterior->prox = NULL;
    }
    //Nem o último, nem o primeiro
    else
    {
        anterior->prox = atual->prox;
    }

    free(atual);
    return nome;
}

void destruirLista(Lista *lista)
{

    Celula *atual = lista->prim;
    Celula *prox = atual->prox;

    //Liberar todas as células
    while (atual)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    //Liberar a lista
    free(lista);
}