TADs implementados:
Lista
Leitura
Idoso
Cuidador
Idoso

- O TAD lista implementa uma lista encadeada genérica `void*`, usando ponteiro de função para impressão.
  https://www.geeksforgeeks.org/generic-linked-list-in-c-2/

- O TAD Leitura guarda uma posição (float latitude, float longitude), e se idoso também float temperatura, int queda (booleano)

- O TAD idoso guarda `char* nome`, `Lista<Idoso> amigos`, `Lista<Cuidador> cuidadores` e `Lista<Leitura> leituras` (temperatura, posição e queda)

- O TAD cuidador guarda `char* nome` e `Lista<Leitura> leituras` (apenas posição)

Após ler carregar todos os dados\*\* (a implementação pede uma leitura por vez) de idosos e cuidadores, incluindo leituras de cada, o programa passará por cada idoso e, em cada leitura, identificar a necessidade de acionar um amigo ou cuidador (o que estiver mais proximo, dentro da categoria) de acordo com as regras do enunciado; registrar o que ocorreu no arquivo de saida

MUDANÇAS:: desfazer o TAD Idoso e Cuidador(?), pois não é necessário carregar para os structs todas as informações da entrada, e sim ler uma linha de cada arquivo por vez, usando as informações e imprimindo uma nova linha abaixo no arquivo de saida
