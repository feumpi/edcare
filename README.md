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
