
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista Lista;
typedef struct celula Celula;

Lista *inicializarLista();

void inserirFim(Lista *lista, void *cont);

void inserirInicio(Lista *lista, void *cont);

void imprimirLista(Lista *lista);

void *removerNaPosicao(Lista *lista, int pos);

void destruirLista(Lista *lista);

#endif