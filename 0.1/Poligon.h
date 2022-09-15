#ifndef POLIGON_H
#define POLIGON_H

#include "Punt.h"
#include "Node.h"

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
    static const int MAX_COSTATS = 30;
    static const int MIN_COSTATS = 3;
    Node* m_vertexs;
    Node* m_ultimVertex;
    int m_nCostats;
    int m_nVertexs;
};

#endif // POLIGON_H