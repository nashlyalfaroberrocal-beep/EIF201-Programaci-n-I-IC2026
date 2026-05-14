#include "AudioLibro.h"

namespace EIF201 {
	AudioLibro::AudioLibro(const std::string name, int duration, int numCapitulos, int precio, int unidades)
		: Contenido(name, duration), numCapitulos(numCapitulos), precio(precio), unidades(unidades)
	{}

	

	double AudioLibro::calcularRegalias() const
	{
		int tasa = 0.25;
		double regalias = precio * tasa * unidades;

		if (duration > 36000) {
			regalias *= 1.30;
		}

		if (precio > 1000) {
			regalias *= 1.12;
		}

		if (numCapitulos > 20) {
			regalias *= 1.08;
		}

		return regalias;
	}

	std::string AudioLibro::getTipo() const
	{
		if (numCapitulos > 10) return "Audio Libro de tasa premium";
		if (numCapitulos > 20) return "obra densa";
		else return "Audio Libro";
	}

	int AudioLibro::getNivelPopularidad() const
	{
		if (unidades > 10) return 1;
		else if (unidades > 50) return 2;
		else if (unidades > 100) return 3;
		else if (unidades > 500) return 4;
		
	}

	AudioLibro::~AudioLibro()
	{
	}

}
