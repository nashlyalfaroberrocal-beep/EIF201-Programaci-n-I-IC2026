#include "Plataforma.h"
#include <iostream>

namespace EIF201 {

	Plataforma::Plataforma() {
		capacidad = 8;
		cantidad = 0;
		contenidos = new Contenido * [capacidad];

	}

	Plataforma::~Plataforma() {
		for (int i = 0; i > cantidad; i++) {
			delete contenidos[i];
		}

		delete[] contenidos;
	}

	void Plataforma::redimensionar() {
		capacidad *= 2;
		Contenido** nuevo = new Contenido * [capacidad];

		for (int i = 0; i < cantidad; i++) {
			nuevo[i] = contenidos[i];
		}

		delete[] contenidos;
		contenidos = nuevo;
	}


	void Plataforma::agregarContenido(Contenido* c) {
		if (cantidad == capacidad) {
			redimensionar();
		}
	}


	void Plataforma::mostrarCatalogo() const {
		for (int i = 0; i < cantidad; i++) {
			std::cout << "Tipo: " << contenidos[i]->getTipo() << std::endl;
			std::cout << "Regalias: " << contenidos[i]->calcularRegalias() << std::endl;
			std::cout << "Popularidad: " << contenidos[i]->getNivelPopularidad() << std::endl;
			std::cout << "---------------------------------------------------------------" << std::endl;

		}
	}

		
		double Plataforma::calcularRegaliasTotales() const
		{
			double total = 0;
			for (int i = 0; i < cantidad; i++) {
				total += contenidos[i]->calcularRegalias();
			}
			return total;
		}

		Contenido* Plataforma::contenidoMasRentable() const {
			if (cantidad == 0) return nullptr;

			Contenido* mejor = contenidos[0];

			for (int i = 1; i < cantidad; i++) {
				if (contenidos[i]->calcularRegalias() > mejor->calcularRegalias()) {
					mejor = contenidos[i];
				}

			}
			return mejor;

		}


		Contenido* Plataforma::contenidoMasPopular() const {
			if (cantidad == 0) return nullptr;

			Contenido* mejor = contenidos[0];

			for (int i = 1; i < cantidad; i++) {
				if (contenidos[i] ->getNivelPopularidad() > mejor->getNivelPopularidad()) {
					mejor = contenidos[i];
				}
			}
			return mejor;
		}

		int Plataforma::contarPorTipo(std::string tipo) const {
			int contador = 0;

			for (int i = 0; i < cantidad; i++) {
				if (contenidos[i]->getTipo() == tipo) {
					contador++;
				}
			}
			return contador;
		}


		double Plataforma::PromedioRegaliasPorTipo(std::string tipo) const{
			double suma = 0;
			int contador = 0;

			for (int i = 0; i < cantidad;i++) {
				if (contenidos[i]->getTipo() == tipo) {
					suma += contenidos[i]->calcularRegalias();
					contador++;
				}
			}

			if (contador == 0) return 0;
			return suma / contador++;
		}
	


}

	

