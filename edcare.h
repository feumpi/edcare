#ifndef EDCARE_H
#define EDCARE_H

#include <stdlib.h>

#include "cuidador.h"
#include "idoso.h"
#include "lista.h"

typedef struct edcare EDCare;

// Inicializa uma instância do EDCare e cria as listas necessárias
EDCare* inicializarEDCare(int caso);

// Carrega o arquivo, inicializa todos os idosos e os adiciona nas listas
void carregarIdosos(EDCare* edcare);

// Carrega o arquivo, inicializa todos os cuidadores e os adiciona nas listas
void carregarCuidadores(EDCare* edcare);

// Retorna a lista de todos os idosos do sistema
Lista* listaIdosos(EDCare* edcare);

// Retorna a lista de todos os cuidadores do sistema
Lista* listaCuidadores(EDCare* edcare);

// Realiza as leituras dos sensores em sequência
void realizarLeituras(EDCare* edcare);

// Libera a memória alocada para o EDCare e destrói as próprias listas
void destruirEDCare(EDCare* edcare);

#endif