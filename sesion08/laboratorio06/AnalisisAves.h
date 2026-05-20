#ifndef EIF201_ANALISIS_AVES_H
#define EIF201_ANALISIS_AVES_H
#include "NodoAve.h"

namespace EIF201 {
	class AnalisisAves {
	private:
		void imprimirInversoAux(NodoAve* cabeza)const;
		NodoAve* maxAux(NodoAve* cabeza)const;

	public:
		AnalisisAves() = default;

		int contar(NodoAve* cabeza)const;
		double sumapesos(NodoAve* cabeza)const;
		int contarEspecie(NodoAve* cabeza, const std::string& especie)const;
		bool existeanillo(NodoAve* cabeza, const std::string& anillo)const;
		NodoAve* aveMasPesada(NodoAve* cabeza)const;
		void imprimirCronologico(NodoAve* cabeza)const;
		void imprimirInverso(NodoAve* cabeza)const;


	};

}
#endif 