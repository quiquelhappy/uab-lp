//
// Created by happy on 19/10/2022.
//

#ifndef EXAMEN1_MAGATZEM_HPP
#define EXAMEN1_MAGATZEM_HPP

#include <iostream>
#include <unordered_map> // obviate

using namespace std;

template<class T>
class Magatzem {
public:
    Magatzem(float capacitat = 10000): m_capacitat(capacitat) {};
    ~Magatzem();

    void afegirProducte(T& m);
    void eliminarProducte(T& m);

    friend ostream& operator << (ostream out, const Magatzem & m) {
        out << "Magatzem: " << endl;
        for (auto it = m.m_contingut.begin(); it != m.m_contingut.end(); it++) {
            out << "Producte: " << ( * (it -> second)) << endl;
        }
        return out;
    }

private:
    unordered_map<int, T*> m_contingut;
    float m_capacitat;
};

template <class T>
void Magatzem<T>::afegirProducte(T& m) {
    if (m_capacitat + m.Volum() >= 0) {
        m_contingut[m.Codi()] = new T(m);
    }
}

template <class T>
void Magatzem<T>::eliminarProducte(T& m) {
    for (auto it = m_contingut.begin(); it != m_contingut.end(); it++) {
        if (it -> first == m.Codi()) {
            delete(it -> second);
            m_contingut.erase(it);
        }
    }
}

template <class T>
Magatzem<T>::~Magatzem() {
    for (auto it = m_contingut.begin(); it != m_contingut.end(); ++it) {
        delete(it -> second);
    }
}

#endif //EXAMEN1_MAGATZEM_HPP
