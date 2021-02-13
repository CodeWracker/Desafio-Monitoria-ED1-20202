# Definições

Não vai poder usar 2 tipos de valores ou chaves ao mesmo tempo

## Hash Function
``` h(k) = k mod m```

m: tamanho da tabela

k: chave

## Chave

### strings
- ASCII com pesos, para evitar anagramas

### char
- Conversão em ASCII

### int e double
- só colocar na função

# float
- ``` k = ⌊ entrada ⌋ ```

-------------------------------------------------------------------------------------------

# Testes

## Teste 1 - Inicialização
Testa se está criando certo a Tabela
- Inicia ela vazia com tamanho 7
- Verifica se ta tudo vazio mesmo
- Inicia outra vazia com tamanho 17
- Verifica se ta tudo vazio mesmo

## Teste 2 - Insersão sem colisão
Testa se consegue Criar a tabela e inserir algum dado nela
- Inicia a tabela vazia com tamanho 7
- Verifica se ela esta vazia
- insere um elemento com string na chave e no valor
- insere um elemento com int na chave e no valor
- insere um elemento com double na chave e no valor
- insere um elemento com float na chave e no valor
- insere um elemento com char na chave e no valor
- verifica se os elementos estão na lista e se não houve colisão
- Tenta inserir um valor usando A MESMA chave (retorna um erro)

## Teste 3 - Insere com colisão
Testa se consegue Criar a tabela e inserir algum dado nela, causando colisões
- Inicia a tabela vazia com tamanho 3
- insere 3 elemento com string na chave e no valor
- Inicia a tabela vazia com tamanho 3
- insere 3 elementos com int na chave e no valor
- Inicia a tabela vazia com tamanho 3
- insere 3 elementos com double na chave e no valor
- Inicia a tabela vazia com tamanho 3
- insere 3 elementos com float na chave e no valor
- Inicia a tabela vazia com tamanho 3
- insere 3 elementos com char na chave e no valor
- Tenta inserir um valor usando A MESMA chave num que ja tem colisão(retorna um erro)
- verifica se os elementos estão na lista e se não houve colisão (No caso, como cria uma lista encadeada, vai verificar se o primeiro é o primeiro da lista)
- nos que deram colisão, verifica se eles estão na posição correta na lista encadeada


### Teste 4 - Remover sem colisão
Testa se consegue remover dados de uma lista que não possui nenhuma colisão
- Cria uma lista de tamanho 7, com 7 elementos
PARA CADA ITEM QUE FOI INSERIDO
- Remove um e verifica se aquela posição agora é nula 
- Cria uma lista de tamanho 7 com 5 elementos
- tenta remover de um elemento nulo (deve dar um throw error)

### Teste 5 - Buscar em tabela sem colisão
Testar se consegue retornar um elemento em uma tabela sem colisão
Ele nusca a partir do hash da chave e na lista salva tb a chave

### Teste 6 - Buscar em tabela com colisão
Testar se consegue retornar um elemento em uma tabela com colisão

### Teste 7 - Remover com colisõa

Testa se consegue remover dados de uma lista que possui colisão
- Cria uma lista de tamanho 7, com 13 elementos
- Remove o primeiro do indice 5
- Verifica se o indice 5 continua tendo colisão (não deveria ter)
- Verfica se o primeiro da lista de colisões do indice 1 corresponde ao esperado (antigo 2o)
- Remove a ultima colisão do indice 3
- Verifia se o indice 3 segue tendo colisão
- Verifica o tamanho da colisão agora
- Verifica se os valores da lista de posição está correta
- Remove o 2 segundo item da lista de colisões do indice 1
- Verifica se segue tendo colisão
- Verifica o tamanho da lista
- Verifica se os valores da lista estão corretos

### Teste 8 - Destruir sem colisão
Testa se consegue limpar uma lista sem colisão e liberar ela
- Cria uma lista de tamanho 7 e toda cheia
- Destroi
- Verifica se foi destruida
- Cria uma lista de tamanho 11 com 8 elementos
- Destroi
- Verifica se foi destruida

### Teste 9 - Destruir com colisão
Testa se consegue destruir uma lista que possui colisão
- Cria uma lista de tamanho 7 com 12 elementos
- Destroi
- Verifica se foi destruido


## Tabelas usadas nos testes


### Tabela sem colisão

pos|value| lista de colisões 
---|---|---
0|meire ->| nullptr
1|joao| nullptr
2|julio ->|nullptr
3|carol ->| nullptr

### Tabela com colisão

pos|value| lista de colisões 
---|---|---
0|meire ->|  nullptr
1|joao ->|  rafalli -> manu -> perna
2|julio ->|  gustavo -> Ykky
3|carol ->|  vinicius
