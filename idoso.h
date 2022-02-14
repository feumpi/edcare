#ifndef IDOSO_H
#define IDOSO_H

#include <stdlib.h>
#include <string.h>

#include "leitura.h"
#include "lista.h"

typedef struct idoso Idoso;

Idoso* inicializarIdoso(char* nome);

char* nomeIdoso(Idoso* idoso);

Lista* meusAmigos(Idoso* idoso);

Lista* meusCuidadores(Idoso* idoso);

Lista* leiturasIdoso(Idoso* idoso);

void imprimirIdoso(Idoso* idoso);

void destruirIdoso(Idoso* idoso);

#endif