#include "cuidador.h"

struct cuidador {
    char *nome;
    FILE *leituras;
    int leituraAtual;
};

Cuidador *
inicializarCuidador(char *nome, int casoTeste) {
    Cuidador *cuidador = malloc(sizeof(Cuidador));

    cuidador->nome = strdup(nome);

    char caminho[50];
    sprintf(caminho, "in/%d/%s.txt", casoTeste, cuidador->nome);
    cuidador->leituras = fopen(caminho, "r");

    cuidador->leituraAtual = -1;

    return cuidador;
}

char *nomeCuidador(Cuidador *cuidador) {
    return cuidador->nome;
}

FILE *leiturasCuidador(Cuidador *cuidador) {
    return cuidador->leituras;
}

void posicaoCuidador(Cuidador *cuidador, int indice, int *latitude, int *longitude) {
    char linha[100];

    // Como nem todo cuidador é lido em toda "rodada", é preciso descartar as leituras de posição anteriores
    while (cuidador->leituraAtual < indice) {
        fgets(linha, 100, cuidador->leituras);
        cuidador->leituraAtual++;
    }

    sscanf(linha, "%d;%d", latitude, longitude);
}

void imprimirCuidador(Cuidador *cuidador) {
    printf("Cuidador: %s\n", cuidador->nome);
}

void destruirCuidador(Cuidador *cuidador) {
    printf("Destruindo cuidador: %s\n", cuidador->nome);
    fclose(cuidador->leituras);

    free(cuidador->nome);
    free(cuidador);
}
