#include "Poligon.h"
#include <math.h>

Poligon::Poligon()
{
    m_nCostats = MIN_COSTATS;
    m_nVertexs = 0;

}

Poligon::~Poligon()
{

}

Poligon::Poligon(int nCostats)
{
    if ((nCostats >= MIN_COSTATS) && (nCostats <= MAX_COSTATS))
        m_nCostats = nCostats;
    else
        m_nCostats = MIN_COSTATS;
    m_nVertexs = 0;
}

bool Poligon::afegeixVertex(const Punt &v)
{
    bool correcte = false;
    if (m_nVertexs < m_nCostats)
    {
        m_vertexs[m_nVertexs] = v;
        m_nVertexs++;
        correcte = true;
    }
    return correcte;
}

bool Poligon::getVertex(int nVertex, Punt &v) const
{
    bool correcte = false;
    if ((nVertex > 0) && (nVertex <= m_nCostats))
    {
        v = m_vertexs[nVertex - 1];
        correcte = true;
    }
    return correcte;
}

float Poligon::calculaPerimetre() const
{
    float perimetre = 0;
    float dx, dy;
    for (int i = 0; i < m_nCostats - 1; i++)
    {
        dx = m_vertexs[i].getX() - m_vertexs[i+1].getX();
        dy = m_vertexs[i].getY() - m_vertexs[i+1].getY();
        perimetre += sqrt(dx*dx + dy*dy);
    }
    dx = m_vertexs[m_nCostats - 1].getX() - m_vertexs[0].getX();
    dy = m_vertexs[m_nCostats - 1].getY() - m_vertexs[0].getY();
    perimetre += sqrt(dx*dx + dy*dy);

    return perimetre;
}