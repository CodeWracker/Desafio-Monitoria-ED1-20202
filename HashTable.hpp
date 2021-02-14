#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <stddef.h>
#include <stdint.h>
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

class chave_invalida_exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Não foi possivel encontrar a chave solicitada";
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
    int val = 0;
    char aux;
    //cout << "val = " << val << endl;
    for (int i = 0; i < str.length(); i++)
    {
        aux = str[i];
        val = val + (i + str.length()) * aux;
        //cout << "val = " << val << endl;
    }

    return val;
}

int hashFunction(int chave, int tam)
{
    int k = chave;
    k = k % tam;

    return k;
}

int hashFunction(char chave, int tam)
{
    int k = chave;
    k = k % tam;
    return k;
}

int hashFunction(string chave, int tam)
{
    int k = stringValue(chave);
    //cout << "string value = " << k << endl;
    k = k % tam;
    //cout << "k = " << k << endl;
    return k;
}

int hashFunction(float chave, int tam)
{
    int k = floor(chave);
    k = k % tam;
    return k;
}
template <typename TKey, typename TData>
void inicializaHashTable(HashTable<TKey, TData> *tabela, int tamanho)
{

    if (tabela == nullptr)
        throw impossivel_criar_tabela_exception();
    tabela->_tamanho = tamanho;
    tabela->_itens = (ListaEncadeada<TKey, TData> **)calloc(tamanho, sizeof(ListaEncadeada<TKey, TData> *));
    if (tabela->_itens == nullptr)
        throw impossivel_criar_tabela_exception();
    for (int i = 0; i < tamanho; i++)
    {
        tabela->_itens[i] = iniciaListaEncadeada<TKey, TData>();
        tabela->_itens[i]->_primeiro = nullptr;
    }
}
template <typename TKey, typename TData>
void adicionarNaHashTable(HashTable<TKey, TData> *tabela, TKey *chave, TData *valor)
{
    if (tabela == nullptr)
        throw adicionar_em_tabela_nula_exception();
    int pos = hashFunction(*chave, tabela->_tamanho);
    bool er = false;
    if (tabela->_itens[pos]->_primeiro != nullptr)
    {
        ListaEncadeada<TKey, TData> *lista = tabela->_itens[pos];
        Elemento<TKey, TData> *item = lista->_primeiro;
        for (int i = 0; i < lista->_quantidade; i++)
        {
            if (*item->_chave == *chave)
            {
                er = true;
                break;
            }
            if (item->_proximo != nullptr)
                item = item->_proximo;
        }
    }

    if (!er)
        adicionaNoFim(tabela->_itens[pos], valor, chave);
    else
        throw chave_igual_exception();
}
template <typename TKey, typename TData>
void destroiHashTable(HashTable<TKey, TData> *tabela)
{
    for (int i = 0; i < tabela->_tamanho; i++)
    {
        ListaEncadeada<TKey, TData> *item = tabela->_itens[i];
        destroiListaEncadeada(item);
    }
    free(tabela->_itens);
    free(tabela);
}

template <typename TKey, typename TData>
void removerDaHashTable(HashTable<TKey, TData> *tabela, TKey chave)
{
    if (tabela == nullptr)
        throw adicionar_em_tabela_nula_exception();
    int pos = hashFunction(chave, tabela->_tamanho);
    removerEspecifico(tabela->_itens[pos], chave);
}
template <typename TKey, typename TData>
Elemento<TKey, TData> *buscarElementoNaHashTable(HashTable<TKey, TData> *tabela, TKey chave)
{
    if (tabela == nullptr)
        throw adicionar_em_tabela_nula_exception();
    int pos = hashFunction(chave, tabela->_tamanho);
    if (tabela->_itens[pos]->_primeiro != nullptr)
    {
        ListaEncadeada<TKey, TData> *lista = tabela->_itens[pos];
        Elemento<TKey, TData> *item = lista->_primeiro;
        for (int i = 0; i < lista->_quantidade; i++)
        {
            if (*item->_chave == chave)
            {
                return item;
            }
            if (item->_proximo != nullptr)
                item = item->_proximo;
        }
    }
    return nullptr;
}

template <typename TKey, typename TData>
ListaEncadeada<TKey, TData> *buscarListaNaHashTable(HashTable<TKey, TData> *tabela, TKey chave)
{
    if (tabela == nullptr)
        throw adicionar_em_tabela_nula_exception();
    int pos = hashFunction(chave, tabela->_tamanho);
    //cout << pos << endl;
    return tabela->_itens[pos];
}

#endif /* HASHTABLE_HPP */