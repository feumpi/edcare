
#include "lista.h"

#include <stdlib.h>
#include <string.h>

#include "cuidador.h"
#include "idoso.h"

struct lista {
    Celula *prim;
    Celula *ult;
    int tipo;
};

struct celula {
    void *cont;
    Celula *prox;
};

Lista *inicializarLista(int tipo) {
    Lista *lista = malloc(sizeof(Lista));
    lista->tipo = tipo;
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void *listaN(Lista *lista, int n) {
    Celula *atual = lista->prim;
    Celula *anterior = NULL;

    int posAtual = 0;

    while (atual && posAtual != n) {
        anterior = atual;
        atual = atual->prox;
        posAtual++;
    }

    if (!atual) {
        printf("pos %d invalida\n", n);
        return NULL;
    }

    return atual->cont;
}

void imprimirLista(Lista *lista) {
    printf("----------\n");
    for (Celula *celula = lista->prim; celula != NULL; celula = celula->prox) {
        if (lista->tipo == LISTA_IDOSOS) {
            imprimirIdoso(celula->cont);
        }

        if (lista->tipo == LISTA_CUIDADORES) {
            imprimirCuidador(celula->cont);
        }
    }
    printf("----------\n\n");
}

void inserirInicio(Lista *lista, void *cont) {
    Celula *celula = malloc(sizeof(Celula));
    celula->cont = cont;

    celula->prox = lista->prim;
    lista->prim = celula;

    //! lista->ult equivalente a lista->ult == NULL
    if (!lista->ult)
        lista->ult = celula;
}

void inserirFim(Lista *lista, void *cont) {
    Celula *celula = malloc(sizeof(Celula));
    celula->cont = cont;
    celula->prox = NULL;

    if (lista->ult) {
        lista->ult->prox = celula;
    }

    lista->ult = celula;

    if (!lista->prim)
        lista->prim = celula;
}

void *removerNaPosicao(Lista *lista, int pos) {
    void *cont;

    Celula *atual = lista->prim;
    Celula *anterior = NULL;

    int posAtual = 0;

    while (atual && posAtual != pos) {
        anterior = atual;
        atual = atual->prox;
        posAtual++;
    }

    if (!atual)
        return NULL;

    cont = atual->cont;

    // Igual ao primeiro e último (único elemento)
    if (atual == lista->prim && atual == lista->ult) {
        lista->prim = NULL;
        lista->ult = NULL;
    }
    // Igual a somente o primeiro
    else if (atual == lista->prim) {
        lista->prim = atual->prox;
    }
    // Igual a somente o último
    else if (atual == lista->ult) {
        lista->ult = anterior;
        anterior->prox = NULL;
    }
    // Nem o último, nem o primeiro
    else {
        anterior->prox = atual->prox;
    }

    free(atual);
    return cont;
}

void *encontrarNome(Lista *lista, char *nome) {
    Celula *atual = lista->prim;
    Celula *anterior = NULL;

    int posAtual = 0;
    char *nomeAtual = NULL;

    // iterar a lista
    while (atual) {
        if (lista->tipo == LISTA_IDOSOS)
            nomeAtual = nomeIdoso(atual->cont);

        if (lista->tipo == LISTA_CUIDADORES)
            nomeAtual = nomeCuidador(atual->cont);

        if (nomeAtual && strcmp(nomeAtual, nome) == 0) {
            return atual->cont;
        }

        anterior = atual;
        atual = atual->prox;
        posAtual++;
    }

    return NULL;
}

void destruirLista(Lista *lista, int destruirElementos) {
    Celula *atual = lista->prim;
    Celula *prox = atual->prox;

    // Iterar a lista
    while (atual) {
        // Destrói os elementos, se solicitado
        if (destruirElementos && lista->tipo == LISTA_IDOSOS) destruirIdoso(atual->cont);
        if (destruirElementos && lista->tipo == LISTA_CUIDADORES) destruirCuidador(atual->cont);
        if (destruirElementos && lista->tipo == LISTA_LEITURAS) destruirLeitura(atual->cont);

        // Libera a célula
        prox = atual->prox;
        free(atual);

        atual = prox;
    }

    // Liberar a lista
    free(lista);
}