#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

#include "Elemento.hpp"

#include <stdbool.h>
#include <exception>
#include <new>

class posicao_invalida_exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Posicao invalida na lista encadeada";
    }
};

class lista_encadeada_vazia_exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Lista encadeada vazia";
    }
};
template <typename TKey, typename TData>
struct ListaEncadeada
{
    Elemento<TKey, TData> *_primeiro;
    int _quantidade;
};
template <typename TKey, typename TData>
ListaEncadeada<TKey, TData> *iniciaListaEncadeada();

template <typename TKey, typename TData>
void destroiListaEncadeada(ListaEncadeada<TKey, TData> *umaLista);

template <typename TKey, typename TData>
bool listaVazia(ListaEncadeada<TKey, TData> *umaLista);

template <typename TKey, typename TData>
int posicao(ListaEncadeada<TKey, TData> *umaLista, void *umDado);

template <typename TKey, typename TData>
bool contem(ListaEncadeada<TKey, TData> *umaLista, void *umDado);

template <typename TKey, typename TData>
void adicionaNoInicio(ListaEncadeada<TKey, TData> *umaLista, void *umDado);

template <typename TKey, typename TData>
void adicionaNaPosicao(ListaEncadeada<TKey, TData> *umaLista, void *umDado, int umaPosicao);

template <typename TKey, typename TData>
void adicionaNoFim(ListaEncadeada<TKey, TData> *umaLista, void *umDado);

template <typename TKey, typename TData>
void *retiraDoInicio(ListaEncadeada<TKey, TData> *umaLista);

template <typename TKey, typename TData>
void *retiraDaPosicao(ListaEncadeada<TKey, TData> *umaLista, int umaPosicao);

template <typename TKey, typename TData>
void *retiraDoFim(ListaEncadeada<TKey, TData> *umaLista);

template <typename TKey, typename TData>
void *retiraEspecifico(ListaEncadeada<TKey, TData> *umaLista, void *umDado);

#endif /* LISTAENCADEADA_HPP */
