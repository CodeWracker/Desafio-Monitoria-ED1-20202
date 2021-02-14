#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

#include "Elemento.hpp"

#include <stdbool.h>
#include <exception>
#include <new>
#include <stdlib.h>
#include <string>
using namespace std;
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
ListaEncadeada<TKey, TData> *iniciaListaEncadeada()
{
    ListaEncadeada<TKey, TData> *lista = (ListaEncadeada<TKey, TData> *)calloc(1, sizeof(ListaEncadeada<TKey, TData>));
    return lista;
}
template <typename TKey, typename TData>
void destroiListaEncadeada(ListaEncadeada<TKey, TData> *umaLista)
{
    Elemento<TKey, TData> *atual = nullptr;
    Elemento<TKey, TData> *proximo = nullptr;

    if (!listaVazia(umaLista))
    {
        atual = umaLista->_primeiro;
        proximo = atual->_proximo;
        free(atual);
    }

    while (proximo != nullptr)
    {
        atual = proximo;
        proximo = atual->_proximo;
        free(atual);
    }

    free(umaLista);
}
template <typename TKey, typename TData>
bool listaVazia(ListaEncadeada<TKey, TData> *umaLista)
{
    if (umaLista != nullptr && umaLista->_quantidade != 0)
    {
        return false;
    }
    else
        return true;
}
template <typename TKey, typename TData>
void adicionaNoInicio(ListaEncadeada<TKey, TData> *umaLista, TData *umDado, TKey *chave)
{
    Elemento<TKey, TData> *novo = (Elemento<TKey, TData> *)calloc(1, sizeof(Elemento<TKey, TData>));

    novo->_proximo = umaLista->_primeiro;
    novo->_dado = umDado;
    novo->_chave = chave;
    umaLista->_primeiro = novo;
    umaLista->_quantidade++;
}

template <typename TKey, typename TData>
Elemento<TKey, TData> *getN(ListaEncadeada<TKey, TData> *umaLista, int posicao)
{
    Elemento<TKey, TData> *ret = umaLista->_primeiro;

    for (int i = 0; i < posicao - 1; i++)
    {
        ret = ret->_proximo;
    }

    return ret;
}
template <typename TKey, typename TData>
void adicionaNaPosicao(ListaEncadeada<TKey, TData> *umaLista, TData *umDado, TKey *chave, int umaPosicao)
{

    //EXCECAO
    if (umaPosicao < 1 || umaPosicao > umaLista->_quantidade + 1)
    {
        throw posicao_invalida_exception();
    }

    if (umaPosicao == 1)
    {
        adicionaNoInicio(umaLista, umDado, chave);
    }
    else
    {
        Elemento<TKey, TData> *novo = (Elemento<TKey, TData> *)calloc(1, sizeof(Elemento<TKey, TData>));
        Elemento<TKey, TData> *anterior = getN(umaLista, umaPosicao - 1);

        novo->_proximo = anterior->_proximo;
        novo->_dado = umDado;
        novo->_chave = chave;
        anterior->_proximo = novo;

        umaLista->_quantidade++;
    }
}
template <typename TKey, typename TData>
void adicionaNoFim(ListaEncadeada<TKey, TData> *umaLista, TData *umDado, TKey *chave)
{
    adicionaNaPosicao(umaLista, umDado, chave, umaLista->_quantidade + 1);
}
template <typename TKey, typename TData>
int posicao(ListaEncadeada<TKey, TData> *umaLista, TData *umDado)
{

    if (listaVazia(umaLista))
    {
        return -1;
    }

    Elemento<TKey, TData> *elemento = umaLista->_primeiro;

    if (elemento->_dado == umDado)
    {
        return 1;
    }

    for (int i = 2; i < umaLista->_quantidade + 1; i++)
    {
        elemento = elemento->_proximo;

        if (elemento->_dado == umDado)
        {
            return i;
        }
    }

    return -1;
}
template <typename TKey, typename TData>
bool contem(ListaEncadeada<TKey, TData> *umaLista, TData *umDado)
{
    if (listaVazia(umaLista))
    {
        return false;
    }
    else
    {
        Elemento<TKey, TData> *elemento = umaLista->_primeiro;

        for (int i = 1; i <= umaLista->_quantidade; i++)
        {
            if (elemento->_dado == umDado)
            {
                return true;
            }
            else if (elemento->_proximo != nullptr)
            {
                elemento = elemento->_proximo;
            }
            else
            {
                return false;
            }
        }

        return false;
    }
}
template <typename TKey, typename TData>
TData *retiraDoInicio(ListaEncadeada<TKey, TData> *umaLista)
{
    if (umaLista == nullptr || umaLista->_quantidade == 0)
        throw lista_encadeada_vazia_exception();

    Elemento<TKey, TData> *elemento;
    TData *dado;

    elemento = umaLista->_primeiro;
    dado = elemento->_dado;
    umaLista->_primeiro = elemento->_proximo;
    umaLista->_quantidade--;

    free(elemento);

    return dado;
}
template <typename TKey, typename TData>
void removerEspecifico(ListaEncadeada<TKey, TData> *umaLista, TKey chave)
{
    if (umaLista == nullptr || umaLista->_quantidade == 0)
    {
        throw lista_encadeada_vazia_exception();
    }

    Elemento<TKey, TData> *sai = umaLista->_primeiro;
    Elemento<TKey, TData> *anterior = sai;
    bool achou = false;
    for (int i = 0; i < umaLista->_quantidade; i++)
    {
        //cout << *sai->_dado << endl;
        if (*sai->_chave == chave)
        {
            achou = true;
            //cout << "achei" << endl;
            break;
        }
        //cout << "isso é pra aparecer uma vez" << endl;
        anterior = sai;
        if (sai->_proximo == nullptr)
            break;

        sai = sai->_proximo;
    }
    if (!achou)
        throw posicao_invalida_exception();
    //cout << "anterior: " << *anterior->_dado << " // sai: " << *sai->_dado << endl;
    if (umaLista->_primeiro == sai)
        retiraDoInicio(umaLista);
    else
    {
        anterior->_proximo = sai->_proximo;

        free(sai);
        umaLista->_quantidade--;
    }
}
template <typename TKey, typename TData>
TData *retiraDaPosicao(ListaEncadeada<TKey, TData> *umaLista, int umaPosicao)
{
    if (umaLista == nullptr || umaLista->_quantidade == 0)
    {
        throw lista_encadeada_vazia_exception();
    }

    if (umaPosicao < 1 || umaPosicao > umaLista->_quantidade)
    {
        throw posicao_invalida_exception();
    }

    if (umaPosicao == 1)
    {
        return retiraDoInicio(umaLista);
    }
    else
    {
        Elemento<TKey, TData> *sai;
        Elemento<TKey, TData> *anterior = getN(umaLista, umaPosicao - 1);
        TData *dado;

        sai = anterior->_proximo;
        dado = sai->_dado;
        anterior->_proximo = sai->_proximo;

        free(sai);
        umaLista->_quantidade--;
        return dado;
    }
}
#endif /* LISTAENCADEADA_HPP */
