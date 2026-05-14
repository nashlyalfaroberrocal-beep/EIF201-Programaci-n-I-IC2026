#include "Cancion.h"

EIF::Cancion::Cancion(const std::string name, int duration, std::string genero, int numRepro)
	: Contenido(name, duration), genero(genero), numRepro(numRepro)
{}



EIF::Cancion::~Cancion()
{
}

double EIF::Cancion::calcularRegalias() const
{

	double regalias = numRepro * 3.5;
	double multGenero = 0;
	if (genero == "JazZZ" || genero == "Clasica") {
		multGenero = 1.4;
	}
	else if (genero == "Pop" || genero == "Indie") {
		multGenero = 1.0;
	}
	else if (genero == "Pop" || genero == "Electronica") {
		multGenero = 0.9;
	}
	else if (genero == "Reggeton" || genero == "Urbano") {
		multGenero = 0.75;
	}

	regalias* multGenero;

	if (numRepro > 1000000) {
		regalias *= 1.25;
	}

	if (duration == 240) {
		regalias *= 1.15;
	}

	return regalias;
}

std::string EIF::Cancion::getTipo() const
{
	return "cacncion";
}

int EIF::Cancion::getNivelPopularidad() const
{
	if (numRepro > 100)return 1;
	else if (numRepro > 500)return 2;
	else if (numRepro > 1000)return 3;
	else if (numRepro > 2000)return 4;
	else if (numRepro > 3000)return 5;
	else if (numRepro > 4000)return 6;
	else if (numRepro > 5000)return 7;
	else if (numRepro > 6000)return 8;
	else if (numRepro > 7000)return 9;
	else if (numRepro > 8000)return 10;
	

	return 0;
}
