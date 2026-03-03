#include <iostream>
#include "inversion.h"

int main()
{
	int size;
	std::cout<< "digite la cantidad de espacios deseados del arreglo (0-20): " << std::endl;

	std::cin >> size;
	while (size< 0 ||size > 20)
	{
		std::cout<< "incumple los parametros establecidos anteriormente (0-20). intentelo denuevo" << std::endl;
		std::cin >> size;

	}
	int original[20];
	int invert[20];

	std::cout << "ingrese los valor para el arreglo " << std::endl;
	GetData(original, size);
	InvertArray(original, invert, size);

	std::cout <<std::endl;

std::cout << "array original: ";
ShowArray(original, size);

std::cout << "array invertido: ";
ShowArray(invert, size);

return 0;
}
