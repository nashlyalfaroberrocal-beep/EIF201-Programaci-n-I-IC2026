#include "RotacionCircular.h"

namespace EIF201 {

    RotacionCircular::RotacionCircular()
        : cola(nullptr), cantidad(0) {
    }

    // Método auxiliar privado
    NodoLocutor* RotacionCircular::getCabeza() const {
        return (cola != nullptr) ? cola->siguiente : nullptr;
    }

    RotacionCircular::~RotacionCircular() {
        if (cola == nullptr) {
            return;
        }
        NodoLocutor* cabeza = cola->siguiente;
        cola->siguiente = nullptr; // Romper el ciclo antes de liberar
        NodoLocutor* actual = cabeza;
        while (actual != nullptr) {
            NodoLocutor* temp = actual->siguiente;
            delete actual;
            actual = temp;
        }
        cola = nullptr;
        cout << "[RotacionCircular destruida]" << endl;
    }
    void RotacionCircular::insertarAlFinal(const string& nombre)
    {
		NodoLocutor* nuevo = new NodoLocutor(nombre);
		if (cola == nullptr) {
            nuevo->siguiente = nuevo; // Apunta a sí mismo para formar el ciclo
            cola = nuevo;
        }
        else {
            nuevo->siguiente = cola->siguiente; // Nuevo apunta a la cabeza actual
            cola->siguiente = nuevo; // La cola actual apunta al nuevo nodo
            cola = nuevo; // El nuevo nodo se convierte en la nueva cola
        }
        cantidad++;
    }

    void RotacionCircular::insertarAlInicio(const string& nombre)
    {
        NodoLocutor* nuevo = new NodoLocutor(nombre);
        if (cola == nullptr) {
            nuevo->siguiente = nuevo; // Apunta a sí mismo para formar el ciclo
            cola = nuevo;
        }
        else {
            nuevo->siguiente = cola->siguiente; // Nuevo apunta a la cabeza actual
			cola->siguiente = nuevo; // La cola actual apunta al nuevo nodo
        }
        cantidad++;
    }

    bool RotacionCircular::insertarDespuesDe(const string& referencia, const string& nuevo)
    {
		if (cola == nullptr) { return false; }
		NodoLocutor* cabeza = getCabeza();
		NodoLocutor* actual = cabeza;

        do {
			if (actual->nombre == referencia) {
                NodoLocutor* nuevoNodo = new NodoLocutor(nuevo);
                nuevoNodo->siguiente = actual->siguiente;
                actual->siguiente = nuevoNodo;
                if (actual == cola) {
                    cola = nuevoNodo; // Actualizar la cola si se inserta después de la última posición
                }
                cantidad++;
                return true;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
        return false;
    }

    int RotacionCircular::obtenerPosicion(const string& nombre) const
    {
		if (cola == nullptr) { return -1; }
		NodoLocutor* cabeza = getCabeza();
        NodoLocutor* actual = cabeza;
        int pos = 0;
		do {
			if (actual->nombre == nombre) { return pos;}
            actual = actual->siguiente;
            pos++;
        } while (actual != cabeza);
        return -1;
    }

    string RotacionCircular::turnoActual() const
    {
		if (cola == nullptr) { return ""; }
        return cola->siguiente->nombre;
    }

    bool RotacionCircular::eliminarLocutor(const string& nombre)
    {
        if (cola == nullptr) { return false; }
        NodoLocutor* cabeza = getCabeza();
        NodoLocutor* actual = cabeza;
        NodoLocutor* previo = cola; // El nodo anterior a la cabeza es la cola
        do {
            if (actual->nombre == nombre) {
                if (actual == cola && actual == cabeza) {
                    cola = nullptr;
                }
                else {
                    previo->siguiente = actual->siguiente; // La cola apunta a la nueva cabeza
                    if (actual == cola) cola = previo;
                }
                    delete actual;
                    actual = nullptr;
                    cantidad--;
                    return true;
                }
                previo = actual;
                actual = actual->siguiente;
            } while (actual != cabeza);
            return false;
        
    }
                

    bool RotacionCircular::eliminarTurnoActual()
    {
		if (cola == nullptr) { return false; }
		return eliminarLocutor(getCabeza()->nombre);

    }

    string RotacionCircular::siguiente()
    {
		if (cola == nullptr) { return ""; }
        cola = cola->siguiente; 
        return getCabeza()->nombre;
    }

	string RotacionCircular::simularTurnos(int n)
	{
		if (cola ==nullptr) { cout << "sin locutores en rotacion." << endl; return ""; }
		for (int i = 1; i <= n; i++) {
			cout << "Turno " << i << ": " << siguiente() << endl;

		}
		return "";
	}

    void RotacionCircular::imprimirRotacion() const
    {
		if (cola == nullptr) { cout << "sin locutores en rotacion." << endl; return; }
        NodoLocutor* cabeza = getCabeza();
        NodoLocutor* actual = cabeza;
		cout << "Rotacion: ";
        do {
            cout << actual->nombre;
            actual = actual->siguiente;
			if (actual != cabeza) { cout << " -> "; }
        } while (actual != cabeza);
		cout << "-> (inicio)" << endl;
	
    }
    int RotacionCircular::getCantidad() const
    {
        return cantidad;
	}

    bool RotacionCircular::estaVacia() const
    {
        return cola ==nullptr;
	}



}




