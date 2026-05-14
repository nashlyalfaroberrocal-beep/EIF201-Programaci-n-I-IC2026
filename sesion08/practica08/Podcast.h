#ifndef PODCAST_H
#define PODCAST_H
#include "Contenido.h"

namespace EIF201 {
	class Podcast : public Contenido
	{
	private:
		int numEpisodios;
		bool Patrocinio;
		int oyentes;
		

	public:
		Podcast(const std:: string name, int duration, int numEpisodios, bool Patrocinio, int oyentes);
		virtual ~Podcast();

		double calcularRegalias() const override;
		std::string getTipo() const override;
		int getNivelPopularidad() const override;


	};
}

#endif

