/*
### Universidade Federal do Espírito Santo

### INF09292 - Estrutura de Dados I - 2021/2

### Primeiro trabalho

### Aluno: 2020205193 Felipe Pereira Umpierre

### Professora: Patricia Dockhorn Costa
*/

#include "leitura.h"

struct leitura {
    int falecimento;
    int queda;
    int latitude;
    int longitude;
    float temperatura;
};

Leitura* inicializarLeitura(int falecimento, int queda, int latitude, int longitude, float temperatura) {
    Leitura* leitura = malloc(sizeof(Leitura));

    leitura->falecimento = falecimento;
    leitura->queda = queda;
    leitura->latitude = latitude;
    leitura->longitude = longitude;
    leitura->temperatura = temperatura;

    return leitura;
}

int leituraFalecimento(Leitura* leitura) {
    return leitura->falecimento;
}

int leituraQueda(Leitura* leitura) {
    return leitura->queda;
}

int leituraLatitude(Leitura* leitura) {
    return leitura->latitude;
}

int leituraLongitude(Leitura* leitura) {
    return leitura->longitude;
}

float leituraTemperatura(Leitura* leitura) {
    return leitura->temperatura;
}

void destruirLeitura(Leitura* leitura) {
    free(leitura);
}