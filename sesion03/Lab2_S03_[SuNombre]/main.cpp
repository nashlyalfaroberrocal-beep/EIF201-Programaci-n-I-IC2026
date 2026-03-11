#include <iostream>
#include "paquetes.h"


int main()
{
	int Cantidad = 0;
	double pesos = 0;
	double LimitePeso = 0;
	double* PesoPaquetes = nullptr;

	int Paquetes =0;
	while (Paquetes <= 0)
	{
		std::cout << "Ingrese la cantidad de paquetes: ";
		std::cin >> Paquetes;

	}
	PesoPaquetes = CrearRegistro(Paquetes);

	IngresoPesos(PesoPaquetes, Cantidad);

	std::cout << "ingrese el limite de peso: ";
	std::cin >> LimitePeso;

	std::cout << "El peso total de los paquetes es: " << CalcularPesoTotal(PesoPaquetes, Cantidad) << std::endl;

	std::cout << "El paquete mas pesado pesa: " << *BuscarMasPesado(PesoPaquetes, Cantidad) << std::endl;

	delete[] PesoPaquetes;

	PesoPaquetes = nullptr;


}