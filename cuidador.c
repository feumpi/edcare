/*
### Universidade Federal do Espírito Santo

### INF09292 - Estrutura de Dados I - 2021/2

### Primeiro trabalho

### Aluno: 2020205193 Felipe Pereira Umpierre

### Professora: Patricia Dockhorn Costa
*/

#include "cuidador.h"

struct cuidador {
    char *nome;
    FILE *leituras;
    int leituraAtual;
    int latitude;
    int longitude;
};

Cuidador *
inicializarCuidador(char *nome, int casoTeste) {
    Cuidador *cuidador = malloc(sizeof(Cuidador));

    cuidador->nome = strdup(nome);

    // Carrega o arquivo de leituras do cuidador, no caso de teste especificado
    char caminho[50];
    sprintf(caminho, "in/%d/%s.txt", casoTeste, cuidador->nome);
    cuidador->leituras = fopen(caminho, "r");

    cuidador->leituraAtual = -1;
    cuidador->latitude = -1;
    cuidador->longitude = -1;

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

    // Se a posição atual estiver desatualizada
    if (cuidador->leituraAtual < indice) {
        // Como nem todo cuidador é lido em toda "rodada", é preciso descartar as leituras de índices anteriores
        while (cuidador->leituraAtual < indice) {
            // Se o fgets retorna um ponteiro != NULL e o indice desejado foi atingido, sinaliza que os valores podem ser lidos
            fgets(linha, 100, cuidador->leituras);
            cuidador->leituraAtual++;
        }

        // Atualiza a latitude e longitude internamente
        sscanf(linha, "%d;%d", &cuidador->latitude, &cuidador->longitude);
    }

    // Guarda a posição nos ponteiros informados
    *latitude = cuidador->latitude;
    *longitude = cuidador->longitude;
}

void imprimirCuidador(Cuidador *cuidador) {
    printf("%s ", cuidador->nome);
}

void destruirCuidador(Cuidador *cuidador) {
    fclose(cuidador->leituras);

    free(cuidador->nome);
    free(cuidador);
}
