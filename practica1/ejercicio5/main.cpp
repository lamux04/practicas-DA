#include <fstream>
#include "cronometro.hpp"
#include "grafo-ponderado.hpp"

int main()
{
    using namespace std;
    cronometro c1, c2;
    GrafoPonderado<int> G;
    ifstream datos("grafo.dat");
    datos >> G;

    c1.activar();
    for (int i = 0; i < 100000; ++i)
    {
        Kruskal1<GrafoPonderado<int, double>>(G);
    }
    c1.parar();
    cout << "Usando preordenacion: " << c1.tiempo() << endl;

    c2.activar();
    for (int i = 0; i < 100000; ++i)
    {
        Kruskal2<GrafoPonderado<int, double>>(G);
    }
    c2.parar();
    cout << "Usando monticulos: " << c2.tiempo() << endl;
}