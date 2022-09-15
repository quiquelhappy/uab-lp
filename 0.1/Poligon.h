#ifndef POLIGON_H
#define POLIGON_H

#include "Punt.h"

class Poligon
{
public:
    Poligon();
    ~Poligon();
    Poligon(int nCostats);

    int getNCostats() const { return m_nCostats; };
    bool afegeixVertex(const Punt &v);
    bool getVertex(int nVertex, Punt &v) const;
    float calculaPerimetre() const;
private:
    static const int MAX_COSTATS = 30;
    static const int MIN_COSTATS = 3;
    Punt m_vertexs[MAX_COSTATS];
    int m_nCostats;
    int m_nVertexs;
};

#endif // POLIGON_H