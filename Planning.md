# Definições

Não vai poder usar 2 tipos de valores ou chaves ao mesmo tempo

## Hash Function
``` h(k) = k mod m```

m: tamanho da tabela

k: chave

## Chave

### strings
- ASCII com pesos, para evitar anagramas
    for(i =0...n) ch = ch + (i*str.len) str[i]

### char
- Conversão em ASCII

### int 
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
- insere um elemento com float na chave e no valor
- insere um elemento com char na chave e no valor
- verifica se os elementos estão na lista e se não houve colisão
- Tenta inserir um valor usando A MESMA chave (retorna um erro)

## Teste 3 - Insere com colisão
Testa se consegue Criar a tabela e inserir algum dado nela, causando colisões
- Inicia a tabela vazia com tamanho 3
- insere 3 elemento com string na chave e no valor
- Verifica a posição de cada um
- Tenta inserir um valor usando A MESMA chave num que ja tem colisão(retorna um erro)



### Teste 4 - Buscar em tabela sem colisão
Testar se consegue retornar um elemento em uma tabela sem colisão
Ele nusca a partir do hash da chave e na lista salva tb a chave
- Cria uma tabela de tamanho 3
- insere 3 elementos com chaves que nao colidem
- verifica se a busca consegue retornar cada elemento

### Teste 5 - Buscar em tabela com colisão
Testar se consegue retornar um elemento em uma tabela com colisão
- Cria a tabela com colisão desrita no fim
- verifica se consegue retornar os elementos em diferentes posições das listas encadeadas

### Teste 6 - Remover sem colisão
Testa se consegue remover dados de uma lista que não possui nenhuma colisão
- Cria uma lista de tamanho 3, com 3 elementos
- Remove um e verifica se aquela posição agora é nula 
- tenta remover de um elemento nulo (deve dar um throw error)

### Teste 7 - Remover com colisão

Testa se consegue remover dados de uma lista que possui colisão
- Cria uma lista de tamanho 4, com 10 elementos
- Remove o primeiro da 4a linha
- Verifica se a linha 4 continua tendo colisão (não deveria ter)
- Verfica se o primeiro da lista de colisões do indice 4 corresponde ao esperado (antigo 2o)

- Remove a ultima colisão da 3a linha
- Verifia se o indice 3 segue tendo colisão
- Verifica o tamanho da colisão agora
- Verifica se os valores da lista de posição está correta

- Remove o 2 segundo item da lista de colisões do indice 1
- Verifica se segue tendo colisão
- Verifica se os valores da lista estão corretos




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
1|joao ->|  rafaelli -> manu -> perna
2|julio ->|  gustavo -> yky
3|carol ->|  vinicius
