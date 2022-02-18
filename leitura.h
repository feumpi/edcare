#ifndef LEITURA_H
#define LEITURA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct leitura Leitura;

// Inicializa um objeto leitura com os dados informados
Leitura* inicializarLeitura(int falecimento, int queda, int latitude, int longitude, float temperatura);

// Retorna se houve falecimento na leitura
int leituraFalecimento(Leitura* leitura);

// Retorna se houve queda na leitura
int leituraQueda(Leitura* leitura);

// Retorna a latitude registrada na leitura
int leituraLatitude(Leitura* leitura);

// Retorna a longitude registrada na leitura
int leituraLongitude(Leitura* leitura);

// Retorna a temperatura registrada na leitura
float leituraTemperatura(Leitura* leitura);

// Libera a memória alocada para a leitura
void destruirLeitura(Leitura* leitura);

#endif