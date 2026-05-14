#ifndef NODO_HISTORIAL
#define NODO_HISTORIAL
#include <iostream>
#include <string>

using namespace std;

namespace EIF201 {
	struct NodoHistorial
	{
		string cancion;
		NodoHistorial* siguiente;
		NodoHistorial* anterior;

		NodoHistorial(const string& c)
			: cancion(c), siguiente(nullptr), anterior(nullptr) {
			cout << "[NodoHistorial creado: " << c << "]" << endl;
		}

		~NodoHistorial() {
			cout << "[NodoHistroail destruido: " << cancion << "]" << endl;
		}

	};
}
#endif // NODO_HISTORIAL