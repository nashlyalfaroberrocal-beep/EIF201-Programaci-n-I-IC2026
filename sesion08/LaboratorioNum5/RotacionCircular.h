#ifndef ROTACION_CIRCULAR
#define ROTACION_CIRCULAR
#include "NodoLocutor.h"

namespace EIF201 {
	class RotacionCircular
	{
	private :
		NodoLocutor* cola;
		int cantidad;

		NodoLocutor* getCabeza() const;

	public:
		RotacionCircular();
		~RotacionCircular();
		void insertarAlFinal(const string& nombre);
		void insertarAlInicio(const string& nombre);
		bool insertarDespuesDe(const string& referencia, const string& nuevo);
		int obtenerPosicion(const string& nombre) const;
		string turnoActual()const;
		bool eliminarLocutor(const string& nombre);
		bool eliminarTurnoActual();
		string siguiente();
		string simularTurnos(int n);
		void imprimirRotacion() const;
		int getCantidad()const;
		bool estaVacia() const;
	};
}
#endif