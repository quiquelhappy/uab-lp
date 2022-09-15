#include <iostream>

using namespace std;

#include "Poligon.h"
#include "Punt.h"

void omplirPoligon (Poligon &p)
{
    for (int i = 1; i <= p.getNCostats(); i++)
    {
        float x, y;
        cout << "Introdueix coordenades del vertex " << i << ": ";
        cin >> x >> y;
        Punt v(x,y);
        p.afegeixVertex(v);
    }
}

void mostrarPoligon(Poligon &p)
{
    for (int i = 1; i <= p.getNCostats(); i++)
    {
        Punt v;
        p.getVertex(i, v);

        cout << "Coordenades del vertex " << i << ": " << v.getX() << ", " << v.getY() << endl;
    }
    float perimetre = p.calculaPerimetre();
    cout << "El perimetre del poligon es: " << perimetre << endl;
}

int main()
{
    cout << "Introdueix el n�mero de costats del poligon: ";
    int nCostats;
    cin >> nCostats;

    Poligon p(nCostats);

    if (nCostats == p.getNCostats())
    {
        omplirPoligon(p);
        mostrarPoligon(p);

    }
    else
        cout << "ERROR" << endl;


    cout << endl << endl;
    cout << "====================================================" << endl;
    cout << "COPIA DEL POLIGON" << endl;
    Poligon pCopia(p);
    mostrarPoligon(pCopia);



    cout << endl << endl;
    cout << "====================================================" << endl;
    cout << "AASIGNACIO DEL POLIGON" << endl;
    Poligon pAssignacio;
    pAssignacio = p;
    mostrarPoligon(pAssignacio);

    return 0;
}