#include "cuidador.h"

struct cuidador {
    char *nome;
    FILE *leituras;
};

Cuidador *
inicializarCuidador(char *nome) {
    Cuidador *cuidador = malloc(sizeof(Cuidador));

    cuidador->nome = strdup(nome);

    char caminho[50];
    sprintf(caminho, "in/%s.txt", cuidador->nome);
    cuidador->leituras = fopen(caminho, "r");

    return cuidador;
}

char *nomeCuidador(Cuidador *cuidador) {
    return cuidador->nome;
}

FILE *leiturasCuidador(Cuidador *cuidador) {
    return cuidador->leituras;
}

void imprimirCuidador(Cuidador *cuidador) {
    printf("Cuidador: %s\n", cuidador->nome);
}

void destruirCuidador(Cuidador *cuidador) {
    fclose(cuidador->leituras);
    free(cuidador);
}
