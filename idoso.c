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

char *nomeIdoso(Idoso *idoso) {
    return idoso->nome;
}

Lista *meusAmigos(Idoso *idoso) {
    return idoso->amigos;
}

Lista *meusCuidadores(Idoso *idoso) {
    return idoso->cuidadores;
}

Lista *leiturasIdoso(Idoso *idoso) {
    return idoso->leituras;
}

void destruirIdoso(Idoso *idoso) {
    destruirLista(idoso->amigos);
    destruirLista(idoso->cuidadores);
    destruirLista(idoso->leituras);
    free(idoso);
}