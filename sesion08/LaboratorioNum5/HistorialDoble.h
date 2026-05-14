#ifndef HISTORIALDOBLE_H
#define HISTORIALDOBLE_H
#include "NodoHistorial.h"

namespace EIF201 {
	class HistorialDoble
	{
	private:
		NodoHistorial* cabeza;
		NodoHistorial* cola;
		int cantidad;

	public:
		HistorialDoble();
		~HistorialDoble();

		//insercion
		// agregar una cancion al inicio(nuevacancion)
		void insertarAlInicio(const string& cancion);

		//agregar cancion al final(nueva cola)
		void insertaralFinal(const string& cancion);

		//agregar cancion en una posicion indicada 
		//si pos <=o; insertar al inicio. si pos >= cantidad, insertar al final. 
		void insertarEnPosicion(const string& cancion, int pos);

		//inserta "nuevo" justo antes de la primera ocurrencia de "referencia". retorna false si existe
		bool insertarAntesDe(const string& referencia, const string& nueva);

		// inserta "nuevo" justo despues de la primera ocurrencia de "referencia". retorna false si "referencia" no existe
		bool insertarDespuesDe(const string& referencia, const string& nueva);

		//busqueda
		//retorna true si el nombre de la cancion existe en el historial.
		bool existeCancion(const string& cancion)const ;

		//retorna la posicion (0-indexada) de la primera ocurrencia de la cancion. 
		//Retorna -1 si no existe.
		int obtenerPosicion(const string& cancion) const;

		// retorna el nombre de la cancion en la posicion dada. Retorna "" si la posicon esta fuera de rango
		string obtenerenPosicion(int pos) const;

		//busqueda desde el final. retorna la posicion contando desde la cola
		// util para encontrar la ultima aparicion de una cancion
		int obtenerPosicionDesdeElFinal(const string& cancion) const;

		//eliminacion
		//elimina la primera ocurrencia de una cancion
		bool eliminarPrimera(const string& cancion);
		
		//elimina la ultima ocurrencia de una cancion 
		bool eliminarUltima(const string& cancion);

		//eliminar el nodo en la posicion indicada(0-index)
		bool eliminarEnPosicon(int pos);

		//eliminar el primer nodo(la cabeza actual)
		bool elimnarCabeza();

		//eliminar el ultimo nodo(la cola actual)
		bool elimnarCola();
		
		//recorrido
		void imprimirCronologico() const; //cabeza a cola
		void imprimirInverso() const; // cola a cabeza

		int getCantidad() const;
		bool estaVacia() const;

	};
}
#endif
