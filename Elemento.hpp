#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

typedef struct Elemento
{
    struct Elemento *_proximo;
    void *_dado;
} Elemento;

#endif /* ELEMENTO_HPP */