#include "ListaEncadeada.hpp"
#include <stdlib.h>
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
void adicionaNoInicio(ListaEncadeada<TKey, TData> *umaLista, void *umDado)
{
    Elemento<TKey, TData> *novo = (Elemento<TKey, TData> *)calloc(1, sizeof(Elemento<TKey, TData>));

    novo->_proximo = umaLista->_primeiro;
    novo->_dado = umDado;

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
void adicionaNaPosicao(ListaEncadeada<TKey, TData> *umaLista, void *umDado, int umaPosicao)
{

    //EXCECAO
    if (umaPosicao < 1 || umaPosicao > umaLista->_quantidade + 1)
    {
        throw posicao_invalida_exception();
    }

    if (umaPosicao == 1)
    {
        adicionaNoInicio(umaLista, umDado);
    }
    else
    {
        Elemento<TKey, TData> *novo = (Elemento<TKey, TData> *)calloc(1, sizeof(Elemento<TKey, TData>));
        Elemento<TKey, TData> *anterior = getN(umaLista, umaPosicao - 1);

        novo->_proximo = anterior->_proximo;
        novo->_dado = umDado;
        anterior->_proximo = novo;

        umaLista->_quantidade++;
    }
}
template <typename TKey, typename TData>
void adicionaNoFim(ListaEncadeada<TKey, TData> *umaLista, void *umDado)
{
    adicionaNaPosicao(umaLista, umDado, umaLista->_quantidade + 1);
}
template <typename TKey, typename TData>
int posicao(ListaEncadeada<TKey, TData> *umaLista, void *umDado)
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
bool contem(ListaEncadeada<TKey, TData> *umaLista, void *umDado)
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
void *retiraDoInicio(ListaEncadeada<TKey, TData> *umaLista)
{
    if (umaLista == nullptr || umaLista->_quantidade == 0)
        throw lista_encadeada_vazia_exception();

    Elemento<TKey, TData> *elemento;
    void *dado;

    elemento = umaLista->_primeiro;
    dado = elemento->_dado;
    umaLista->_primeiro = elemento->_proximo;
    umaLista->_quantidade--;

    free(elemento);

    return dado;
}
template <typename TKey, typename TData>
void *retiraDaPosicao(ListaEncadeada<TKey, TData> *umaLista, int umaPosicao)
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
        void *dado;

        sai = anterior->_proximo;
        dado = sai->_dado;
        anterior->_proximo = sai->_proximo;

        free(sai);
        umaLista->_quantidade--;
        return dado;
    }
}