#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <iterator>
#include "matrices.hpp"

struct arista
{
    std::string origen, destino;
    double peso;
};

std::istream& operator>> (std::istream& fe, arista& a)
{
    return fe >> a.origen >> a.destino >> a.peso;
}

int main()
{
    using namespace std;

    // Abre el fichero, que se cargará en dos pasadas.
    ifstream dgt("dgt.dat");
    // 1ª pasada: codifica las ciudades y obtiene el número de vértices.
    map<string, size_t> codigo; // Código asociado a una ciudad.
    map<size_t, string> ciudad; // Ciudad asociada a un código.
    string origen, destino; // Ciudades de origen y destino.
    double distancia; // Distancia entre ambas.
    size_t n = 0; // Número de ciudades.
    // ... lee las ciudades (el peso se desecha) y las codifica.
    // ... los códigos serán correlativos (0, 1, ...) para cada nueva ciudad.

    std::istream_iterator<arista> ife(dgt), fin;
    for (std::istream_iterator<arista> p = ife; p != fin; p++)
    {
        arista a = *p;

        if (codigo.find(a.origen) == codigo.end())
        {
            codigo.insert(make_pair(a.origen, n));
            ciudad.insert(make_pair(n, a.origen));
            n++;
        }
        if (codigo.find(a.destino) == codigo.end())
        {
            codigo.insert(make_pair(a.destino, n));
            ciudad.insert(make_pair(n, a.destino));
            n++;
        }
    }

    // 2ª pasada: obtiene la matriz de pesos.
    MatrizPesos p(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            p[i][j] = MatrizPesos::infinito;
    dgt.close();
    dgt.clear();
    dgt.open("dgt.dat");

    std::istream_iterator<arista> ife2(dgt), fin2;
    for (std::istream_iterator<arista> pos = ife2; pos != fin2; pos++)
    {
        arista a = *pos;
        size_t i = codigo.find(a.origen)->second;
        size_t j = codigo.find(a.destino)->second;

        p[i][j] = a.peso;
        p[j][i] = a.peso;
    }
    // Calcula los caminos mínimos.

    MatrizCaminos c = Floyd(p);
    // Responde a las consultas.
    // ... solicita el origen y el destino.

    cout << "Origen: ";
    cin >> origen;
    cout << "Destino: ";
    cin >> destino;


    // ... comprueba las situaciones excepcionales.

    if (codigo.find(origen) == codigo.end() || codigo.find(destino) == codigo.end())
    {
        cout << "La ciudad origen o destino no esta contemplada";
    }
    else
    {
        size_t i = codigo.find(origen)->second;
        size_t j = codigo.find(destino)->second;

        cout << i << " " << j << " " << endl;

        if (p[i][j] == MatrizPesos::infinito)
            cout << "No hay camino entre origen y destino";
        else
        {
            // ... obtiene el camino mínimo codificado.
            Camino cam = CaminoMinimo(c, i, j);
            // ... muestra la longitud de la ruta y las ciudades que la integran.

            cout << "La ruta mas corta (" << p[i][j] << "km) es:" << endl;

            for (auto city : cam)
                cout << ciudad.find(city)->second << " ";

            cout << endl;
        }
    }

    cout << endl;

    return 0;
}