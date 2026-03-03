#include <iostream>
#include "Estadisticas.h"

int main()
{
	int array[10];
		std::cout << "digite 10 numeros " << std::endl;

	GetData(array, 10);

	int Mayor = GetMayor(array, 10);
	int Minor = GetMinor(array, 10);
	int Addition = CalcAddition(array, 10);
	double Average = CalcAverage(array, 10);

	std::cout << "Mayor: " << Mayor << std::endl;
	std::cout << "Menor: " << Minor << std::endl;
	std::cout << "suma" << Addition << std::endl;
	std::cout << "Promedio:" << Average << std::endl;
	return 0;
}