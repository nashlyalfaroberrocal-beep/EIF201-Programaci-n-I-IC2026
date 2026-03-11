#include <iostream>
#include "paquetes.h"


int main() {
    int cantidad = 0; // Let's use one consistent variable
    double limitePeso = 0;
    double* pesoPaquetes = nullptr;

    // 1. Get the quantity
    while (cantidad <= 0) {
        std::cout << "Ingrese la cantidad de paquetes: ";
        std::cin >> cantidad;
    }

    // 2. Allocate memory
    pesoPaquetes = CrearRegistro(cantidad);

    // 3. Fill the array (Pass 'cantidad', not a zeroed variable)
    IngresoPesos(pesoPaquetes, cantidad);

    // 4. Get the limit and perform calculations
    std::cout << "Ingrese el limite de peso: ";
    std::cin >> limitePeso;

    std::cout << "El peso total de los paquetes es: " << CalcularPesoTotal(pesoPaquetes, cantidad) << std::endl;

    // Note: We should check if the pointer is null before dereferencing it with '*'
    const double* masPesado = BuscarMasPesado(pesoPaquetes, cantidad);
    if (masPesado != nullptr) {
        std::cout << "El paquete mas pesado pesa: " << *masPesado << std::endl;
    }

    // 5. Cleanup
    delete[] pesoPaquetes;
    pesoPaquetes = nullptr;

    return 0;
}