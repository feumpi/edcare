//listaMat.h: especificação do TAD Lista de Matrizes com funções de criação, inserção, retirada, impressão e liberação de memória; o retira só vai fazer sentido considerando a posição da matriz na lista.

#ifndef LISTAMAT_H_
#define LISTAMAT_H_

#include <stdio.h>

typedef struct lista Lista;
typedef struct celula Celula;

Lista *inicializarLista();

void inserirFim(Lista *lista, char *matriz);

void inserirInicio(Lista *lista, char *matriz);

void imprimirLista(Lista *lista);

char *removerNaPosicao(Lista *lista, int pos);

void destruirLista(Lista *lista);

#endif