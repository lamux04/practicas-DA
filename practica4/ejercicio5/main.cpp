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
    bool solucion = damas_solucion(t);

    std::cout << t;
    return 0;
}