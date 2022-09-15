#ifndef POLIGON_H
#define POLIGON_H

#include <forward_list>
#include "Punt.h"

class Poligon
{
public:
    Poligon();
    ~Poligon();
    Poligon(int nCostats);
    Poligon(const Poligon& p);
    Poligon& operator=(const Poligon& p);

    int getNCostats() const { return m_nCostats; };
    bool afegeixVertex(const Punt &v);
    bool getVertex(int nVertex, Punt &v) const;
    float calculaPerimetre() const;
private:
    static const int MIN_COSTATS = 3;
    std::forward_list<Punt> m_vertexs;
    std::forward_list<Punt>::iterator m_ultimVertex;
    int m_nCostats;
    int m_nVertexs;
};

#endif // POLIGON_H