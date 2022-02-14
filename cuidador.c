#include "cuidador.h"

struct cuidador {
    char *nome;
    Lista *leituras;
};

Cuidador *
inicializarCuidador(char *nome) {
    Cuidador *cuidador = malloc(sizeof(Cuidador));

    cuidador->nome = strdup(nome);
    cuidador->leituras = inicializarLista(LISTA_LEITURAS);

    return cuidador;
}

char *nomeCuidador(Cuidador *cuidador) {
    return cuidador->nome;
}

Lista *leiturasCuidador(Cuidador *cuidador) {
    return cuidador->leituras;
}

void imprimirCuidador(Cuidador *cuidador) {
    printf("Cuidador: %s\n", cuidador->nome);
}

void destruirCuidador(Cuidador *cuidador) {
    destruirLista(cuidador->leituras);
    free(cuidador);
}
