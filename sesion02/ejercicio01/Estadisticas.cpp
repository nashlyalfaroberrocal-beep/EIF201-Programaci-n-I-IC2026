#include <iostream>
#include "Estadisticas.h"

void GetData(int array[], int size){
	for (int i =0 ;i < size; i++)
	{
		std::cout << ": ";
		std::cin >> array[i];

	}
}

int GetMayor(int array[], int size) {
	int Mayor = array[0];

	for(int i = 1;i < size;i++) {
		if (array[i] > Mayor) {
			Mayor = array[i];

		}
	}
	return Mayor;
}
int GetMinor(int array[], int size) {
	int Minor = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] < Minor) {
			Minor = array[i];
		}
	}
	return Minor;
}
int CalcAddition(int array[],int size) {
	int Addition = 0;

	for (int i = 0; i < size; i++) {
		Addition = Addition + array[i];
	}
	return Addition;
}
double CalcAverage(int array[], int size) {
	int Addition = CalcAddition(array, size);
	double Average = (double)Addition / size;
	return Average;
}