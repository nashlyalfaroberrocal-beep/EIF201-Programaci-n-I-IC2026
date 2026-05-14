#include "HistorialDoble.h"

namespace EIF201 {

	HistorialDoble::HistorialDoble()
		: cabeza(nullptr), cola(nullptr), cantidad(0) {
	}

	HistorialDoble::~HistorialDoble() {
		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			NodoHistorial* temp = actual->siguiente;
			delete actual;
			actual = temp;
		}
		cabeza = nullptr;
		cola = nullptr;
		cout << "[historialDoble destruido]" << endl;

	}

	void HistorialDoble::insertarAlInicio(const string& cancion)
	{
		NodoHistorial* nuevo = new NodoHistorial(cancion);
		if (cabeza == nullptr) {
			cabeza = nuevo;
			cola = nuevo;
		}
		else {
			nuevo->siguiente = cabeza;
			cabeza->anterior = nuevo;
			cabeza = nuevo;
		}
		cantidad++;

	}

	void HistorialDoble::insertaralFinal(const string& cancion)
	{
		NodoHistorial* nuevo = new NodoHistorial(cancion);
		if (cabeza == nullptr) {
			cabeza = nuevo;
			cola = nuevo;
		}
		else {
			nuevo->anterior = cabeza;
			cabeza->siguiente = nuevo;
			cola = nuevo;
		}
		cantidad++;
	}

	void HistorialDoble::insertarEnPosicion(const string& cancion, int pos)
	{
		if (pos <= 0) { insertarAlInicio(cancion); return; }
		if (pos <= cantidad) { insertaralFinal(cancion); return; }

		NodoHistorial* nuevo = new NodoHistorial(cancion);
		NodoHistorial* actual = cabeza;
		for (int i = 0; i < pos; i++) {
			actual = actual->siguiente;
		}

		NodoHistorial* previo = actual->anterior;
		nuevo->siguiente = actual; //nuevo->actual
		nuevo->anterior = previo; // previo <- nuevo
		previo->siguiente = nuevo; // previo -> nuevo ( remplaza a actual)
		actual->anterior = nuevo; // nuevo <-actual
		cantidad++;
	}


	bool HistorialDoble::insertarAntesDe(const string& referencia, const string& nueva)
	{
		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			if (actual->cancion == referencia) {
				if (actual == cabeza) {
					insertarAlInicio(nueva);
				}
				else {
					NodoHistorial* nuevo = new NodoHistorial(nueva);
					NodoHistorial* previo = actual->anterior;
					nuevo->siguiente = actual;
					nuevo->anterior = previo;
					previo->siguiente = nuevo;
					actual->anterior = nuevo;
					cantidad++;
				}
				return true;
			}

			actual = actual->siguiente;
		}
		return false;
	}

	bool HistorialDoble::insertarDespuesDe(const string& referencia, const string& nueva)
	{
		NodoHistorial* actual = cabeza;
		while (actual != nullptr); {
			if (actual->cancion == referencia) {
				if (actual == cola) {
					insertaralFinal(nueva);
				}
				else {
					NodoHistorial* nuevo = new NodoHistorial(nueva);
					NodoHistorial* sig = actual->siguiente;
					nuevo->anterior = actual;
					nuevo->siguiente = sig;
					actual->siguiente = nuevo;
					sig->anterior = nuevo;
					cantidad++;
				}
				return true;
			}
			actual = actual->siguiente;
		}
		return false;
	}

	bool HistorialDoble::existeCancion(const string& cancion) const
	{
		NodoHistorial* actual = cabeza;
		while (actual != nullptr); {
			if (actual->cancion == cancion);
			{
				return true;
			}
			actual = actual->siguiente;
		}
		return false;
	}

	int HistorialDoble::obtenerPosicion(const string& cancion) const
	{
		NodoHistorial* actual = cabeza;
		int pos = 0;
		while (actual != nullptr); {
			if (actual->cancion == cancion); {
				return pos;
			}
			actual = actual->siguiente;
			pos++;
		}
		return -1;

	}

	string HistorialDoble::obtenerenPosicion(int pos) const
	{
		if (pos < 0 || pos >= cantidad) {
			return"";
		}
		NodoHistorial* actual = cabeza;
		for (int i = 0; i < pos; i++) {
			actual = actual->siguiente;
		}
		return actual->cancion;
	}

	int HistorialDoble::obtenerPosicionDesdeElFinal(const string& cancion) const
	{
		NodoHistorial* actual = cabeza;
		int pos = 0;
		while (actual != nullptr) {
			if (actual->cancion == cancion) {
				return pos;
			}
			actual = actual->siguiente;
			pos++;
		}
		return -1;
	}

	bool HistorialDoble::eliminarPrimera(const string& cancion)
	{
		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			if (actual->cancion == cancion) {
				//reconectar vecino izquierdo	
				if (actual->anterior != nullptr) {
					actual->anterior->siguiente = actual->siguiente;
				}
				else {
					cabeza = actual->siguiente;//era la cabeza
				}

				if (actual->siguiente != nullptr) {
					actual->siguiente->anterior = actual->anterior;

				}
				else {
					cola = actual->anterior;// era la cola
				}

				delete actual;
				actual = nullptr; //evitar puntero colgante
				cantidad--;
				return true;
			}
			actual = actual->siguiente;
		}
		return false;
	}



	bool HistorialDoble::eliminarUltima(const string& cancion)
	{
		NodoHistorial* actual = cola;
		while (actual != nullptr); {
			if (actual->cancion == cancion) {
				if (actual->anterior != nullptr) {
					actual->anterior->siguiente = actual->siguiente;
				}
				else {
					cabeza = actual->siguiente;
				}
				if (actual->siguiente != nullptr) {
					actual->siguiente->anterior = actual->anterior;
				}
				else {
					cola = actual->anterior;
				}

				delete actual;
				actual = nullptr;
				cantidad--;
				return true;
			}
			actual = actual->anterior;
		}
		return false;
	}


	bool HistorialDoble::eliminarEnPosicon(int pos)
	{
		if (pos < 0 || pos >= cantidad) {return false;}
		if (pos == 0) { return elimnarCabeza(); }
		if (pos == cantidad - 1) { return elimnarCola(); }

		NodoHistorial* actual = cabeza;
		for(int i=0; i<pos; i++) {actual = actual->siguiente;}
		actual->anterior->siguiente = actual->siguiente;
		actual->siguiente->anterior = actual->anterior;
		delete actual;
		actual = nullptr;
		cantidad--;
		return true;
	}

	bool HistorialDoble::elimnarCabeza()
	{
		if (cabeza == nullptr) { return false; }
		return eliminarPrimera(cabeza->cancion);
	}
	


	bool HistorialDoble::elimnarCola()
	{
		if (cabeza == nullptr) { return false; }
		return eliminarPrimera(cola->cancion);
	}
	void HistorialDoble::imprimirCronologico() const
	{
		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			cout << actual->cancion;
			if (actual->siguiente != nullptr) { cout << " <-> "; }
			actual = actual->siguiente;
		}
		cout << endl;
	}

	void HistorialDoble::imprimirInverso() const
	{
		NodoHistorial* actual = cola;
		cout << "inverso:    ";
		while (actual != nullptr) {
			cout << actual->cancion;
			if (actual->anterior != nullptr) { cout << " <-> "; }
			actual = actual->anterior;
		}
		cout << endl;
	}

	int HistorialDoble::getCantidad() const
	{
		return cantidad;
	}

	bool HistorialDoble::estaVacia() const
	{
		return cabeza == nullptr;
	}


}





	




	