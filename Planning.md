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
- k = ⌊ entrada ⌋


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
- insere 5 elementos
- Procura cada um deles na tabela e verifica se ouve colisão (não deveria ocorrer colisão)

## Teste 3 - Insere com colisão
Testa se consegue Criar a tabela e inserir algum dado nela
- Inicia a tabela vazia com tamanho 7
- Verifica se ela esta vazia
- insere 5 elementos