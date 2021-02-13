#include "ListaEncadeada.hpp"
#include <stdlib.h>

ListaEncadeada *iniciaListaEncadeada()
{
    ListaEncadeada *lista = (ListaEncadeada *)calloc(1, sizeof(ListaEncadeada));
    return lista;
}

void destroiListaEncadeada(ListaEncadeada *umaLista)
{
    Elemento *atual = nullptr;
    Elemento *proximo = nullptr;

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

bool listaVazia(ListaEncadeada *umaLista)
{
    if (umaLista != nullptr && umaLista->_quantidade != 0)
    {
        return false;
    }
    else
        return true;
}

void adicionaNoInicio(ListaEncadeada *umaLista, void *umDado)
{
    Elemento *novo = (Elemento *)calloc(1, sizeof(Elemento));

    novo->_proximo = umaLista->_primeiro;
    novo->_dado = umDado;

    umaLista->_primeiro = novo;
    umaLista->_quantidade++;
}

Elemento *getN(ListaEncadeada *umaLista, int posicao)
{
    Elemento *ret = umaLista->_primeiro;

    for (int i = 0; i < posicao - 1; i++)
    {
        ret = ret->_proximo;
    }

    return ret;
}

void adicionaNaPosicao(ListaEncadeada *umaLista, void *umDado, int umaPosicao)
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
        Elemento *novo = (Elemento *)calloc(1, sizeof(Elemento));
        Elemento *anterior = getN(umaLista, umaPosicao - 1);

        novo->_proximo = anterior->_proximo;
        novo->_dado = umDado;
        anterior->_proximo = novo;

        umaLista->_quantidade++;
    }
}

void adicionaNoFim(ListaEncadeada *umaLista, void *umDado)
{
    adicionaNaPosicao(umaLista, umDado, umaLista->_quantidade + 1);
}

int posicao(ListaEncadeada *umaLista, void *umDado)
{

    if (listaVazia(umaLista))
    {
        return -1;
    }

    Elemento *elemento = umaLista->_primeiro;

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

bool contem(ListaEncadeada *umaLista, void *umDado)
{
    if (listaVazia(umaLista))
    {
        return false;
    }
    else
    {
        Elemento *elemento = umaLista->_primeiro;

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

void *retiraDoInicio(ListaEncadeada *umaLista)
{
    if (umaLista == nullptr || umaLista->_quantidade == 0)
        throw lista_encadeada_vazia_exception();

    Elemento *elemento;
    void *dado;

    elemento = umaLista->_primeiro;
    dado = elemento->_dado;
    umaLista->_primeiro = elemento->_proximo;
    umaLista->_quantidade--;

    free(elemento);

    return dado;
}

void *retiraDaPosicao(ListaEncadeada *umaLista, int umaPosicao)
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
        Elemento *sai;
        Elemento *anterior = getN(umaLista, umaPosicao - 1);
        void *dado;

        sai = anterior->_proximo;
        dado = sai->_dado;
        anterior->_proximo = sai->_proximo;

        free(sai);
        umaLista->_quantidade--;
        return dado;
    }
}