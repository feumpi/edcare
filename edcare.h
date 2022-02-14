#ifndef EDCARE_H
#define EDCARE_H

#include <stdlib.h>

#include "lista.h"

typedef struct edcare EDCare;

EDCare *inicializarEDCare();

void destruirEDCare(EDCare *edcare);

#endif