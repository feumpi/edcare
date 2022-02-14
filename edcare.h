#ifndef EDCARE_H
#define EDCARE_H

#include <stdlib.h>

#include "lista.h"

typedef struct edcare EDCare;

EDCare* inicializarEDCare();

Lista* listaIdosos(EDCare* edcare);

Lista* listaCuidadores(EDCare* edcare);

void destruirEDCare(EDCare* edcare);

#endif