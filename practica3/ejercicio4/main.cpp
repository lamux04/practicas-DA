#include "ordenacion.hpp"
#include "cronometro.hpp"
#include <vector>
#include <iostream>
#include <random>

void imprimir_vector(const std::vector<int>& v)
{
    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

// int main()
// {
//     using namespace std;
//     vector<int> v = { 0, 1, 2, 3, 4, 6, 5 };

//     imprimir_vector(v);

//     ordenacion_rapida(v.begin(), v.end(), 4);

//     imprimir_vector(v);
// }

int main()
{
    using namespace std;

    default_random_engine gnp;

    for (int n = 0; n <= 1000000; n += 20000)
    {
        vector<int> v(n), w(n);
        for (int i = 0; i < n; ++i)
            v[i] = i;
        w = v;

        cronometro c1;
        c1.activar();
        for (int i = 0; i < 10; ++i)
        {
            shuffle(v.begin(), v.end(), gnp);
            ordenacion_fusion(v.begin(), v.end());
        }
        c1.parar();
        cout << n << " -> Ordenación por fusión: " << c1.tiempo() << endl;

        c1.activar();
        for (int i = 0; i < 10; ++i)
        {
            shuffle(v.begin(), v.end(), gnp);
            ordenacion_rapida(v.begin(), v.end());
        }
        c1.parar();
        cout << n << " -> Ordenación rápida: " << c1.tiempo() << endl;
    }


    return 0;
}