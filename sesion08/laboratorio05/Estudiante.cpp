#include "Estudiante.h"
#include <iostream>
#include <iomanip>
namespace EIF201 {

	Estudiante::Estudiante(const std::string& nombre, const std::string& carnet, double nota)
		: carnet(carnet), nota(nota), nombre(nombre) {
	}


	Estudiante::~Estudiante()
	{
	}


	std::string Estudiante::getNombre()const
	{
		return nombre;
	}

	std::string Estudiante::getCarnet() const
	{
		return carnet;
	}

	double Estudiante::getNota() const
	{
		return nota;
	}

	void Estudiante::setNota(double nota)
	{
		this->nota = nota;
	}


	void Estudiante::mostrar() const
	{
		std::cout << "carnet: " << carnet
			<< " nombre: " << nombre
			<< " nota: " << std::fixed << std::setprecision 
			(1) << nota << std::endl;
	}
	


}
