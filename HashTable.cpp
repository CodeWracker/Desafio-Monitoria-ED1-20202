#include "HashTable.hpp"
#include <stdlib.h>

int stringValue(string str)
{
    int val;
    for (int i = 0; i < str.length(); i++)
        val = val + i * str[i];
    return val;
}

template <typename T>
int hashFunction(T chave, int tam)
{
    int k;
    if (typeid(chave) == typeid(string))
        k = stringValue(chave);
    else
        k = floor(chave);
    k = k % tam;
    return k;
}
template <typename TKey, typename TData>
void inicializaHashTable(HashTable<TKey, TData> *tabela, int tamanho)
{
    tabela = (HashTable<TKey, TData> *)malloc(sizeof(HashTable<TKey, TData>));
    if (tabela == nullptr)
        throw impossivel_criar_tabela_exception();
    tabela->_tamanho = tamanho;
    tabela->_itens = (Elemento<TKey, TData> **)malloc(tamanho * sizeof(Elemento<TKey, TData>));
    if (tabela->_itens == nullptr)
        throw impossivel_criar_tabela_exception();
}
template <typename TKey, typename TData>
void adicionarNaHashTable(HashTable<TKey, TData> *tabela, TKey chave, TData *valor)
{
    int pos = hashFunction(chave, tabela->_tamanho);
    adicionaNoFim(tabela->_itens[pos], valor);
}
template <typename TKey, typename TData>
void destroiHashTable(HashTable<TKey, TData> *tabela)
{
    free(tabela);
}

template <typename TKey, typename TData>
void removerDaHashTable(HashTable<TKey, TData> *tabela, TKey chave) {}
template <typename TKey, typename TData>
Elemento<TKey, TData> *buscarNaHashTable(HashTable<TKey, TData> *tabela, TKey chave) {}