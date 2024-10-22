#include <iostream>
#include "natural.hpp"
#include "cronometro.hpp"
#include "math.h"

natural f(natural n);

// Genera la tabla de tiempos frente a n.

int main()
{
    natural a = 0, b = 1, n = 0;
    while (n < 93) {
        const natural c = a + b;
        a = b;
        b = c;
        std::cout << c << std::endl;
        n++;
    }
}
