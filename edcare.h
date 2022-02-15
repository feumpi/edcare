#ifndef EDCARE_H
#define EDCARE_H

#include <stdlib.h>

#include "lista.h"

typedef struct edcare EDCare;

// Inicializa uma instância do EDCare e cria as listas necessárias
EDCare* inicializarEDCare();

// Retorna a lista de todos os idosos do sistema
Lista* listaIdosos(EDCare* edcare);

// Retorna a lista de todos os cuidadores do sistema
Lista* listaCuidadores(EDCare* edcare);

// Libera a memória alocada para o EDCare e destrói as próprias listas
void destruirEDCare(EDCare* edcare);

#endif