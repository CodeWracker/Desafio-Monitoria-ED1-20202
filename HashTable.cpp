#include "HashTable.hpp"
#include <stdlib.h>

HashTable *inicializaHashTable(int tamanho)
{
    HashTable *tabela = (HashTable *)malloc(sizeof(HashTable));
    if (tabela == nullptr)
        throw impossivel_criar_tabela_exception();
    tabela->_tamanho = tamanho;
    tabela->_itens = (Elemento **)malloc(tamanho * sizeof(Elemento));
    if (tabela->_itens == nullptr)
        throw impossivel_criar_tabela_exception();
    return tabela;
}
void destroiHashTable(HashTable *tabela)
{
    free(tabela);
}
template <typename TKey, typename TData>
void adicionarNaHashTable(HashTable *tabela, TKey chave, TData valor);
template <typename TKey, typename TData>
void removerDaHashTable(HashTable *tabela, TKey chave, TData valor);
template <typename TKey, typename TData>
ListaEncadeada *buscarNaHashTable(HashTable *tabela, TKey chave, TData valor);