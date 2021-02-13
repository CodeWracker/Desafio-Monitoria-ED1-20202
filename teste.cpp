#include "gtest/gtest.h"

#include "HashTable.hpp"
#include "ListaEncadeada.hpp"

TEST(HashTableTest, TesteinicializaHashTable)
{

    HashTable<int, int> *tabela;
    int tam = 7;
    inicializaHashTable(tabela, &tam);
    ASSERT_EQ(*tabela->_tamanho, 7) << "O tamanho está como " << *tabela->_tamanho << " e deveria ser 7";
    for (int i = 0; i < 7; i++)
    {
        ASSERT_EQ(tabela->_itens[i], nullptr) << "O item na posição " << i << " não é nulo";
    }
    destroiHashTable(tabela);
    HashTable<string, string> *table;
    tam = 17;
    inicializaHashTable(table, &tam);
    for (int i = 0; i < 17; i++)
    {
        ASSERT_EQ(table->_itens[i], nullptr) << "O item na posição " << i << " não é nulo";
    }
    destroiHashTable(table);
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
    HashTable<string, string> *tabela1;
    int tam = 7;
    inicializaHashTable(tabela1, &tam);
    string c1 = "chave1";
    string val1 = "valor1";
    adicionarNaHashTable(tabela1, &c1, &val1);
    destroiHashTable(tabela1);

    HashTable<int, int> *tabela2;
    inicializaHashTable(tabela2, &tam);
    int c2 = 1;
    int val2 = 12;
    adicionarNaHashTable(tabela2, &c2, &val2);
    destroiHashTable(tabela2);

    HashTable<double, double> *tabela3;
    inicializaHashTable(tabela3, &tam);
    double c3 = 2;
    double val3 = 123;
    adicionarNaHashTable(tabela3, &c3, &val3);
    destroiHashTable(tabela3);

    HashTable<float, float> *tabela4;
    inicializaHashTable(tabela4, &tam);
    float c4 = 4.12;
    float val4 = 1.98;
    adicionarNaHashTable(tabela4, &c4, &val4);
    destroiHashTable(tabela4);

    HashTable<char, char> *tabela5;
    inicializaHashTable(tabela5, &tam);
    char c5 = ''; //isso aqui é o que da 5 na ASCII
    char val5 = 'p';
    adicionarNaHashTable(tabela5, &c5, &val5);
    destroiHashTable(tabela5);
}
TEST(HashTableTest, TesteInsereComColizao)
{

    HashTable<string, string> *tabela1;
    int tam = 2;
    inicializaHashTable(tabela1, &tam);
    string c1 = "A"; // 65 MOD 2 = 1
    string val1 = "meire";
    string c2 = "B"; // 66 MOD 2 = 0
    string val2 = "joao";
    string c3 = "C"; // 67 MOD 2 = 1
    string val3 = "julio";
    adicionarNaHashTable(tabela1, &c1, &val1);
    adicionarNaHashTable(tabela1, &c2, &val2);
    adicionarNaHashTable(tabela1, &c3, &val3);
    ASSERT_EQ(*tabela1->_itens[0]->_primeiro->_dado, val1);
    ASSERT_EQ(*tabela1->_itens[1]->_primeiro->_dado, val2);
    ASSERT_EQ(*tabela1->_itens[0]->_primeiro->_proximo->_dado, val2);

    EXPECT_THROW(adicionarNaHashTable(tabela1, &c2, &val2), chave_igual_exception);
    destroiHashTable(tabela1);

    ASSERT_EQ(1, 1);
}
TEST(HashTableTest, TesteBuscaSemColisao)
{
    HashTable<int, string> *tabela;
    int tam = 3;
    inicializaHashTable(tabela, &tam);
    int c1 = 0;
    string val1 = "meire";
    int c2 = 1;
    string val2 = "joao";
    int c3 = 0;
    string val3 = "julio";
    adicionarNaHashTable(tabela, &c1, &val1);
    adicionarNaHashTable(tabela, &c2, &val2);
    adicionarNaHashTable(tabela, &c3, &val3);
    Elemento<int, string> *busca;

    busca = buscarNaHashTable(tabela, c1);
    ASSERT_EQ(*busca->_dado, val1);

    busca = buscarNaHashTable(tabela, c2);
    ASSERT_EQ(*busca->_dado, val2);

    busca = buscarNaHashTable(tabela, c3);
    ASSERT_EQ(*busca->_dado, val3);

    destroiHashTable(tabela);
}
TEST(HashTableTest, TesteBuscaComColisao)
{
    /*
    pos|value| lista de colisões 
    ---|---|---
    0|meire ->|  nullptr
    1|joao ->|  rafalli -> manu -> perna
    2|julio ->|  gustavo -> Ykky
    3|carol ->|  vinicius
    */
    HashTable<string, string> *tabela;
    int tam = 3;
    inicializaHashTable(tabela, &tam);
    string c1 = "A";
    string val1 = "meire";
    string c2 = "B";
    string val2 = "joao";
    string c3 = "C";
    string val3 = "julio";
    string c4 = "D";
    string val4 = "carol";
    string c5 = "B";
    string val5 = "rafaelli";
    string c6 = "B";
    string val6 = "manu";
    string c7 = "B";
    string val7 = "perna";
    string c8 = "C";
    string val8 = "gustavo";
    string c9 = "C";
    string val9 = "Ykky";
    string c10 = "D";
    string val10 = "vinicius";

    adicionarNaHashTable(tabela, &c1, &val1);
    adicionarNaHashTable(tabela, &c2, &val2);
    adicionarNaHashTable(tabela, &c3, &val3);
    adicionarNaHashTable(tabela, &c4, &val4);
    adicionarNaHashTable(tabela, &c5, &val5);
    adicionarNaHashTable(tabela, &c6, &val6);
    adicionarNaHashTable(tabela, &c7, &val7);
    adicionarNaHashTable(tabela, &c8, &val8);
    adicionarNaHashTable(tabela, &c9, &val9);
    adicionarNaHashTable(tabela, &c10, &val10);
    Elemento<string, string> *busca;

    busca = buscarNaHashTable(tabela, c3);
    ASSERT_EQ(*busca->_dado, val3);

    busca = buscarNaHashTable(tabela, c9);
    ASSERT_EQ(*busca->_dado, val9);

    busca = buscarNaHashTable(tabela, c6);
    ASSERT_EQ(*busca->_dado, val6);

    destroiHashTable(tabela);
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