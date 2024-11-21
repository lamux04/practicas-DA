#include "matrices.hpp"
#include <algorithm>
#include <limits>
#include <list>

MatrizCaminos Floyd(MatrizPesos& p)
{
    size_t n = p.size();
    MatrizCaminos S(n);
    for (int i = 0; i < n; ++i)
    {
        p[i][i] = 0;
        for (int j = 0; j < n; ++j)
            S[i][j] = i;
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (p[i][k] + p[k][j] < p[i][j])
                {
                    p[i][j] = p[i][k] + p[k][j];
                    S[i][j] = k;
                }
            }
    return S;
}

Camino CaminoMinimo(const MatrizCaminos& c, size_t i, size_t j)
{
    Camino l;
    l.push_back(j);
    size_t k = j;
    while (k != i)
    {
        k = c[i][k];
        l.push_front(k);
    }
    return l;
}
