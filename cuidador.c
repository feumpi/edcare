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
    int lido = 0;

    // Como nem todo cuidador é lido em toda "rodada", é preciso descartar as leituras de posição anteriores
    while (cuidador->leituraAtual < indice) {
        // Se o fgets retorna um ponteiro != NULL e o indice desejado foi atingido, sinaliza que os valores podem ser lidos
        if (fgets(linha, 100, cuidador->leituras) && cuidador->leituraAtual == indice) lido = 1;
        cuidador->leituraAtual++;
    }

    // Lê da string a latitude e longitude se sinalizado anteriormente (corrige erro do valgrind)
    if (lido) sscanf(linha, "%d;%d", latitude, longitude);
}

void imprimirCuidador(Cuidador *cuidador) {
    printf("Cuidador: %s\n", cuidador->nome);
}

void destruirCuidador(Cuidador *cuidador) {
    fclose(cuidador->leituras);

    free(cuidador->nome);
    free(cuidador);
}
