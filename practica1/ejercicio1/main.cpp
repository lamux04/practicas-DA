#include "fajos.hpp"
#include <fstream>
#include <iostream>

int main()
{
    using namespace std;
    ifstream datos("caja.dat");
    fajos caja;
    datos >> caja;
    fajos reintegro = reintegrar(caja, 2000);
    cout << reintegro;
    return 0;
}