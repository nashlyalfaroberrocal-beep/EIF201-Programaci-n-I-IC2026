#include "paquetes.h"
#include <iostream>
#include <iomanip>

double* CrearRegistro(int& cantidad)
{
	double* Paquetes = new double[cantidad];
	return Paquetes;
}

void IngresoPesos(double* pesos, int cantidad)
{
	for (int i = 0; i < cantidad; ++i) {
		std::cout << "Ingrese el peso del paquete " << (i + 1) << ": ";
		std::cin >> pesos[i];
	}
}


double CalcularPesoTotal(double* pesos, int cantidad)
{
	double total = 0.0;
	for (int i = 0; i < cantidad; ++i) {
		total = pesos[i] + total;

	}
	return 0.0;
}



int ContarSobreLimite(const double* pesos, int cantidad, double limite)
{
	int contador = 0;
	for (int i = 0; i < cantidad; ++i) {
		if (pesos[i] > limite){
			contador++; }
	}
	return 0;
}



const double* BuscarMasPesado(const double* pesos, int cantidad)
{
	for (int i = 0; i < cantidad; ++i) {
		if (pesos[i] > pesos[i + 1]){
			return &pesos[i]; }
	}
	return nullptr;
}
