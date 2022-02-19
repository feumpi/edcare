#include "idoso.h"

struct idoso {
    char *nome;
    Lista *amigos;
    Lista *cuidadores;
    Lista *historico;
    FILE *leituras;
    FILE *saida;
    int quantidadeAmigos;
    int quantidadeCuidadores;
    int febreBaixa;
    int faleceu;
    int latitude;
    int longitude;
    int leituraAtual;
};

Idoso *
inicializarIdoso(char *nome, int casoTeste) {
    Idoso *idoso = malloc(sizeof(Idoso));

    idoso->nome = strdup(nome);
    idoso->amigos = inicializarLista(LISTA_IDOSOS);
    idoso->cuidadores = inicializarLista(LISTA_CUIDADORES);
    idoso->historico = inicializarLista(LISTA_LEITURAS);

    char caminhoEntrada[50], caminhoSaida[50];
    sprintf(caminhoEntrada, "in/%d/%s.txt", casoTeste, idoso->nome);
    sprintf(caminhoSaida, "out/%d/%s-saida.txt", casoTeste, idoso->nome);

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
    idoso->leituraAtual = -1;

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

        // Ignorar amigo que já faleceu
        if (idosoFaleceu(amigo))
            continue;

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
    int distancia, menorDistancia, indiceMenor = 0;

    for (int i = 0; i < idoso->quantidadeCuidadores; i++) {
        Cuidador *cuidador = listaN(idoso->cuidadores, i);
        int latCuidador, longCuidador;

        posicaoCuidador(cuidador, idoso->leituraAtual, &latCuidador, &longCuidador);
        int distY = latitude - latCuidador;
        int distX = longitude - longCuidador;

        distancia = sqrt(pow(distX, 2) + pow(distY, 2));

        if (i == 0 || distancia < menorDistancia) {
            menorDistancia = distancia;
            indiceMenor = i;
        }
    }

    return listaN(idoso->cuidadores, indiceMenor);
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

    idoso->leituraAtual++;

    Leitura *leitura = inicializarLeitura(falecimento, queda, latitude, longitude, temperatura);

    inserirFim(idoso->historico, leitura);

    return leitura;
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
    printf("Destruindo idoso: %s\n", idoso->nome);
    // Destrói a lista de amigos e cuidadores, sem destruir os elementos
    destruirLista(idoso->amigos, 0);
    destruirLista(idoso->cuidadores, 0);

    // Destrói a lista de leituras, e os elementos
    destruirLista(idoso->historico, 1);

    free(idoso->nome);

    // Fecha os arquivos
    fclose(idoso->leituras);
    fclose(idoso->saida);
    free(idoso);
}