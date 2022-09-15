#include "Poligon.h"
#include <math.h>

Poligon::Poligon()
{
    m_nCostats = MIN_COSTATS;
    m_nVertexs = 0;
    m_ultimVertex = m_vertexs.before_begin();
}

Poligon::~Poligon()
{

}

Poligon::Poligon(int nCostats)
{
    if (nCostats > MIN_COSTATS)
        m_nCostats = nCostats;
    else
        m_nCostats = MIN_COSTATS;
    m_nVertexs = 0;
    m_ultimVertex = m_vertexs.before_begin();
}


bool Poligon::afegeixVertex(const Punt &v)
{
    bool correcte = false;
    if (m_nVertexs < m_nCostats)
    {
        correcte = true;
        m_ultimVertex = m_vertexs.insert_after(m_ultimVertex, v);
        m_nVertexs++;
    }
    return correcte;
}

bool Poligon::getVertex(int nVertex, Punt &v) const
{
    bool correcte = false;
    if (nVertex > 0 && nVertex <= m_nVertexs)
    {
        std::forward_list<Punt>::const_iterator aux = m_vertexs.begin();
        for (int i = 1; i < nVertex; i++)
            aux++;
        v = *aux;
        correcte = true;
    }
    return correcte;
}

float Poligon::calculaPerimetre() const
{
    float perimetre = 0;
    float dx, dy;
    std::forward_list<Punt>::const_iterator aux = m_vertexs.begin();
    std::forward_list<Punt>::const_iterator ant;
    for (int i = 0; i < (m_nCostats - 1); i++)
    {
        ant = aux;
        aux++;
        dx = ant->getX() - aux->getX();
        dy = ant->getY() - aux->getY();
        perimetre += sqrt(dx*dx + dy*dy);
    }
    dx = aux->getX() - m_vertexs.begin()->getX();
    dy = aux->getY() - m_vertexs.begin()->getY();
    perimetre += sqrt(dx*dx + dy*dy);
    return perimetre;
}

Poligon& Poligon::operator=(const Poligon& p)
{
    if (this != &p)
    {
        m_nCostats = p.m_nCostats;
        m_nVertexs = p.m_nVertexs;
        m_vertexs = p.m_vertexs;
        m_ultimVertex = m_vertexs.before_begin();
        std::forward_list<Punt>::iterator it;
        for (it = m_vertexs.begin(); it != m_vertexs.end(); it++)
            m_ultimVertex++;
    }
    return *this;
}

Poligon::Poligon(const Poligon &p)
{
    *this = p;
}
