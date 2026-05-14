#include "Podcast.h"



EIF201::Podcast::Podcast(const std::string name, int duration, int numEpisodios, bool Patrocinio, int oyentes)
: Contenido(name, duration), numEpisodios(numEpisodios), Patrocinio(Patrocinio), oyentes(oyentes)
{}



double EIF201::Podcast::calcularRegalias() const
{
    double regalias = numEpisodios * 1500 * (oyentes / 1000);
    if (Patrocinio) {
        regalias *= 1.45;
    }

    if (numEpisodios > 50) {
		regalias *= 1.18;
    }

    if (duration < 900) {
        regalias *= 0.80;
    }
    
    return regalias;
}

std::string EIF201::Podcast::getTipo() const
{
	if (numEpisodios > 50) return "Podcast veterano";
    else return "Podcast";
}

int EIF201::Podcast::getNivelPopularidad() const
{
    if (oyentes > 100) return 1;
    else if (oyentes > 500) return 2;
    else if (oyentes > 1000) return 3;
    return 4;

}


EIF201::Podcast::~Podcast()
{
}