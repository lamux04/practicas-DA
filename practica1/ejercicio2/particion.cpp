#include "particion.hpp"

Particion::Particion(int n) : p(n, -1)
{
}

int Particion::buscar(int i) const
{
    int representante = i;
    while (p[representante] >= 0)
        representante = p[representante];
    while (p[i] >= 0)
    {
        int aux = p[i];
        p[i] = representante;
        i = aux;
    }

    return representante;
}

void Particion::unir(int i, int j)
{
    if (p[i] < p[j])
        p[j] = i;
    else
    {
        if (p[j] == p[i])
            p[j]--;
        p[i] = j;
    }
}