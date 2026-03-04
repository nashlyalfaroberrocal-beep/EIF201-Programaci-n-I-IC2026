#include <iostream>
#include <string>
#include "Nombre.h"

int main(){
    std::string Name;

    std::cout << "Ingrese su nombre completo: ";
    std::getline(std::cin,Name);

    NameProcess(Name);
    return 0;
}