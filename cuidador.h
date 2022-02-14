#ifndef CUIDADOR_H
#define CUIDADOR_H

#include <stdlib.h>
#include <string.h>

#include "leitura.h"
#include "lista.h"

typedef struct cuidador Cuidador;

Cuidador* inicializarCuidador();

char* nomeCuidador(Cuidador* cuidador);

Lista* leiturasCuidador(Cuidador* cuidador);

void destruirCuidador(Cuidador* cuidador);

#endif