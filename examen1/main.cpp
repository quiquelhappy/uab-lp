#include <iostream>

void testEjercicio2(){
    Magatzem<Moble> magatzem = *new Magatzem<Moble>();
    Moble moble = *new Moble(1,1);
    unordered_map<int,Moble*> m;
    magatzem.afegirProducte(moble);
    magatzem.eliminarProducte(moble);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
