TADs implementados:
Lista
Leitura
Idoso
Cuidador
Idoso

- O TAD lista implementa uma lista encadeada genérica `void*`, usando ponteiro de função para impressão.
  https://www.geeksforgeeks.org/generic-linked-list-in-c-2/

- O TAD Leitura guarda uma posição (float latitude, float longitude), e se idoso também float temperatura, int queda (booleano)

- O TAD idoso guarda um nome, lista de amigos, lista de cuidadores e lista de leituras, recuperáveis por `nomeIdoso()`, `meusAmigos()`, `meusCuidadores()` e `leiturasIdoso()`, respectivamente

- O TAD cuidador guarda nome e leituras, recuperáveis por `nomeCuidador()` e `leiturasCuidador()`, respectivamente

- O TAD EDCare guarda uma lista com todos os idosos, recuperavel por `listaIdosos()`, e uma lista de todos os cuidadores, recuperavel por `listaCuidadores()`.

Após ler carregar todos os dados\*\* (a implementação pede uma leitura por vez) de idosos e cuidadores, incluindo leituras de cada, o programa passará por cada idoso e, em cada leitura, identificar a necessidade de acionar um amigo ou cuidador (o que estiver mais proximo, dentro da categoria) de acordo com as regras do enunciado; registrar o que ocorreu no arquivo de saida

MUDANÇAS:: desfazer o TAD Idoso e Cuidador(?), pois não é necessário carregar para os structs todas as informações da entrada, e sim ler uma linha de cada arquivo por vez, usando as informações e imprimindo uma nova linha abaixo no arquivo de saida

---

O programa implementa um TAD `Lista`, que é uma lista encadeada genérica (usando `void*`), servindo tanto para idosos como para cuidadores, com tipo definido na inicialização.

No TAD `Idoso`, inicializamos e guardamos um `char *nome`, bem como uma `Lista *amigos` (outros idosos da rede de apoio pessoal) e uma `Lista *cuidadores` (cuidadores responsáveis pelo idoso). Em `FILE *leituras`, temos o endereço do arquivo com o próprio nome, contendo as leituras do sensor do idoso, e em `FILE *saida` o arquivo onde as saídas sobre o idoso devem ser impressas.

No TAD `Cuidador`, inicializamos e guardamos um `char* nome`, um `FILE* leituras` apontando para o arquivo das próprias leituras, da mesma forma.

dificuldades encontradas:

- para evitar duplicar bastante código implementando listas diferentes para cada TAD, busquei como implementar uma lista "genérica", que não é exatamente heterogênea - pois é esperado que os elementos sejam sempre iguais - mas se trata de um único tad Lista que pode ser inicializado como uma lista de idosos, de cuidadores ou de leituras, com uma propriedade `Lista::tipo` e não `Celula::tipo` para identificá-la, e usando o ponteiro `void *`.

- usando tipos opacos, com a definição dos structs acontecendo no arquivo .c, foi necessário definir funções "getters" e "setters" que me lembraram bastante o modelo de orientação a objeto em C++, especialmente ao implementar os tads `Idoso`, `Cuidador` e `Leitura` com acesso frequente de informações

- como nem todos os cuidadores acionados são lidos em cada leitura dos batches, ler a próxima linha para encontrar a posição era inconsistente, então foi preciso pensar numa forma de descartar as linhas referentes a leituras anteriores;

- de forma parecida, a posição de um cuidador pode ser requisitada por mais de um idoso a cada leitura, e nesse caso não é desejável ler a próxima linha, e sim obter a posição atual. pra isso, a posição, uma vez lida, é guardada em `Cuidador::longitude` e `Cuidador::latitude`, e `Cuidador::leituraAtual` identifica se ela está atualizada.

- foi preciso tratar o caso de, na leitura de um idoso A, que precisa acionar um amigo B, ainda não ter disponivel a posição atualizada de B, por não ter sido lido ainda. para corrigir isso, é mantida uma lista de leituras em `Idoso::historico`. Ao solicitar a posição por `Idoso::posicaoIdoso`, é verificado se `Idoso::leituraAtual` está desatualizada, forçando uma nova leitura para atualizar a posição. Na hora de ler o próprio idoso, é verificado se a leitura ainda precisa ser feita, e adicionada ao início do histórico. A leitura 0 do histórico é então retornada.

### diferenças nos casos de teste documentadas

- quando dois cuidadores tiverem a mesma posição, o considerado "mais próximo" será o primeiro da lista, por exemplo c1 e não o c3, diferente do que ocorre em algumas leituras do caso de teste 2:
  - linhas 7, 10, 12 e 15 (c1 / c3)
  - linhas 2 e 12 (c7 / c9)
