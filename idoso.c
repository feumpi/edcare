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

float calcularDistancia(int lat1, int long1, int lat2, int long2) {
    int distY = abs(lat1 - lat2);
    int distX = abs(long1 - long2);
    // A raiz da soma dos quadrados das distâncias X e Y
    return sqrt(pow(distX, 2) + pow(distY, 2));
}

Idoso *amigoMaisProximo(Idoso *idoso, int latitude, int longitude) {
    // Valores precisam ser inicializados para evitar um erro no valgrind
    double distancia = 999, menorDistancia = 999;
    int indiceMenor = -1;

    for (int i = 0; i < idoso->quantidadeAmigos; i++) {
        Idoso *amigo = listaN(idoso->amigos, i);

        // Ignorar amigo que já faleceu
        if (idosoFaleceu(amigo))
            continue;

        distancia = calcularDistancia(latitude, longitude, minhaLatitude(amigo), minhaLongitude(amigo));

        // Se um indiceMenor ainda não foi encontrado, ou a distancia atual for menor
        if (indiceMenor == -1 || distancia < menorDistancia) {
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
    double distancia = 999, menorDistancia = 999;
    int indiceMenor = -1;

    for (int i = 0; i < idoso->quantidadeCuidadores; i++) {
        Cuidador *cuidador = listaN(idoso->cuidadores, i);

        // Obtém a posição do cuidador; Inicializando valores para corrigir um erro do valgrind
        int latCuidador = 0, longCuidador = 0;
        posicaoCuidador(cuidador, idoso->leituraAtual, &latCuidador, &longCuidador);

        distancia = calcularDistancia(latitude, longitude, latCuidador, longCuidador);

        if (indiceMenor == -1 || distancia < menorDistancia) {
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

    // Lê a próxima linha da leitura do idoso
    fgets(linha, 100, idoso->leituras);
    // Se não for possível ler os 4 dados, houve falecimento
    if (sscanf(linha, "%f;%d;%d;%d", &temperatura, &latitude, &longitude, &queda) != 4) {
        falecimento = 1;
        idoso->faleceu = 1;
    }

    // salva a nova posição para uso dos amigos e incrementa o índice da leitura
    idoso->latitude = latitude;
    idoso->longitude = longitude;
    idoso->leituraAtual++;

    // Cria o objeto Leitura com os dados obtidos, insere no histórico e o retorna
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
    // Destrói a lista de amigos e cuidadores, sem destruir os elementos
    destruirLista(idoso->amigos, 0);
    destruirLista(idoso->cuidadores, 0);

    // Destrói a lista de leituras, e os elementos
    destruirLista(idoso->historico, 1);

    // Libera o char* nome
    free(idoso->nome);

    // Fecha os arquivos
    fclose(idoso->leituras);
    fclose(idoso->saida);
    free(idoso);
}