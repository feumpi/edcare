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

// FIXME: corrigir erros do valgrind
//     TODO: fechar os vazamentos de memória usando destrutores e free()
//     TODO: documentar o trabalho corretamente, criar diagramas
//     TODO: fazer um makefile

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Informe o número do caso de teste a ser usado.\nEx: %s 1\n", argv[0]);
        exit(-1);
    }

    int casoTeste = atoi(argv[1]);

    EDCare* edcare = inicializarEDCare(casoTeste);

    carregarIdosos(edcare);
    carregarCuidadores(edcare);

    imprimirLista(listaIdosos(edcare));
    imprimirLista(listaCuidadores(edcare));

    /* Idoso *idoso = encontrarNome(listaIdosos(edcare), "Luis");

    if (idoso) {
        printf("Amigos de %s:\n", nomeIdoso(idoso));
        imprimirLista(meusAmigos(idoso));
    }

    if (idoso) {
        printf("Cuidadores de %s:\n", nomeIdoso(idoso));
        imprimirLista(meusCuidadores(idoso));
    } */

    realizarLeituras(edcare);

    destruirEDCare(edcare);

    return 0;
}
