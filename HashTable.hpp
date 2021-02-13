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

HashTable *inicializaTabela(int tamanho);
void destroiHashTable(HashTable *tabela);
template <typename TKey, typename TData>
void adiciona(HashTable *tabela, TKey chave, TData valor);
template <typename TKey, typename TData>
void remove(HashTable *tabela, TKey chave, TData valor);
template <typename TKey, typename TData>
ListaEncadeada *buscar(HashTable *tabela, TKey chave, TData valor);

#endif /* HASHTABLE_HPP */