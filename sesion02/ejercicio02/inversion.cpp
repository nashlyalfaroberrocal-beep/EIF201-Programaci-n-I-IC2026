
#include <iostream>
#include "inversion.h"

void GetData(int array[], int size)
{
	for (int i= 0;i <size; i++)
	{
		std::cout << "digite los valores: " << std::endl;
		std::cin >> array[i];
	}

}
void InvertArray(int original[],int invert[],int size)
{
	for (int i = 0; i< size;i++)
	{
		invert[i] = original[size - 1 - i];

	}
}
void ShowArray(int array[],int size)
{
	for (int i= 0;i<size; i++)
	{
		std::cout<< array[i]<< " ";
	}
	std::cout<< std::endl;
}