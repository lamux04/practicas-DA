#include <iostream>
#include "matriz.hpp"
#include "cronometro.hpp"
using namespace std;

// Inserción de una matriz en un flujo de salida.

ostream& operator <<(ostream& fs, matriz& a)
{
    for (size_t i = 0; i < a.filas(); ++i) {
        for (size_t j = 0; j < a.columnas(); ++j)
            fs << a[i][j] << ' ';
        fs << '\n';
    }
    return fs;
}

// Función delta de Kronecker.

inline double delta(size_t i, size_t j)
{
    return i == j;
}

// Potencia iterativa

matriz potencia_iterativa(matriz A, int n)
{
    matriz resultado = matriz(A.filas(), A.columnas(), delta);
    for (int i = 0; i < n; ++i)
        resultado *= A;
    return resultado;
}

// Potencia rápida

matriz potencia_rapida(matriz A, int n)
{
    if (n == 0)
        return matriz(A.filas(), A.columnas(), delta);
    else
    {
        if (n == 1)
            return A;
        else
        {
            if (n % 2 == 0)
                return potencia_rapida(A * A, n / 2);
            else
                return A * potencia_rapida(A, n - 1);
        }
    }
}

// Prueba.

int main()
{
    using namespace std;
    cout << "n\titerativa\trapida" << endl;
    cronometro c1, c2;

    for (int i = 0; i <= 64; ++i)
    {
        cout << i << '\t';
        c1.activar();
        potencia_iterativa(matriz(100, 100, delta), i);
        c1.parar();
        cout << c1.tiempo() << '\t';
        c2.activar();
        potencia_rapida(matriz(100, 100, delta), i);
        c2.parar();
        cout << c2.tiempo() << endl;
    }

    return 0;
}
