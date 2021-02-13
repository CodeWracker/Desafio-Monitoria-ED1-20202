#include "HashTable.hpp"
#include <stdlib.h>

HashTable *inicializaTabela(int tamanho)
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
void destroiHashTable(HashTable *tabela);
template <typename TKey, typename TData>
void adiciona(HashTable *tabela, TKey chave, TData valor);
template <typename TKey, typename TData>
void remove(HashTable *tabela, TKey chave, TData valor);
template <typename TKey, typename TData>
ListaEncadeada *buscar(HashTable *tabela, TKey chave, TData valor);