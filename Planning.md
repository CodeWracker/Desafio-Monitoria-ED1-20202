# Definições

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
- insere um elemento com string
- insere um elemento com int
- insere um elemento com double
- insere um elemento com float
- insere um elemento com char
- verifica se os elementos estão na lista e se não houve colisão

## Teste 3 - Insere com colisão
Testa se consegue Criar a tabela e inserir algum dado nela, causando colisões
- Inicia a tabela vazia com tamanho 7
- Verifica se ela esta vazia
- insere 10 elementos
- insere 2 elemento com string
- insere 2 elementos com int
- insere 2 elementos com double
- insere 2 elementos com float
- insere 2 elementos com char
- verifica se os elementos estão na lista e se não houve colisão (No caso, como cria uma lista encadeada, vai verificar se o primeiro é o primeiro da lista)
- nos que deram colisão, verifica se eles estão na posição correta na lista encadeada

### Teste 4 - Remover sem colisão
Testa se consegue remover dados de uma lista que não possui nenhuma colisão
- Cria uma lista de tamanho 7, com 7 elementos
PARA CADA ITEM QUE FOI INSERIDO
- Remove um e verifica se aquela posição agora é nula 

### Teste 5 - Remover com colisõa

Testa se consegue remover dados de uma lista que possui colisão
- Cria uma lista de tamanho 7, com 12 elementos


## Tabelas usadas nos testes

### Tabela sem colisão

pos|value| colisões 
---|---|---
0|46 ->| null
1|joao| null
2|96 ->|null
3|9,22 ->| null
4|pedro ->| null
5|rodrigo ->| null
6|fuinha ->| null

### Tabela com colisão

pos|value| colisões 
---|---|---
0|46 ->|  null
1|joao ->|  rafalli -> manu -> perna
2|96 ->|  null
3|9,22 ->|  gustavo -> Ykky
4|pedro ->|  null
5|rodrigo ->|  vinicius
6|fuinha ->|  null
