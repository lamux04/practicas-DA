#ifndef DAMAS_HPP
#define DAMAS_HPP

#include <list>
#include <vector>
#include <iostream>

class Tablero {
public:
    explicit Tablero(int n)
        : n(n),
        columna_dama(n, n),
        columna_amenazada(n, false),
        diagonal_creciente_amenazada(2 * n - 1, false),
        diagonal_decreciente_amenazada(2 * n - 1, false)
    {
    }
    int dimension() const { return n; }
    bool amenazada(int i, int j) const;
    void coloca(int i, int j);
    void elimina(int i, int j);
    int operator [](int i) const;
    bool operator==(const Tablero& other) const {
        return columna_dama == other.columna_dama;
    }
private:
    bool valida(int k) const;
    bool valida(int i, int j) const;
    int n;
    std::vector<int> columna_dama;
    std::vector<bool>
        columna_amenazada,
        diagonal_creciente_amenazada,
        diagonal_decreciente_amenazada;
};

// ...
std::ostream& operator <<(std::ostream& fs, const Tablero& t);

std::list<Tablero> damas(Tablero& t);


#endif