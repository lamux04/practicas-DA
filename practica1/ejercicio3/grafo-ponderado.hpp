#ifndef GRAFO_PONDERADO_HPP_
#define GRAFO_PONDERADO_HPP_

#include <iostream>
#include <algorithm>
#include <iterator>
#include "grafo.hpp"
#include "particion.hpp"

// Arista ponderada.

template <typename V, typename P = double>
class AristaPonderada : public Arista<V> {
public:
    using Peso = P;
    AristaPonderada(V u, V v, Peso p = Peso()) : Arista<V>(u, v), p{ p } {}
    Peso peso() const { return p; }
    Peso& peso() { return p; }
private:
    Peso p;
};

template <typename V, typename P = double>
bool operator < (const AristaPonderada<V, P>& a, const AristaPonderada<V, P>& b)
{
    return a.peso() < b.peso();
}

// Grafo ponderado.

template <typename V, typename P = double>
class GrafoPonderado : public Grafo<V, AristaPonderada<V, P>> {
public:
    using Peso = P;
    GrafoPonderado(size_t n = 0) : Grafo<V, AristaPonderada<V, P>>(n) {}
};

template <typename V, typename P>
std::istream& operator>>(std::istream& fe, AristaPonderada<V, P>& a)
{
    using namespace std;
    return fe >> a.primero() >> a.segundo() >> a.peso();
}

template <typename V, typename P>
std::ostream& operator <<(std::ostream& fs, const AristaPonderada<V, P>& a)
{
    using namespace std;
    return fs << a.primero() << ' ' << a.segundo() << ' ' << a.peso();
}


template <typename G>
G Kruskal(const G& g)
{
    using std::list;
    using Arista = typename G::Arista;
    using Vertice = typename G::Vertice;
    size_t n = g.nVertices();
    G s(n);
    Particion p(n);
    list<Arista> c(g.aristas());

    c.sort();
    c.reverse();

    while (n > 1 && !c.empty())
    {
        Arista t = *(c.begin());
        c.erase(c.begin());

        int n1 = p.buscar(t.primero()),
            n2 = p.buscar(t.segundo());
        if (n1 != n2)
        {
            p.unir(n1, n2);
            s.insertarArista(t);
            n--;
        }
    }
    return s;
}

#endif
