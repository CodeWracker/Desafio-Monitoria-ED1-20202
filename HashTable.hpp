#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#define typename(x) _Generic((x), /* Get the name of a type */         \
                                                                       \
                             _Bool                                     \
                             : "_Bool", unsigned char                  \
                             : "unsigned char",                        \
                               char                                    \
                             : "char", signed char                     \
                             : "signed char",                          \
                               short int                               \
                             : "short int", unsigned short int         \
                             : "unsigned short int",                   \
                               int                                     \
                             : "int", unsigned int                     \
                             : "unsigned int",                         \
                               long int                                \
                             : "long int", unsigned long int           \
                             : "unsigned long int",                    \
                               long long int                           \
                             : "long long int", unsigned long long int \
                             : "unsigned long long int",               \
                               float                                   \
                             : "float", double                         \
                             : "double",                               \
                               long double                             \
                             : "long double", char *                   \
                             : "pointer to char",                      \
                               void *                                  \
                             : "pointer to void", int *                \
                             : "pointer to int",                       \
                               default                                 \
                             : "other")

#include <cmath>
#include <exception>
#include <string>
#include <cstdlib>

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
    int _tamanho;
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
    /*if (typeof(chave) == typeof(string))
        k = stringValue(chave);
    if (typeof(chave) == typeof(char))
        k = chave[0];
    else
        k = floor(chave[0]);
    k = k % tam;*/
    return k;
}
template <typename TKey, typename TData>
void inicializaHashTable(HashTable<TKey, TData> *tabela, int tamanho)
{

    if (tabela == nullptr)
        throw impossivel_criar_tabela_exception();
    tabela->_tamanho = tamanho;
    tabela->_itens = new ListaEncadeada<TKey, TData> *[tamanho];
    if (tabela->_itens == nullptr)
        throw impossivel_criar_tabela_exception();
}
template <typename TKey, typename TData>
void adicionarNaHashTable(HashTable<TKey, TData> *tabela, TKey *chave, TData *valor)
{
    int pos = hashFunction(*chave, tabela->_tamanho);
    if (tabela == nullptr)
        throw adicionar_em_tabela_nula_exception();
    adicionaNoFim(tabela->_itens[pos], valor);
}
template <typename TKey, typename TData>
void destroiHashTable(HashTable<TKey, TData> *tabela)
{
    for (int i = 0; i < tabela->_tamanho; i++)
    {
        ListaEncadeada<TKey, TData> *item = tabela->_itens[i];
        destroiListaEncadeada(item);
    }
    free(tabela);
}

template <typename TKey, typename TData>
void removerDaHashTable(HashTable<TKey, TData> *tabela, TKey chave) {}
template <typename TKey, typename TData>
Elemento<TKey, TData> *buscarElementoNaHashTable(HashTable<TKey, TData> *tabela, TKey chave)
{
    Elemento<TKey, TData> *busca;

    return busca;
}

template <typename TKey, typename TData>
ListaEncadeada<TKey, TData> *buscarListaNaHashTable(HashTable<TKey, TData> *tabela, TKey chave)
{
    ListaEncadeada<TKey, TData> *busca;

    return busca;
}

#endif /* HASHTABLE_HPP */