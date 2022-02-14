#include "idoso.h"

struct idoso {
    char *nome;
    Lista *amigos;
    Lista *cuidadores;
    Lista *leituras;
};

Idoso *
inicializarIdoso(char *nome) {
    Idoso *idoso = malloc(sizeof(Idoso));

    idoso->nome = strdup(nome);
    idoso->amigos = inicializarLista();
    idoso->cuidadores = inicializarLista();
    idoso->leituras = inicializarLista();

    return idoso;
}

void destruirIdoso(Idoso *idoso) {
    destruirLista(idoso->amigos);
    destruirLista(idoso->cuidadores);
    destruirLista(idoso->leituras);
    free(idoso);
}