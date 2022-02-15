
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LISTA_IDOSOS 0
#define LISTA_CUIDADORES 1
#define LISTA_LEITURAS 2

typedef struct lista Lista;
typedef struct celula Celula;

Lista *inicializarLista(int tipo);

void inserirFim(Lista *lista, void *cont);

void inserirInicio(Lista *lista, void *cont);

void imprimirLista(Lista *lista);

void *removerNaPosicao(Lista *lista, int pos);

// Enontra e retorna um elemento da lista com o nome correspondente, ou NULL
void *encontrarNome(Lista *lista, char *nome);

void destruirLista(Lista *lista);

#endif