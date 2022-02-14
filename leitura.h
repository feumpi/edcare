#ifndef LEITURA_H
#define LEITURA_H

typedef struct leitura Leitura;

Leitura *inicializarLeitura(float latitude, float longitude, float temperatura, int queda);

void destruirLeitura(Leitura *leitura);

#endif