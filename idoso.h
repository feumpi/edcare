#ifndef IDOSO_H
#define IDOSO_H

#include <stdlib.h>
#include <string.h>

#include "leitura.h"
#include "lista.h"

typedef struct idoso Idoso;

Idoso *inicializarIdoso();

void destruirIdoso(Idoso *idoso);

#endif