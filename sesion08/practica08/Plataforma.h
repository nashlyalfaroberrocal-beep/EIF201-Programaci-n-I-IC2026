#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Contenido.h"
#include <string>

namespace EIF201 {
	class Plataforma
	{
	private:
		Contenido** contenidos;
		int capacidad;
		int cantidad;

		void redimensionar();

	public:
		Plataforma();
		~Plataforma();

		void agregarContenido(Contenido* c);
		void mostrarCatalogo() const;
		double calcularRegaliasTotales() const;
		
		Contenido* contenidoMasRentable() const;
		Contenido* contenidoMasPopular() const;

		int contarPorTipo(std::string tipo) const;
		double PromedioRegaliasPorTipo(std::string tipo) const;


	};

}
#endif