#include "Flota.h"
#include <iostream>


namespace UNA {

    Flota::Flota() {
        capacidad = 3;
        cantidad = 0;
        vehiculos = new Vehiculo * [capacidad];
   }


    Flota::~Flota() {
        for (int i = 0; i < cantidad; i++) {
            delete vehiculos[i];
        }
        delete[] vehiculos;
    }



    void Flota::redimensionar() {
        capacidad *= 2;
        Vehiculo** nuevo = new Vehiculo * [capacidad];

        for (int i = 0; i < cantidad; i++) {
            nuevo[i] = vehiculos[i];
        }
        delete[] vehiculos;

        vehiculos = nuevo;
    }


    void Flota::agregar(Vehiculo* nuevo) {
        if (cantidad == capacidad) {
            redimensionar();
        }

        vehiculos[cantidad] = nuevo;
        cantidad++;
    }



    Vehiculo* Flota::buscarPorPlaca(std::string placa) {
        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getPlaca() == placa) {
                return vehiculos[i];
            }
        }

        return nullptr;
    }




    void Flota::mostrarPorMarca(std::string marca) {
        int contador = 0;

        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getMarca() == marca) {
                vehiculos[i]->mostrar();
                contador++;
            }
        }

        if (contador == 0)
            std::cout << "No hay vehiculos de esa marca" << std::endl;
        else
            std::cout << "Total encontrados: " << contador << std::endl;
    }


    bool Flota::eliminar(std::string placa) {

        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getPlaca() == placa) {

                if (vehiculos[i]->getActivo()) {
                    std::cout << "Primero debe desactivar el vehiculo" << std::endl;
                    return false;
                }
                delete vehiculos[i];

                for (int j = i; j < cantidad - 1; j++) {
                   vehiculos[j] = vehiculos[j + 1];
                }
                cantidad--;
              return true;
           }
        }
        std::cout << "Vehiculo no encontrado" << std::endl;
        return false;

    }

    int Flota::contarActivos() {

        int contador = 0;
       for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getActivo()) {
                contador++;
            }
        }
        return contador;
    }

    void Flota::mostrarTodos() {
        if (cantidad == 0) {
            std::cout << "La flota esta vacia" <<std::endl;
            return;
       }
        for (int i = 0; i < cantidad; i++) {
           vehiculos[i]->mostrar();
        }
    }

}