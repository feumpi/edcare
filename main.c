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

// FIXME: verificar casos de teste 2 escolhendo amigo/cuidador incorreto (mas considerar falecimento) - rever cálculo da distancia em amigoMaisProximo() e cuidadorMaisProximo()
// TODO: fechar os vazamentos de memória usando destrutores e free()
// TODO: documentar o trabalho corretamente, criar diagramas
// TODO: fazer um makefile

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Informe o número do caso de teste a ser usado.\nEx: %s 1\n", argv[0]);
        exit(-1);
    }

    int casoTeste = atoi(argv[1]);

    EDCare* edcare = inicializarEDCare(casoTeste);

    carregarIdosos(edcare);
    carregarCuidadores(edcare);

    realizarLeituras(edcare);

    destruirEDCare(edcare);

    return 0;
}
