#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
#include "fajos.hpp"

std::istream& operator >>(std::istream& fe, fajo& f)
{
    return fe >> f.valor() >> f.unidades();
}
std::istream& operator >>(std::istream& fe, fajos& f)
{
    using namespace std;
    istream_iterator<fajo> ife(fe), fin;
    copy(ife, fin, back_inserter(f));
    return fe;
}
std::ostream& operator <<(std::ostream& fs, const fajo& f)
{
    return fs << f.unidades() << " billete" << (f.unidades() == 1 ? "" : "s") << " de " << f.valor();
}

std::ostream& operator <<(std::ostream& fs, const fajos& f)
{
    using namespace std;
    copy(begin(f), end(f), ostream_iterator<fajo>(fs, "\n"));
    return fs;
}

fajos reintegrar(const fajos& caja, unsigned int cantidad)
{
    fajos reintegro;
    std::priority_queue<fajo> cfajos(caja.begin(), caja.end());
    while (cantidad > 0 && !cfajos.empty())
    {
        fajo f = cfajos.top();
        cfajos.pop();
        if (cantidad / f.valor() < f.unidades())
            f.unidades() = cantidad / f.valor();
        cantidad -= f.unidades() * f.valor();
        if (f.unidades() > 0)
            reintegro.push_back(f);
    }
    if (cantidad > 0)
        reintegro = fajos{};
    return reintegro;
}