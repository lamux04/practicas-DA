#include <iostream>
#include <charconv>
#include <cstring>
#include "damas.hpp"

int main(int argc, char* argv[])
{
    using namespace std;
    const char* input = argv[1];
    int n;
    from_chars(input, input + std::strlen(input), n);
    Tablero t(n);
    std::list<Tablero> soluciones = damas(t);

    std::cout << "SOLUCIONES:" << endl;
    for (auto i : soluciones)
        cout << i << endl;
    std::cout << soluciones.size() << endl;
    return 0;
}