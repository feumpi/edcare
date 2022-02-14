#include "edcare.h"

struct edcare {
    Lista *idosos;
    Lista *cuidadores;
};

EDCare *inicializarEDCare() {
    EDCare *edcare = malloc(sizeof(EDCare));

    edcare->idosos = inicializarLista();
    edcare->cuidadores = inicializarLista();

    return edcare;
}

Lista *listaIdosos(EDCare *edcare) {
    return edcare->idosos;
}

Lista *listaCuidadores(EDCare *edcare) {
    return edcare->cuidadores;
}

void destruirEDCare(EDCare *edcare) {
    destruirLista(edcare->idosos);
    destruirLista(edcare->cuidadores);
    free(edcare);
}