#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template <typename TKey, typename TData>
struct Elemento
{
    Elemento *_proximo;
    TData *_dado;
    TKey *_chave;
};

#endif /* ELEMENTO_HPP */