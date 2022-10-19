#include <iostream>
#include "Moble.h"
#include "Magatzem.hpp"

void testEjercicio2(){
    Magatzem<Moble> magatzem = *new Magatzem<Moble>();
    Moble moble = *new Moble(1,1);
    unordered_map<int,Moble*> m;
    magatzem.afegirProducte(moble);
    magatzem.eliminarProducte(moble);
}

void testEjercicio3(){
    Magatzem<Moble> magatzem = *new Magatzem<Moble>();
    Moble moble = *new Moble(1,456.7);
    unordered_map<int,Moble*> m;
    magatzem.afegirProducte(moble);
    cout << &magatzem;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
