#ifndef MOCHILA_HPP
#define MOCHILA_HPP

#include <string>
#include <vector>
#include <iostream>

class Objeto
{
public:
    Objeto(std::string n = "", int p = 0, int v = 0) : n(n), p(p), v(v) {}
    const std::string& nombre() const { return n; }
    std::string& nombre() { return n; }
    int valor() const { return v; }
    int& valor() { return v; }
    int peso() const { return p; }
    int& peso() { return p; }

private:
    std::string n;
    int p, v;
};

using Objetos = std::vector<Objeto>;

std::istream& operator>> (std::istream& fe, Objeto& o);
std::istream& operator>> (std::istream& fe, Objetos& obs);
std::ostream& operator<< (std::ostream& fe, const Objeto& o);
std::ostream& operator<< (std::ostream& fe, const Objetos& obs);


Objetos mochila(const Objetos& objetos, unsigned int capacidad);

#endif