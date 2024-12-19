#include "damas.hpp"
#include <cassert>
#include <algorithm>

bool Tablero::amenazada(int i, int j) const
{
    assert(valida(i, j));
    bool a = false;
    if (columna_dama[i] != n) a = true;
    if (columna_amenazada[j]) a = true;
    if (diagonal_creciente_amenazada[i + j]) a = true;
    if (diagonal_decreciente_amenazada[i + n - 1 - j]) a = true;
    return a;
}

void Tablero::coloca(int i, int j)
{
    assert(valida(i, j) && !amenazada(i, j));
    columna_dama[i] = j;
    columna_amenazada[j] = diagonal_creciente_amenazada[i + j] = diagonal_decreciente_amenazada[i + n - 1 - j] = true;
}

void Tablero::elimina(int i, int j)
{
    assert(valida(i, j));
    if (columna_dama[i] == j)
    {
        columna_dama[i] = n;
        columna_amenazada[j] = diagonal_creciente_amenazada[i + j] = diagonal_decreciente_amenazada[i + n - 1 - j] = false;
    }
}

bool Tablero::valida(int k) const
{
    return k >= 0 && k < n;
}

bool Tablero::valida(int i, int j) const
{
    return valida(i) && valida(j);
}

std::ostream& operator <<(std::ostream& fs, const Tablero& t)
{
    for (int i = 0; i < t.dimension(); i++)
    {
        int dama = t[i];
        for (int j = 0; j < dama; ++j)
            fs << "-";
        if (dama < t.dimension())
            fs << "+";
        for (int j = dama + 1; j < t.dimension(); ++j)
            fs << "-";
        fs << std::endl;
    }
    return fs;
}

int Tablero::operator [](int i) const
{
    assert(valida(i));
    return columna_dama[i];
}

bool solucion(const std::vector<Tablero>& s, size_t k)
{
    bool esSolucion = true;
    for (int i = 0; i < s[k].dimension(); ++i)
        if (s[k][i] == s[k].dimension())
            esSolucion = false;
    return esSolucion;
}

bool vuelta_atras(std::vector<Tablero>& s, size_t k, Tablero& tsolucion)
{
    size_t n = s[0].dimension();
    bool bsolucion = false;
    size_t j = 0;
    while (j < n && !bsolucion)
    {
        if (!s[k - 1].amenazada(k - 1, j))
        {
            s[k] = s[k - 1];
            s[k].coloca(k - 1, j);
            // std::cout << s[k] << std::endl << std::endl;
            if (solucion(s, k))
            {
                tsolucion = s[k];
                bsolucion = true;
            }
            else
                bsolucion = vuelta_atras(s, k + 1, tsolucion);
        }
        ++j;
    }
    return bsolucion;
}

bool damas_solucion(Tablero& t)
{
    std::vector<Tablero> s(t.dimension() + 1, t);
    return vuelta_atras(s, 1, t);
}

