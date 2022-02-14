#include "leitura.h"

struct leitura {
    float latitude;
    float longitude;
    float temperatura;
    int queda;
};

Leitura *inicializarLeitura(float latitude, float longitude, float temperatura, int queda) {
    Leitura *leitura = malloc(sizeof(Leitura));

    leitura->latitude = latitude;
    leitura->longitude = longitude;
    leitura->temperatura = temperatura;
    leitura->queda = queda;

    return leitura;
}

void destruirLeitura(Leitura *leitura);