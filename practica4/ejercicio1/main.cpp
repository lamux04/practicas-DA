#include <iostream>
#include "damas.hpp"

int main()
{
    using namespace std;
    Tablero t(8);
    std::list<Tablero> soluciones = damas(t);

    std::cout << "SOLUCIONES:" << endl;
    for (auto i : soluciones)
        cout << i << endl;
    std::cout << soluciones.size() << endl;
    return 0;
}