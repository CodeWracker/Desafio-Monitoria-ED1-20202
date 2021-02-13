#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <cmath>
#include <exception>
#include <string>

#include "Elemento.hpp"
#include "ListaEncadeada.hpp"

using namespace std;

class impossivel_criar_tabela_exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Não foi possivel inicializar a Tabela";
    }
};
class adicionar_em_tabela_nula_exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Não é possivel adicionar em null";
    }
};

class chave_igual_exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Não é possivel adicionar com chaves repetidas";
    }
};
template <typename TKey, typename TData>
struct HashTable
{
    int *_tamanho;
    ListaEncadeada<TKey, TData> **_itens;
};
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
    if (typeid(chave) == typeid(char))
        k = chave[0];
    else
        k = floor(chave[0]);
    k = k % tam;
    return k;
}
template <typename TKey, typename TData>
void inicializaHashTable(HashTable<TKey, TData> *tabela, int *tamanho)
{
    tabela = (HashTable<TKey, TData> *)malloc(sizeof(HashTable<TKey, TData>));
    if (tabela == nullptr)
        throw impossivel_criar_tabela_exception();
    tabela->_tamanho = tamanho;
    tabela->_itens = (ListaEncadeada<TKey, TData> **)malloc(*tamanho * sizeof(ListaEncadeada<TKey, TData>));
    if (tabela->_itens == nullptr)
        throw impossivel_criar_tabela_exception();
}
template <typename TKey, typename TData>
void adicionarNaHashTable(HashTable<TKey, TData> *tabela, TKey *chave, TData *valor)
{
    int pos = hashFunction(*chave, *tabela->_tamanho);
    if (tabela == nullptr)
        throw adicionar_em_tabela_nula_exception();
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
Elemento<TKey, TData> *buscarNaHashTable(HashTable<TKey, TData> *tabela, TKey chave)
{
    Elemento<TKey, TData> *busca;

    return busca;
}

#endif /* HASHTABLE_HPP */