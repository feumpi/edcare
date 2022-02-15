#include "cuidador.h"

struct cuidador {
    char *nome;
    Lista *leituras;
};

Cuidador *
inicializarCuidador(char *nome) {
    Cuidador *cuidador = malloc(sizeof(Cuidador));

    cuidador->nome = strdup(nome);

    char caminho[50];
    sprintf(caminho, "in/%s.txt", idoso->nome);
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
