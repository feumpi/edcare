/*
### Universidade Federal do Espírito Santo

### INF09292 - Estrutura de Dados I - 2021/2

### Primeiro trabalho

### Aluno: 2020205193 Felipe Pereira Umpierre

### Professora: Patricia Dockhorn Costa
*/

#ifndef CUIDADOR_H
#define CUIDADOR_H

#include <stdlib.h>
#include <string.h>

#include "leitura.h"
#include "lista.h"

typedef struct cuidador Cuidador;

// Inicializa um cuidador com o nome correspondente e abre o arquivo de leituras
Cuidador* inicializarCuidador(char* nome, int casoTeste);

// Retorna o nome do cuidador
char* nomeCuidador(Cuidador* cuidador);

// Obtém a posição do cuidador no índice de leitura desejado e guarda nos ponteiros informados
void posicaoCuidador(Cuidador* cuidador, int indice, int* latitude, int* longitude);

// temporario: retorna o arquivo de leituras do cuidador
FILE* leiturasCuidador(Cuidador* cuidador);

// Imprime o nome do cuidador
void imprimirCuidador(Cuidador* cuidador);

// Libera a memória alocada para o cuidador e fecha o arquivo de leituras
void destruirCuidador(Cuidador* cuidador);

#endif