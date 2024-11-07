#include <fstream>
#include <iostream>
#include "mochila.hpp"

int main()
{
    using namespace std;
    Objetos obs;
    ifstream datos("objetos.dat");
    datos >> obs;
    cout << obs;
    cout << "------------------------" << endl;
    obs = mochila(obs, 50);
    cout << obs;

    return 0;
}