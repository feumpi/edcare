#ifndef IDOSO_H
#define IDOSO_H

#include <stdlib.h>
#include <string.h>

#include "leitura.h"
#include "lista.h"

typedef struct idoso Idoso;

// Inicializa um idoso com o nome correspondente, cria as listas necessárias e abre o arquivo de leituras
Idoso* inicializarIdoso(char* nome);

// Retorna o nome do idoso
char* nomeIdoso(Idoso* idoso);

// Retorna a lista de amigos (rede de apoio) do idoso
Lista* meusAmigos(Idoso* idoso);

// Retorna a lista de cuidadores do idoso
Lista* meusCuidadores(Idoso* idoso);

// Retorna o arquivo de leituras do idoso
FILE* leiturasIdoso(Idoso* idoso);

// Retorna o arquivo de saída do idoso
FILE* saidaIdoso(Idoso* idoso);

// Retorna a quantidade de vezes que o idoso teve febre baixa
int febreBaixa(Idoso* idoso);

// Incrementa a quantidade de vezes que o idoso teve febre baixa
void incrementarFebreBaixa(Idoso* idoso);

// Reseta a quantidade de vezes que o idoso teve febre baixa
void resetarFebreBaixa(Idoso* idoso);

// Imprime o nome do idoso
void imprimirIdoso(Idoso* idoso);

// Libera a memória alocada para o idoso, fecha o arquivo de leituras e destrói as próprias listas
void destruirIdoso(Idoso* idoso);

#endif