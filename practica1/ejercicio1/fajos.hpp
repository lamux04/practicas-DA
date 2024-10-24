#ifndef FAJOS_HPP
#define FAJOS_HPP

#include <vector>
#include <iostream>

class fajo {
public:
    fajo() : v{ 0 }, u{ 0 } {}
    fajo(unsigned int v, unsigned int u) : v{ v }, u{ u } {}
    unsigned int valor() const { return v; }
    unsigned int& valor() { return v; }
    unsigned int unidades() const { return u; }
    unsigned int& unidades() { return u; }
private:
    unsigned int v, u; // Valor y número de unidades de cada billete.
};

inline bool operator < (const fajo& a, const fajo& b)
{
    return a.valor() < b.valor();
}

using fajos = std::vector<fajo>;

std::istream& operator >>(std::istream& fe, fajo& f);
std::istream& operator >>(std::istream& fe, fajos& f);
std::ostream& operator <<(std::ostream& fs, const fajo& f);
std::ostream& operator <<(std::ostream& fs, const fajos& f);

fajos reintegrar(const fajos& caja, unsigned int cantidad);

#endif