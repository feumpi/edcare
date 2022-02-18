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

// FIXME: na leitura 5 de joao, cuidador4 é acionado em vez do cuidador1
// FIXME: na leitura 2 de Maria, cuidador1 é acionado em vez do cuidador3
//  TODO: Salvar o histórico de leituras do idoso numa lista
//    TODO: fechar os vazamentos de memória usando destrutores e free()
//    TODO: documentar o trabalho corretamente, criar diagramas
//    TODO: fazer um makefile

int main() {
    printf("EDCare\n\n");

    EDCare *edcare = inicializarEDCare();

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

    return 0;
}
