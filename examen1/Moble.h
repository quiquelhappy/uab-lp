//
// Created by happy on 19/10/2022.
//

#ifndef EXAMEN1_MOBLE_H
#define EXAMEN1_MOBLE_H

#include <iostream>

using namespace std;


class Moble
{
public:
    Moble(int codi, float volum): m_codi(codi), m_volum(volum)  {};
    Moble(Moble& m) = default;

    ~Moble() {}
    float Volum() const { return m_volum; }
    int Codi() const { return m_codi; }

    friend ostream& operator << (ostream out, const Moble& m) {
        out << "Codi: " << m.m_codi << ", Volum: " << m.m_volum;
        return out;
    }

private:
    int m_codi;
    float m_volum;
};


#endif //EXAMEN1_MOBLE_H
