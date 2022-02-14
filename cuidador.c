#include "cuidador.h"

struct cuidador {
    char *nome;
    Lista *leituras;
};

Cuidador *
inicializarCuidador(char *nome) {
    Cuidador *cuidador = malloc(sizeof(Cuidador));

    cuidador->nome = strdup(nome);
    cuidador->leituras = inicializarLista();

    return cuidador;
}

void destruirCuidador(Cuidador *cuidador) {
    destruirLista(cuidador->leituras);
    free(cuidador);
}
