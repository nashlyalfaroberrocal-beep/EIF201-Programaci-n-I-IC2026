#include "paquetes.h"
#include <iostream>

double* CrearRegistro(int& cantidad) {
    
    return new double[cantidad];
}

void IngresoPesos(double* pesos, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        std::cout << "Ingrese el peso del paquete " << (i + 1) << ": ";
        std::cin >> pesos[i];
    }
}

double CalcularPesoTotal(double* pesos, int cantidad) {
    double total = 0.0;
    for (int i = 0; i < cantidad; ++i) {
        total += pesos[i];
    }
    return total;
}

int ContarSobreLimite(const double* pesos, int cantidad, double limite) {
    int contador = 0;
    for (int i = 0; i < cantidad; ++i) {
        if (pesos[i] > limite) {
            contador++;
        }
    }
    return contador; 
}

const double* BuscarMasPesado(const double* pesos, int cantidad) {
    if (cantidad <= 0) return nullptr;

    const double* masPesado = &pesos[0];
    for (int i = 1; i < cantidad; ++i) {
        if (pesos[i] > *masPesado) {
            masPesado = &pesos[i];
        }
    }
    return masPesado;
}