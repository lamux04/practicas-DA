#include <fstream>
#include "grafo-ponderado.hpp"

int main()
{
    using namespace std;
    GrafoPonderado<int> G;
    ifstream datos("grafo.dat");
    datos >> G;
    cout << G;
    cout << Kruskal<GrafoPonderado<int, double>>(G);
}