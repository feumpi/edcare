#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cuidador.h"
#include "edcare.h"
#include "idoso.h"
#include "leitura.h"
#include "lista.h"

#define IDOSOS 0
#define CUIDADORES 1

// TODO: mudar a inserção nas listas para o começo, de modo a igualar os casos teste
//   TODO: documentar o trabalho corretamente, criar diagramas
//   TODO: fazer um makefile

int main(int argc, char* argv[]) {
    // Encerra se o número do caso de teste não for informado na execução
    if (argc <= 1) {
        printf("Informe o número do caso de teste a ser usado.\nEx: %s 1\n", argv[0]);
        exit(-1);
    }

    // Obtém o valor do caso de teste e inicializa o EDCare
    int casoTeste = atoi(argv[1]);
    printf("Executando caso de teste %d\n", casoTeste);
    EDCare* edcare = inicializarEDCare(casoTeste);

    // Carrega os idosos e cuidadores para o EDCare
    carregarIdosos(edcare);
    carregarCuidadores(edcare);

    // Realiza as leituras sequenciais
    realizarLeituras(edcare);

    // Destrói o EDCare
    destruirEDCare(edcare);

    return 0;
}
