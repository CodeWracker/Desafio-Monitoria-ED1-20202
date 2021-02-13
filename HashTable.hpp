#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <exception>

#include "Elemento.hpp"
#include "ListaEncadeada.hpp"

class impossivel_criar_tabela_exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Não foi possivel inicializar a Tabela";
    }
};

typedef struct
{
    int _tamanho;
    Elemento **_itens;
} HashTable;

HashTable *inicializaHashTable(int tamanho);
void destroiHashTable(HashTable *tabela);
template <typename TKey, typename TData>
void adicionarNaHashTable(HashTable *tabela, TKey chave, TData valor);
template <typename TKey, typename TData>
void removerDaHashTable(HashTable *tabela, TKey chave, TData valor);
template <typename TKey, typename TData>
ListaEncadeada *buscarNaHashTable(HashTable *tabela, TKey chave, TData valor);

#endif /* HASHTABLE_HPP */