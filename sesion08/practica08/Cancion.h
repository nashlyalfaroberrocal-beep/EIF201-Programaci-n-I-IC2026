#ifndef CANCION_H
#define CANCION_H 
#include "Contenido.h"
#include <string>
#include <sstream>

namespace EIF {
	class Cancion : public Contenido
	{
	private:
		std::string genero;
		int numRepro;

	public:
		Cancion(const std::string name, int duration, std::string genero, int numRepro);
		virtual ~Cancion();

		double calcularRegalias() const override;
		std::string getTipo() const override;
		int getNivelPopularidad() const override;

	};
}


#endif