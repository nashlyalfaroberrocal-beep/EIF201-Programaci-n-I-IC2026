#pragma once

#include "Estudiante.h"


namespace EIF201 {

	struct Nodo {
		Estudiante* dato;
		Nodo* siguiente;

		Nodo(Estudiante* e);
		~Nodo();
	};

	class ListaEstudiante
	{
	private:
		Nodo* cabeza;
		int cantidad;

	public:
		ListaEstudiante();
		~ListaEstudiante();

		void insertarAlInicio(Estudiante* nuevo);
		void insertarAlFinal(Estudiante* nuevo);

		Estudiante* buscarPorCarnet(const std::string& carnet) const;

		bool eliminarPorCarnet(const std::string& carnet);

		void recorrer() const;

		double calcularPromedio() const;

		int contarAprobados() const;

		int contarAprobados(double notaMinima) const;

		int contarReprobados(double notaMinima) const;

		int getCantidad() const;

		bool estaVacia()  const;


	};

}