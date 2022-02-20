/*
### Universidade Federal do Espírito Santo

### INF09292 - Estrutura de Dados I - 2021/2

### Primeiro trabalho

### Aluno: 2020205193 Felipe Pereira Umpierre

### Professora: Patricia Dockhorn Costa

Documentação e instruções de uso em DOCUMENTACAO.md ou DOCUMENTACAO.pdf
Posicione arquivos de entrada em /in/<N>, sendo <N> o número do caso de teste.
Ex: /in/1
    /in/2

Os arquivos de saída serão gerados em /out/<N>/, sendo <N> o número  do caso de teste
Atenção: A pasta <N> precisa existir, pois o programa não cria diretórios

Para compilar, use o comando "make"
Execute o arquivo ./main informado o número do caso de teste desejável, de acordo com a pasta de entradas.
Ex: ./main 1
    ./main 2
*/

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

int main(int argc, char* argv[]) {
    // Encerra se o número do caso de teste não for informado na execução
    if (argc <= 1) {
        printf("Informe o número do caso de teste a ser usado.\nEx: %s 1\n", argv[0]);
        exit(-1);
    }

    // Obtém o valor do caso de teste e inicializa o EDCare
    int casoTeste = atoi(argv[1]);
    printf("Executando caso de teste %d\n", casoTeste);
    EDCare* edcare = inicializarEDCare(casoTeste);

    // Carrega os idosos e cuidadores para o EDCare
    carregarIdosos(edcare);
    carregarCuidadores(edcare);

    // Realiza as leituras sequenciais
    realizarLeituras(edcare);

    // Destrói o EDCare
    destruirEDCare(edcare);

    return 0;
}
