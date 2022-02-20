#ifndef IDOSO_H
#define IDOSO_H

#include <stdlib.h>
#include <string.h>

#include "cuidador.h"
#include "leitura.h"
#include "lista.h"
#include "math.h"

typedef struct idoso Idoso;

// Inicializa um idoso com o nome correspondente, cria as listas necessárias e abre o arquivo de leituras
Idoso* inicializarIdoso(char* nome, int casoTeste);

// Retorna o nome do idoso
char* nomeIdoso(Idoso* idoso);

// Retorna a lista de amigos (rede de apoio) do idoso
Lista* meusAmigos(Idoso* idoso);

// Incrementa a quantidade de amigos do idoso
void incrementarAmigos(Idoso* idoso);

// Retorna a distância entre duas coordenadas
float calcularDistancia(int lat1, int long1, int lat2, int long2);

// Retorna o amigo mais próximo da posição informada
Idoso* amigoMaisProximo(Idoso* idoso, int latitude, int longitude);

// Retorna a lista de cuidadores do idoso
Lista* meusCuidadores(Idoso* idoso);

// Retorna o cuidador mais próximo da posição informada
Cuidador* cuidadorMaisProximo(Idoso* idoso, int latitude, int longitude);

// Incrementa a quantidade de cuidadores do idoso
void incrementarCuidadores(Idoso* idoso);

// Realiza a próxima leitura do idoso e armazena os dados nos ponteiros fornecidos
Leitura* leituraIdoso(Idoso* idoso);

// Retorna a latitude do idoso
int minhaLatitude(Idoso* idoso);

// Retorna a longitude do idoso
int minhaLongitude(Idoso* idoso);

// Imprime uma saída no arquivo do idoso
void imprimirSaida(Idoso* idoso, char* saida);

// Retorna a quantidade de vezes que o idoso teve febre baixa
int febreBaixa(Idoso* idoso);

// Incrementa a quantidade de vezes que o idoso teve febre baixa
void incrementarFebreBaixa(Idoso* idoso);

// Reseta a quantidade de vezes que o idoso teve febre baixa
void resetarFebreBaixa(Idoso* idoso);

// Retorna 1 se o idoso faleceu, ou 0 se não
int idosoFaleceu(Idoso* idoso);

// Registra que houve falecimento do idoso
void registrarFalecimento(Idoso* idoso);

// Imprime o nome do idoso
void imprimirIdoso(Idoso* idoso);

// Libera a memória alocada para o idoso, fecha o arquivo de leituras e destrói as próprias listas
void destruirIdoso(Idoso* idoso);

#endif