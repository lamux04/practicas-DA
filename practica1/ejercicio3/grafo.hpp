#ifndef GRAFO_HPP_
#define GRAFO_HPP_

#include <list>
#include <iostream>
#include <iterator>



// Arista.

template <typename V>
class Arista {
public:
    using Vertice = V;
    Arista(Vertice u, Vertice v) : u{ u }, v{ v } {}
    Vertice primero() const { return u; }
    Vertice segundo() const { return v; }
    Vertice& primero() { return u; }
    Vertice& segundo() { return v; }
private:
    Vertice u, v;
};

// Grafo.

template <typename V, typename A = Arista<V>>
class Grafo {
public:
    using Vertice = V;
    using Arista = A;
    using Aristas = std::list<Arista>;
    Grafo(size_t n = 0) : n{ n } {}
    size_t nVertices() const { return n; }
    const Aristas& aristas() const { return a; }
    void insertarArista(const Arista& u) { a.push_back(u); }
private:
    size_t n;
    Aristas a;
};

template <typename V, typename A>
std::istream& operator>>(std::istream& fe, Grafo<V, A>& g)
{
    using namespace std;
    size_t n = 0;
    fe >> n;
    g = Grafo<V, A>(n);
    V u{}, v{};
    A a(u, v);
    while (fe >> a)
        g.insertarArista(a);
    return fe;
}

template <typename V, typename A>
std::ostream& operator <<(std::ostream& fs, const Grafo<V, A>& g)
{
    using namespace std;
    fs << g.nVertices() << '\n';
    auto& a = g.aristas();
    copy(begin(a), end(a), ostream_iterator<A>(fs, "\n"));
    return fs << flush;
}

#endif
