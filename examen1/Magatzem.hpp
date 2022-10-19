//
// Created by happy on 19/10/2022.
//

#ifndef EXAMEN1_MAGATZEM_HPP
#define EXAMEN1_MAGATZEM_HPP

#include <iostream>

using namespace std;

class Magatzem {
public:
    Magatzem(float capacitat = 10000): m_capacitat(capacitat) {};
    ~Magatzem();

    void afegirProducte(A& m);
    void eliminarProducte(A& m);

    friend ostream& operator << (ostream out, const Magatzem & m) {
        out << "Magatzem: " << endl;
        for (auto it = m.m_contingut.begin(); it != m.m_contingut.end(); it++) {
            out << "Producte: " << ( * (it -> second)) << endl;
        }
        return out;
    }

private:
    unordered_map <int, A*> m_contingut;
    float m_capacitat;
};

void Magatzem::afegirProducte(A& m) {
    if (m_capacitat + m.Volum() >= 0) {
        m_contingut[m.Codi()] = new A(m);
    }
}

void Magatzem::eliminarProducte(A& m) {
    for (auto it = m_contingut.begin(); it < m_contingut.end(); it++) {
        if (it -> first == m.Codi()) {
            delete(it -> second);
            m_contingut.erase(it);
        }
    }
}

Magatzem::~Magatzem() {
    for (auto it = m_contingut.begin(); it != m_contingut.end(); ++it) {
        delete(it -> second);
    }
}

#endif //EXAMEN1_MAGATZEM_HPP
