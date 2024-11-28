#ifndef ORDENACION_HPP
#define ORDENACION_HPP

#include <algorithm>
#include <iostream>

template <typename I>
void ordenacion_isercion(I i, I j)
{
    if (i != j)
        for (I k = i + 1; k != j; k++)
        {
            I x = k;
            while (x != i && *x < *(x - 1))
            {
                std::swap(*x, *(x - 1));
                x--;
            }
        }
}

template <typename I>
void ordenacion_fusion(I i, I j, int n0 = 1)
{
    int n = j - i;

    if (n <= n0)
    {
        ordenacion_isercion(i, j);
    }
    else
    {
        I k = i + n / 2;
        ordenacion_fusion(i, k, n0);
        ordenacion_fusion(k, j, n0);
        std::inplace_merge(i, k, j);
    }
}

template <typename I>
I pivote(I i, I j)
{
    I p = i;
    auto x = *i;
    for (I k = i + 1; k != j; ++k)
    {
        if (*k <= x)
        {
            p++;
            std::swap(*p, *k);
        }
    }
    std::swap(*i, *p);
    return p;
}

template <typename I>
void ordenacion_rapida(I i, I j, int n0 = 1)
{
    int n = j - i;
    if (n <= n0)
        ordenacion_isercion(i, j);
    else
    {
        I p = pivote(i, j);
        ordenacion_rapida(i, p, n0);
        ordenacion_rapida(p + 1, j, n0);
    }
}



#endif