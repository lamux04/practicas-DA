#ifndef PARTICION_HPP
#define PARTICION_HPP

#include <vector>

class Particion {
public:
    Particion(int n);
    int buscar(int i) const;
    void unir(int i, int j);
private:
    mutable std::vector<int> p;
};

#endif