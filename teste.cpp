#include "gtest/gtest.h"

#include "HashTable.hpp"
#include "ListaEncadeada.hpp"

TEST(HashTableTest, TesteinicializaHashTable)
{

    HashTable<int, int> *tabela = (HashTable<int, int> *)calloc(1, sizeof(HashTable<int, int>));
    int tam = 7;
    inicializaHashTable(tabela, tam);
    int tamanho = tabela->_tamanho;
    ASSERT_EQ(tamanho, 7);
    for (int i = 0; i < 7; i++)
    {
        ASSERT_EQ(tabela->_itens[i]->_primeiro, nullptr) << "O item na posição " << i << " não é nulo";
    }
    destroiHashTable(tabela);
    HashTable<string, string> *table = (HashTable<string, string> *)calloc(1, sizeof(HashTable<string, string>));

    int tam2 = 17;
    inicializaHashTable(table, tam2);
    for (int i = 0; i < 17; i++)
    {
        ASSERT_EQ(table->_itens[i]->_primeiro, nullptr) << "O item na posição " << i << " não é nulo";
    }
    destroiHashTable(table);
}
TEST(HashTableTest, TesteInsereSemColizao)
{

    HashTable<string, string> *tabela1 = (HashTable<string, string> *)calloc(1, sizeof(HashTable<string, string>));

    int tam = 2;
    inicializaHashTable(tabela1, tam);
    string c1 = "B";
    string val1 = "valor1";
    adicionarNaHashTable(tabela1, &c1, &val1);
    ASSERT_EQ(*tabela1->_itens[0]->_primeiro->_dado, val1);
    destroiHashTable(tabela1);

    HashTable<int, int> *tabela2 = (HashTable<int, int> *)calloc(1, sizeof(HashTable<int, int>));
    inicializaHashTable(tabela2, tam);
    int c2 = 1;
    int val2 = 12;
    adicionarNaHashTable(tabela2, &c2, &val2);
    Elemento<int, int> *a = tabela2->_itens[1]->_primeiro;
    ASSERT_EQ(*a->_dado, val2);
    destroiHashTable(tabela2);

    HashTable<float, float> *tabela3 = (HashTable<float, float> *)calloc(1, sizeof(HashTable<float, float>));
    inicializaHashTable(tabela3, tam);
    float c3 = 4.12;
    float val3 = 1.98;
    adicionarNaHashTable(tabela3, &c3, &val3);
    ASSERT_EQ(*tabela3->_itens[0]->_primeiro->_dado, val3);
    destroiHashTable(tabela3);

    HashTable<char, char> *tabela4 = (HashTable<char, char> *)calloc(1, sizeof(HashTable<char, char>));
    inicializaHashTable(tabela4, tam);
    char c4 = ''; //isso aqui é o que da 5 na ASCII
    char val4 = 'p';
    adicionarNaHashTable(tabela4, &c4, &val4);
    ASSERT_EQ(*tabela4->_itens[1]->_primeiro->_dado, val4);
    destroiHashTable(tabela4);
}
TEST(HashTableTest, TesteInsereComColizao)
{

    HashTable<string, string> *tabela1 = (HashTable<string, string> *)calloc(1, sizeof(HashTable<string, string>));
    int tam = 2;
    inicializaHashTable(tabela1, tam);
    string c1 = "A"; // 65 MOD 2 = 1
    string val1 = "meire";
    string c2 = "B"; // 66 MOD 2 = 0
    string val2 = "joao";
    string c3 = "C"; // 67 MOD 2 = 1
    string val3 = "julio";
    adicionarNaHashTable(tabela1, &c1, &val1);
    adicionarNaHashTable(tabela1, &c2, &val2);
    adicionarNaHashTable(tabela1, &c3, &val3);
    ASSERT_EQ(*tabela1->_itens[0]->_primeiro->_dado, val2);

    ASSERT_EQ(*tabela1->_itens[1]->_primeiro->_dado, val1);

    ASSERT_EQ(*tabela1->_itens[1]->_primeiro->_proximo->_dado, val3);

    EXPECT_THROW(adicionarNaHashTable(tabela1, &c2, &val2), chave_igual_exception);
    destroiHashTable(tabela1);
}
TEST(HashTableTest, TesteBuscaSemColisao)
{

    HashTable<int, string> *tabela = (HashTable<int, string> *)calloc(1, sizeof(HashTable<int, string>));
    int tam = 3;
    inicializaHashTable(tabela, tam);
    int c1 = 0;
    string val1 = "meire";
    int c2 = 1;
    string val2 = "joao";
    int c3 = 2;
    string val3 = "julio";
    adicionarNaHashTable(tabela, &c1, &val1);
    adicionarNaHashTable(tabela, &c2, &val2);
    adicionarNaHashTable(tabela, &c3, &val3);
    Elemento<int, string> *busca;

    busca = buscarElementoNaHashTable(tabela, c1);
    ASSERT_EQ(*busca->_dado, val1);

    busca = buscarElementoNaHashTable(tabela, c2);
    ASSERT_EQ(*busca->_dado, val2);

    busca = buscarElementoNaHashTable(tabela, c3);
    ASSERT_EQ(*busca->_dado, val3);

    busca = buscarElementoNaHashTable(tabela, 6);
    ASSERT_EQ(busca, nullptr);

    destroiHashTable(tabela);
}
TEST(HashTableTest, TesteBuscaComColisao)
{
    /*
    pos|value| lista de colisões 
    ---|---|---
    0|meire ->|  nullptr
    1|joao ->|  rafaelli -> manu -> perna
    2|julio ->|  gustavo -> Ykky
    3|carol ->|  vinicius
    */

    HashTable<string, string> *tabela = (HashTable<string, string> *)calloc(1, sizeof(HashTable<string, string>));
    int tam = 4;
    inicializaHashTable(tabela, tam);
    string c1 = "A";
    string val1 = "meire";
    string c2 = "B";
    string val2 = "joao";
    string c3 = "C";
    string val3 = "julio";
    string c4 = "D";
    string val4 = "carol";
    string c5 = "F";
    string val5 = "rafaelli";
    string c6 = "J";
    string val6 = "manu";
    string c7 = "O";
    string val7 = "perna";
    string c8 = "G";
    string val8 = "gustavo";
    string c9 = "K";
    string val9 = "Ykky";
    string c10 = "H";
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

    busca = buscarElementoNaHashTable(tabela, c3);
    ASSERT_EQ(*busca->_dado, val3);

    busca = buscarElementoNaHashTable(tabela, c9);
    ASSERT_EQ(*busca->_dado, val9);

    busca = buscarElementoNaHashTable(tabela, c6);
    ASSERT_EQ(*busca->_dado, val6);

    destroiHashTable(tabela);
}
TEST(HashTableTest, TesteRemoveSemColisao)
{

    HashTable<int, string> *tabela = (HashTable<int, string> *)calloc(1, sizeof(HashTable<int, string>));
    int tam = 3;
    inicializaHashTable(tabela, tam);
    int c1 = 0;
    string val1 = "meire";
    int c2 = 1;
    string val2 = "joao";
    int c3 = 2;
    string val3 = "julio";
    adicionarNaHashTable(tabela, &c1, &val1);
    adicionarNaHashTable(tabela, &c2, &val2);
    adicionarNaHashTable(tabela, &c3, &val3);
    Elemento<int, string> *busca;
    busca = buscarElementoNaHashTable(tabela, c3);
    ASSERT_EQ(*busca->_dado, val3);
    removerDaHashTable(tabela, c3);
    busca = buscarElementoNaHashTable(tabela, c3);
    ASSERT_EQ(busca, nullptr);
    EXPECT_THROW(removerDaHashTable(tabela, 4), posicao_invalida_exception);
    destroiHashTable(tabela);
}
TEST(HashTableTest, TesteRemoveComColisao)
{

    /*
    pos|value| lista de colisões 
    ---|---|---
    0|meire ->|  nullptr
    1|joao ->|  rafaelli -> manu -> perna
    2|julio ->|  gustavo -> Ykky
    3|carol ->|  vinicius
    */

    HashTable<string, string> *tabela = (HashTable<string, string> *)calloc(1, sizeof(HashTable<string, string>));
    int tam = 4;
    inicializaHashTable(tabela, tam);
    string c1 = "D"; //0
    string val1 = "meire";
    string c2 = "A"; //1
    string val2 = "joao";
    string c3 = "B"; //2
    string val3 = "julio";
    string c4 = "C"; //3
    string val4 = "carol";
    string c5 = "E"; //1
    string val5 = "rafaelli";
    string c6 = "I"; //1
    string val6 = "manu";
    string c7 = "M"; //1
    string val7 = "perna";
    string c8 = "F"; //2
    string val8 = "gustavo";
    string c9 = "J"; //2
    string val9 = "Ykky";
    string c10 = "G"; //3
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
    ListaEncadeada<string, string> *busca;

    busca = buscarListaNaHashTable(tabela, c4);
    ASSERT_EQ(busca, tabela->_itens[3]);

    removerDaHashTable(tabela, c4);
    busca = buscarListaNaHashTable(tabela, c10);
    ASSERT_EQ(*busca->_primeiro->_dado, val10);

    removerDaHashTable(tabela, c9);
    busca = buscarListaNaHashTable(tabela, c3);
    ASSERT_EQ(busca->_primeiro->_proximo->_proximo, nullptr);
    ASSERT_EQ(tabela->_itens[2]->_quantidade, 2);

    removerDaHashTable(tabela, c5);
    busca = buscarListaNaHashTable(tabela, c2);
    ASSERT_EQ(*busca->_primeiro->_proximo->_dado, val6);

    destroiHashTable(tabela);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}