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

// FIXME: saidas de Alice continuam mesmo apos interrupção de leituras (falecimento)
// FIXME: alguns idosos tem apenas 4 saidas em vez de 5, apesar de não haver falecimento (parece corrigido)
// FIXME: verificar acontecimentos com tratamento errado (ex. registro queda em vez de febre alta)
// TODO: Implementar a parte de encontrar o cuidador/amigo mais próximp
// TODO: tratar o falecimento removendo o idoso das listas (ou adicionar uma flag falecimento = 1, ajuda a interromper as leiturs do idoso!!)
// TODO: fechar os vazamentos de memória usando destrutores e free()
// TODO: documentar o trabalho corretamente, criar diagramas
// TODO: fazer um makefile

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
