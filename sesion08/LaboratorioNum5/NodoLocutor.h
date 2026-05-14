#ifndef NODO_LOCUTOR
#define NODO_LOCUTOR

#include <iostream>
#include <string>
using namespace std;
namespace EIF201 {
		struct NodoLocutor {
			string nombre;
			NodoLocutor* siguiente;

			NodoLocutor(const string& n)
				: nombre(n), siguiente(nullptr) {
				cout << "[NodoLocutor creado: " << n << "]" << endl;
			}
			~NodoLocutor() {
				cout << "[NodoLocutor destruido: " << nombre << "]" << endl;
				siguiente = nullptr; //evitar puntero colgante
			}
		};
}
#endif