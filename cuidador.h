#ifndef CUIDADOR_H
#define CUIDADOR_H

#include <stdlib.h>
#include <string.h>

#include "leitura.h"
#include "lista.h"

typedef struct cuidador Cuidador;

// Inicializa um cuidador com o nome correspondente e abre o arquivo de leituras
Cuidador* inicializarCuidador(char* nome);

// Retorna o nome do cuidador
char* nomeCuidador(Cuidador* cuidador);

// Realiza a próxima leitura do cuidador e guarda os dados nos ponteiros informados
void leituraCuidador(Cuidador* cuidador, int* latitude, int* longitude);

// temporario: retorna o arquivo de leituras do cuidador
FILE* leiturasCuidador(Cuidador* cuidador);

// Imprime o nome do cuidador
void imprimirCuidador(Cuidador* cuidador);

// Libera a memória alocada para o cuidador e fecha o arquivo de leituras
void destruirCuidador(Cuidador* cuidador);

#endif