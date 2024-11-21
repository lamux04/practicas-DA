#include <iostream>
#include <vector>
#include <bitset>

int log(int n, int b)
{
    if (n < b)
        return 0;
    else
        return log(n / b, b) + 1;
}

int main()
{
    using namespace std;

    // Creamos la matriz vacia

    vector<vector<int>> matriz(64, vector<int>(4, 0));

    for (int i = 0; i < 64; ++i)
    {
        // Rellenamos la primera columna
        matriz[i][0] = i + 1;

        // Rellenamos el logaritmo
        matriz[i][1] = log(matriz[i][0], 2);

        // Número binario
        matriz[i][2] = i + 1;

        // Productos
        if (i == 0) matriz[0][3] = 0;
        else
            if ((i + 1) % 2 == 0)
                matriz[i][3] = matriz[i][1];
            else
                matriz[i][3] = log(i + 2, 2) * 2 - 2;
    }

    cout << "n\tlogn\tBinario\tProducto" << endl;
    for (int i = 0; i < 64; ++i)
    {
        cout << matriz[i][0] << '\t' << matriz[i][1] << '\t' << bitset<8>(matriz[i][2]) << '\t' << matriz[i][3] << endl;
    }


    return 0;
}