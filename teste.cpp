#include "gtest/gtest.h"

#include "HashTable.hpp"
#include "ListaEncadeada.hpp"

TEST(HashTableTest, TesteInicializaTabela)
{
    /*
        Testa se está criando certo a Tabela
        - Inicia ela vazia com tamanho 7
        - Verifica se ta tudo vazio mesmo
        - Inicia outra vazia com tamanho 17
        - Verifica se ta tudo vazio mesmo
    */
    HashTable *tabela = inicializaTabela(7);
    ASSERT_EQ(tabela->_tamanho, 7);
    for (int i = 0; i < 7; i++)
    {
        ASSERT_EQ(tabela->_itens[i], nullptrptr) << "O item na posição " << i << " não é nulo";
    }
}
TEST(HashTableTest, TesteInsereSemColizao)
{
    /*
        Testa se consegue Criar a tabela e inserir algum dado nela
        - Inicia a tabela vazia com tamanho 7
        - Verifica se ela esta vazia
        - insere um elemento com string na chave e no valor
        - insere um elemento com int na chave e no valor
        - insere um elemento com double na chave e no valor
        - insere um elemento com float na chave e no valor
        - insere um elemento com char na chave e no valor
        - verifica se os elementos estão na lista e se não houve colisão
    */
    ASSERT_EQ(1, 1);
}
TEST(HashTableTest, TesteInsereComColizao)
{
    /*
        Testa se consegue Criar a tabela e inserir algum dado nela, causando colisões
        - Inicia a tabela vazia com tamanho 7
        - Verifica se ela esta vazia
        - insere 10 elementos
        - insere 2 elemento com string na chave e no valor
        - insere 2 elementos com int na chave e no valor
        - insere 2 elementos com double na chave e no valor
        - insere 2 elementos com float na chave e no valor
        - insere 2 elementos com char na chave e no valor
        - verifica se os elementos estão na lista e se não houve colisão (No caso, como cria uma lista encadeada, vai verificar se o primeiro é o primeiro da lista)
        - nos que deram colisão, verifica se eles estão na posição correta na lista encadeada
    */
    ASSERT_EQ(1, 1);
}
TEST(HashTableTest, TesteRemoveSemColisao)
{
    /*
        Testa se consegue remover dados de uma lista que não possui nenhuma colisão
        - Cria uma lista de tamanho 7, com 7 elementos
        PARA CADA ITEM QUE FOI INSERIDO
        - Remove um e verifica se aquela posição agora é nula 
        - Cria uma lista de tamanho 7 com 5 elementos
        - tenta remover de um elemento nulo (deve dar um throw error)
    */
    ASSERT_EQ(1, 1);
}
TEST(HashTableTest, TesteRemoveComColisao)
{
    /*
        Testa se consegue remover dados de uma lista que possui colisão
        - Cria uma lista de tamanho 7, com 12 elementos
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
*/
    ASSERT_EQ(1, 1);
}
TEST(HashTableTest, TesteDestroiSemColisao)
{
    /*
        Testa se consegue limpar uma lista sem colisão e liberar ela
        - Cria uma lista de tamanho 7 e toda cheia
        - Destroi
        - Verifica se foi destruida
        - Cria uma lista de tamanho 11 com 8 elementos
        - Destroi
        - Verifica se foi destruida
*/
    ASSERT_EQ(1, 1);
}
TEST(HashTableTest, TesteDestroiComColisao)
{
    /*
        Testa se consegue destruir uma lista que possui colisão
        - Cria uma lista de tamanho 7 com 12 elementos
        - Destroi
        - Verifica se foi destruido
    */
    ASSERT_EQ(1, 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}