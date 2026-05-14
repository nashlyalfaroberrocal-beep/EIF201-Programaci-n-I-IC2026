#include "ListaEstudiante.h"
#include <iostream>

namespace EIF201 {

	Nodo::Nodo(Estudiante* e) : dato(e), siguiente(nullptr) {}

	Nodo::~Nodo() {
		delete dato;
		dato = nullptr;

	}

	ListaEstudiante::ListaEstudiante() : cabeza(nullptr),
		cantidad(0) {
	}

	ListaEstudiante::~ListaEstudiante() {
		Nodo* temp = cabeza;

		while (temp != nullptr) {
			Nodo* siguiente = temp->siguiente;
			delete temp;
			temp = siguiente;
		}

		cabeza = nullptr;
		cantidad = 0;
	}

	void ListaEstudiante::insertarAlInicio(Estudiante* nuevo) {
		if (nuevo == nullptr) {
			return;
		}

		Nodo* nodoNuevo = new Nodo(nuevo);
		nodoNuevo->siguiente = cabeza;
		cabeza = nodoNuevo;
		cantidad++;

	}


	void ListaEstudiante::insertarAlFinal(Estudiante* nuevo) {
		
		if (nuevo == nullptr) {
			return;
		}
			Nodo* nodoNuevoAnterior = new Nodo(nuevo);
			if (cabeza == nullptr) {
				cabeza == nodoNuevoAnterior;
			}

			else {
				Nodo* temp = cabeza;
				while (temp->siguiente != nullptr) {
					temp = temp->siguiente;
				}
				temp->siguiente = nodoNuevoAnterior;
			}
			cantidad++;
		}

	Estudiante* ListaEstudiante::buscarPorCarnet(const std::string& carnet) const
	{
		Nodo* temp = cabeza;
		while (temp != nullptr) {
			if (temp->dato->getCarnet() == carnet) {
				return temp->dato;
			}
			temp = temp->siguiente;
		}

		return nullptr;
	}

	bool ListaEstudiante::eliminarPorCarnet(const std::string& carnet) {
		if (cabeza == nullptr) {
			return false;
		}

		if (cabeza->dato->getCarnet() == carnet) {
			Nodo* eliminar = cabeza;
			cabeza = cabeza->siguiente;
			delete eliminar;
			cantidad--;
			return true;
		}

		Nodo* anterior = cabeza;
		Nodo* actual = cabeza->siguiente;
		while(actual != nullptr) {
			if (actual->dato->getCarnet() == carnet) {
				anterior->siguiente = actual->siguiente;
				delete actual;
				cantidad--;
				return true;
			}

			anterior = actual;
			actual = actual->siguiente;
		}
		return false;
	}

	void ListaEstudiante::recorrer() const
	{
		if (cabeza == nullptr) {
			std::cout << "La lista esta vacia" << std::endl;
			return;
		}
		std::cout << "cantidad de estudiantes: " << cantidad << endl;
		Nodo* temp = cabeza;
		int position = 1;
		while (temp != nullptr) {
			std::cout << " [ " << position << " ] ";
			temp->dato->mostrar();
			temp = temp->siguiente;
			position++;
		}
		std::cout << "-----Fin de la lista-----" << std::endl;
	}

	double ListaEstudiante::calcularPromedio() const {

		}
	int ListaEstudiante::contarAprobados() const
	{
		int contador = 0;
		Nodo* actual = cabeza;
		while (actual != nullptr) {
			if (actual->dato->getNota() >= notaMinima) {
				contador++;
			}

			actual = actual->siguiente;
		}
		return contador;
	}
	}


	int ListaEstudiante::contarAprobados(double notaMinima) const {
		int contador = 0;
		Nodo* actual = cabeza;	
		while(actual != nullptr) {
			if (actual->dato->getNota() >= notaMinima) {
				contador++;
			}

			actual = actual->siguiente;
		}
		return contador;
	}

	int ListaEstudiante::contarReprobados(double notaMinima) const {
		int cantidadApro = ListaEstudiante::contarReprobados(double notaMinima)
		
	}

	int ListasEstudiante::getCantidad() const {

	}
	}


		







