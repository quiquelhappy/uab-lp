//
// Created by happy on 19/10/2022.
//

#ifndef EXAMEN1_MOBLE_H
#define EXAMEN1_MOBLE_H


class Moble
{
public:
    Moble(int codi, float volum): m_codi(codi), m_volum(volum)  {};
    ~Moble() {}
    float Volum() const { return m_volum; }
    int Codi() const { return m_codi; }
private:
    int m_codi;
    float m_volum;
};


#endif //EXAMEN1_MOBLE_H
