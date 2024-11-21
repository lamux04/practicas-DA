#ifndef MATRICES_HPP
#define MATRICES_HPP

#include <stddef.h>
#include <list>
#include <vector>
#include <limits>

template <typename T>
class MatrizCuadrada
{
public:
    MatrizCuadrada(size_t n) : n(n), matriz(n, std::vector<T>(n, T())) {}
    size_t size() { return n; }
    std::vector<T>& operator[] (size_t i) { return matriz[i]; }
    const std::vector<T>& operator[] (size_t i) const { return matriz[i]; }

private:
    std::vector<std::vector<T>> matriz;
    size_t n;
};

class MatrizPesos : public MatrizCuadrada<double>
{
public:
    static constexpr double infinito = std::numeric_limits<double>::infinity();
    MatrizPesos(size_t n) : MatrizCuadrada<double>(n) {}
};

using MatrizCaminos = MatrizCuadrada<size_t>;
using Camino = std::list<size_t>;

MatrizCaminos Floyd(MatrizPesos& p);
Camino CaminoMinimo(const MatrizCaminos& c, size_t i, size_t j);

#endif