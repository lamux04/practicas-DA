#include <iterator>
#include <algorithm>
#include "mochila.hpp"

std::istream& operator>> (std::istream& fe, Objeto& o)
{
    return fe >> o.nombre() >> o.peso() >> o.valor();
}

std::istream& operator>> (std::istream& fe, Objetos& obs)
{
    std::istream_iterator<Objeto> ife(fe), fin;
    std::copy(ife, fin, std::back_inserter(obs));
    return fe;
}

std::ostream& operator<< (std::ostream& fe, const Objeto& o)
{
    fe << o.nombre() << " " << o.peso() << " " << o.valor() << std::endl;
    return fe;
}

std::ostream& operator<< (std::ostream& fe, const Objetos& obs)
{
    for (auto i : obs)
        fe << i;
    return fe;
}

Objetos mochila(const Objetos& objetos, unsigned int capacidad)
{
    // Tabla de subproblemas resueltos (TSP).
    using Indice = Objetos::size_type;
    using TSP = std::vector<std::vector<double>>;
    const Indice n = objetos.size();
    TSP tsp(n, TSP::value_type(capacidad + 1));
    // Cálculo de los valores de la TSP.
    for (int i = 0; i <= capacidad; ++i)
    {
        if (i < objetos[0].peso())
            tsp[0][i] = 0;
        else
            tsp[0][i] = objetos[0].valor();
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= capacidad; j++)
        {
            if (j < objetos[i].peso())
                tsp[i][j] = objetos[i].valor();
            else
                tsp[i][j] = std::max(objetos[i].valor() + tsp[i - 1][j - objetos[i].peso()], tsp[i - 1][j]);
        }
    }
    // Recuperación de la solución a partir de la TSP.
    Objetos solucion;
    Indice i = n - 1, j = capacidad;
    while (i > 0)
    {
        if (tsp[i][j] == tsp[i - 1][j])
            i--;
        else
        {
            i--;
            j -= objetos[i].peso();
            solucion.push_back(objetos[i]);
        }
    }
    if (tsp[i][j] > 0)
        solucion.push_back(objetos[0]);
    return solucion;
}
