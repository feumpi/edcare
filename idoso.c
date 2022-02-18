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
    int latitude;
    int longitude;
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
    idoso->latitude = 0;
    idoso->longitude = 0;

    return idoso;
}

char *nomeIdoso(Idoso *idoso) {
    return idoso->nome;
}

Lista *meusAmigos(Idoso *idoso) {
    return idoso->amigos;
}

void incrementarAmigos(Idoso *idoso) {
    idoso->quantidadeAmigos++;
}

Idoso *amigoMaisProximo(Idoso *idoso, int latitude, int longitude) {
    int distancia, menorDistancia, indiceMenor = 0;

    for (int i = 0; i < idoso->quantidadeAmigos; i++) {
        Idoso *amigo = listaN(idoso->amigos, i);

        int distY = latitude - minhaLatitude(amigo);
        int distX = longitude - minhaLongitude(amigo);

        distancia = sqrt(pow(distX, 2) + pow(distY, 2));

        if (i == 0 || distancia < menorDistancia) {
            menorDistancia = distancia;
            indiceMenor = i;
        }
    }

    return listaN(idoso->amigos, indiceMenor);
}

Lista *meusCuidadores(Idoso *idoso) {
    return idoso->cuidadores;
}

Cuidador *cuidadorMaisProximo(Idoso *idoso, int latitude, int longitude) {
    // iterar cuidadores, usar leituraCuidador() para achar lat:long de cada um
}

void incrementarCuidadores(Idoso *idoso) {
    idoso->quantidadeCuidadores++;
}

Leitura *leituraIdoso(Idoso *idoso) {
    char linha[100];
    int falecimento = 0, queda, latitude, longitude;
    float temperatura;

    fgets(linha, 100, idoso->leituras);

    if (sscanf(linha, "%f;%d;%d;%d", &temperatura, &latitude, &longitude, &queda) != 4) {
        falecimento = 1;
        idoso->faleceu = 1;
    }

    // salva a posição para uso dos amigos
    idoso->latitude = latitude;
    idoso->longitude = longitude;

    return inicializarLeitura(falecimento, queda, latitude, longitude, temperatura);
}

int minhaLatitude(Idoso *idoso) {
    return idoso->latitude;
}

int minhaLongitude(Idoso *idoso) {
    return idoso->longitude;
}

void imprimirSaida(Idoso *idoso, char *saida) {
    fprintf(idoso->saida, "%s\n", saida);
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