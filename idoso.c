#include "idoso.h"

struct idoso {
    char *nome;
    Lista *amigos;
    Lista *cuidadores;
    FILE *leituras;
    FILE *saida;
    int quantidadeAmigos;
    int quantidadeCuidadores;
    int febreBaixa;
    int faleceu;
};

Idoso *
inicializarIdoso(char *nome) {
    Idoso *idoso = malloc(sizeof(Idoso));

    idoso->nome = strdup(nome);
    idoso->amigos = inicializarLista(LISTA_IDOSOS);
    idoso->cuidadores = inicializarLista(LISTA_CUIDADORES);

    char caminhoEntrada[50], caminhoSaida[50];
    sprintf(caminhoEntrada, "in/%s.txt", idoso->nome);
    sprintf(caminhoSaida, "out/%s-saida.txt", idoso->nome);

    FILE *arqEntrada = fopen(caminhoEntrada, "r");

    FILE *arqSaida = fopen(caminhoSaida, "w");

    idoso->leituras = arqEntrada;
    idoso->saida = arqSaida;

    idoso->quantidadeAmigos = 0;
    idoso->quantidadeCuidadores = 0;
    idoso->febreBaixa = 0;
    idoso->faleceu = 0;

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

FILE *saidaIdoso(Idoso *idoso) {
    return idoso->saida;
}

int febreBaixa(Idoso *idoso) {
    return idoso->febreBaixa;
}

void incrementarFebreBaixa(Idoso *idoso) {
    idoso->febreBaixa++;
}

void resetarFebreBaixa(Idoso *idoso) {
    idoso->febreBaixa = 0;
}

int idosoFaleceu(Idoso *idoso) {
    return idoso->faleceu;
}

void registrarFalecimento(Idoso *idoso) {
    idoso->faleceu = 1;
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