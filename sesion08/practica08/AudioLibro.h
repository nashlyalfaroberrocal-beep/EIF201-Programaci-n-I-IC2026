#ifndef AUDIOLIBRO_H
#define AUDIOLIBRO_H
#include "Contenido.h"


namespace EIF201 {

	class AudioLibro : public Contenido
	{
	private:
		int numCapitulos;
		int precio;
		int unidades;


	public:
		AudioLibro(const std::string name, int duration, int numCapitulos, int precio, int unidades);
		virtual ~AudioLibro();

		double calcularRegalias() const override;
		std::string getTipo() const override;
		int getNivelPopularidad() const override;



	};

}

#endif

