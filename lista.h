
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

// Cria uma lista do tipo LISTA_IDOSOS ou LISTA_CUIDADORES
Lista *inicializarLista(int tipo);

// Retorna o N elemento da lista
void *listaN(Lista *lista, int n);

// Insere um idoso ou cuidador no final da lista
void inserirFim(Lista *lista, void *cont);

// Insere um idoso ou cuidador no começo da lista
void inserirInicio(Lista *lista, void *cont);

// Imprime o nome dos idosos ou cuidadores na lista
void imprimirLista(Lista *lista);

// Remove um idoso ou cuidador numa posição especifica da lista
void *removerNaPosicao(Lista *lista, int pos);

// Enontra e retorna um idoso ou cuidador da lista com o nome correspondente, ou NULL se não encontrado
void *encontrarNome(Lista *lista, char *nome);

// Libera a memória usada pela lista, mas não libera os elementos
void destruirLista(Lista *lista);

#endif