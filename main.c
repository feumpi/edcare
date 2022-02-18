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

//   TODO: Implementar a parte de encontrar o cuidador mais próximp
//  TODO: usar leituraCuidador() para obter latitude e longitude dele
//   TODO: considerar falecimento ao procurar amigo mais próximo
//   TODO: fechar os vazamentos de memória usando destrutores e free()
//   TODO: documentar o trabalho corretamente, criar diagramas
//   TODO: fazer um makefile

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
