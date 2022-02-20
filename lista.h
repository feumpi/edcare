
/*
### Universidade Federal do Espírito Santo

### INF09292 - Estrutura de Dados I - 2021/2

### Primeiro trabalho

### Aluno: 2020205193 Felipe Pereira Umpierre

### Professora: Patricia Dockhorn Costa
*/

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

// Insere um elemento no final da lista
void inserirFim(Lista *lista, void *cont);

// Insere um elemento no começo da lista
void inserirInicio(Lista *lista, void *cont);

// Imprime o nome dos idosos ou cuidadores na lista
void imprimirLista(Lista *lista);

// Remove elemento numa posição especifica da lista
void *removerNaPosicao(Lista *lista, int pos);

// Enontra e retorna um idoso ou cuidador da lista com o nome correspondente, ou NULL se não encontrado
void *encontrarNome(Lista *lista, char *nome);

// Libera a memória usada pela lista, e também os elementos, se for solicitado
void destruirLista(Lista *lista, int destruirElementos);

#endif