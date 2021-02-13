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
template <typename TKey, typename TData>
struct HashTable
{
    int _tamanho;
    Elemento<TKey, TData> **_itens;
};
template <typename TKey, typename TData>
void inicializaHashTable(HashTable<TKey, TData> *tabela, int tamanho);
template <typename TKey, typename TData>
void destroiHashTable(HashTable<TKey, TData> *tabela);
template <typename TKey, typename TData>
void adicionarNaHashTable(HashTable<TKey, TData> *tabela, TKey chave, TData valor);
template <typename TKey, typename TData>
void removerDaHashTable(HashTable<TKey, TData> *tabela, TKey chave);
template <typename TKey, typename TData>
Elemento<TKey, TData> *buscarNaHashTable(HashTable<TKey, TData> *tabela, TKey chave);

#endif /* HASHTABLE_HPP */