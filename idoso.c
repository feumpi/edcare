#include "idoso.h"

struct idoso {
    char *nome;
    Lista *amigos;
    Lista *cuidadores;
    FILE *leituras;
    FILE *saida;
};

Idoso *
inicializarIdoso(char *nome) {
    Idoso *idoso = malloc(sizeof(Idoso));

    idoso->nome = strdup(nome);
    idoso->amigos = inicializarLista(LISTA_IDOSOS);
    idoso->cuidadores = inicializarLista(LISTA_CUIDADORES);

    char caminhoEntrada[50], caminhoSaida[50];
    sprintf(caminhoEntrada, "in/%s-saida.txt", idoso->nome);
    sprintf(caminhoSaida, "out/%s-saida.txt", idoso->nome);

    idoso->leituras = fopen(caminhoEntrada, "r");
    idoso->saida = fopen(caminhoSaida, "w");

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

FILE *leiturasIdoso(Idoso *idoso) {
    return idoso->leituras;
}

void imprimirIdoso(Idoso *idoso) {
    printf("Idoso: %s\n", idoso->nome);
}

void destruirIdoso(Idoso *idoso) {
    destruirLista(idoso->amigos);
    destruirLista(idoso->cuidadores);
    fclose(idoso->leituras);
    free(idoso);
}