#include <iostream>
#include "paquetes.h"


int main() {
    int cantidad = 0; 
    double limitePeso = 0;
    double* pesoPaquetes = nullptr;

    while (cantidad <= 0) {
        std::cout << "Ingrese la cantidad de paquetes: ";
        std::cin >> cantidad;
    }

    pesoPaquetes = CrearRegistro(cantidad);

    IngresoPesos(pesoPaquetes, cantidad);

    std::cout << "Ingrese el limite de peso: ";
    std::cin >> limitePeso;

    std::cout << "El peso total de los paquetes es: " << CalcularPesoTotal(pesoPaquetes, cantidad) << std::endl;

    const double* masPesado = BuscarMasPesado(pesoPaquetes, cantidad);
    if (masPesado != nullptr) {
        std::cout << "El paquete mas pesado pesa: " << *masPesado << std::endl;
    }

    delete[] pesoPaquetes;
    pesoPaquetes = nullptr;

    return 0;
}