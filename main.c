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

// FIXME: implementação do proximaLeitura(): recuperar o primeiro Idoso* da lista, está vindo como 0x0 (NULL) - função listaN()

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

    proximaLeitura(edcare);

    return 0;
}
