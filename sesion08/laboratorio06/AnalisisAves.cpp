#include "AnalisisAves.h"
#include <iostream>
namespace EIF201 {
    int AnalisisAves::contar(NodoAve* cabeza) const
    {
		if (cabeza == nullptr) {
            return 0;
        }
        else {
			return 1 + contar(cabeza->siguiente);
        }
        
    }

    double AnalisisAves::sumapesos(NodoAve* cabeza) const
    {
        if (cabeza == nullptr) {
            return 0;
        }
        else {
            return cabeza->peso + sumapesos(cabeza->siguiente);
        }

        
    }

    int AnalisisAves::contarEspecie(NodoAve* cabeza, const std::string& especie) const
    {
        if (cabeza == nullptr) {
            return 0;
        }
        else {
			return (cabeza->especie == especie ? 1 : 0) + contarEspecie(cabeza->siguiente, especie);
        }
    }

    bool AnalisisAves::existeanillo(NodoAve* cabeza, const std::string& anillo) const
    {
        if (cabeza == nullptr) {
            return 0;
        }
		else {
            return (cabeza->anillo == anillo) || existeanillo(cabeza->siguiente, anillo);
		}
        
    }

    NodoAve* AnalisisAves::aveMasPesada(NodoAve* cabeza) const
    {
		if (cabeza == nullptr) {
            return 0;
        }
        else {
            NodoAve* maxSiguiente = aveMasPesada(cabeza->siguiente);
            if (maxSiguiente == nullptr || cabeza->peso >= maxSiguiente->peso) {
                return cabeza;
            }
            else {
                return maxSiguiente;
			}
        }
       
    }

    void AnalisisAves::imprimirCronologico(NodoAve* cabeza) const
    {
        if (cabeza == nullptr) {
            return;
        }

        std::cout << cabeza->anillo << " | "
            << cabeza->especie << " | "
            << cabeza->peso << " | "
            << cabeza->sexo << " | "
            << cabeza->fecha << std::endl;

        imprimirCronologico(cabeza->siguiente);
    }

    void AnalisisAves::imprimirInverso(NodoAve* cabeza) const
    {
        if (cabeza == nullptr) {
            return;
        }

        imprimirInverso(cabeza->siguiente);

        std::cout << cabeza->anillo << " | "
            << cabeza->especie << " | "
            << cabeza->peso << " | "
            << cabeza->sexo << " | "
            << cabeza->fecha << std::endl;
    }

}