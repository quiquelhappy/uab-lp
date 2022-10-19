//
// Created by happy on 19/10/2022.
//

#ifndef EXAMEN1_VEHICLE_H
#define EXAMEN1_VEHICLE_H

#include <iostream>

using namespace std;

class Vehicle {
public:
    Vehicle(const string & matricula,
            const string & marca, bool disponible):
            m_matricula(matricula), m_marca(marca), m_disponible(disponible),
            m_taxaFixa(10) {};
    ~Vehicle();
    void setMatricula(const string & matricula) {
        m_matricula = matricula;
    };
    string getMatricula() const {
        return m_matricula;
    };
    void setMarca(const string & marca) {
        m_marca = marca;
    };
    string getMarca() const {
        return m_marca;
    };
    void setDisponible(bool disponible) {
        m_disponible = disponible;
    };
    bool getDisponible() const {
        return m_disponible;
    };
    void setTaxaFixa(float taxaFixa) {
        m_taxaFixa = taxaFixa;
    };
    float getPreu() const;
private:
    string m_matricula;
    string m_marca;
    bool m_disponible;
    float m_taxaFixa;
};

#endif //EXAMEN1_VEHICLE_H