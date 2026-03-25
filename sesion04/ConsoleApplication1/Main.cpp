#include <iostream>
#include "Flota.h"

using namespace UNA;

int main() {

    Flota flota;
    int opcion;

    do {
        std::cout<<"--------------------------------------------------" << std::endl;
        std::cout << "Registrar vehiculo" << std::endl;
        std::cout << "2 Buscar vehiculo por placa" << std::endl;
        std::cout << "3 Mostrar vehiculos por marca" << std::endl;
        std::cout << "4 Registrar kilometros" << std::endl;
        std::cout << "5 Desactivar vehiculo" << std::endl;
        std::cout << "6 Reactivar vehiculo" << std::endl;
        std::cout << "7 Eliminar vehiculo" << std::endl;
        std::cout << "8 Mostrar flota" << std::endl;
        std::cout << "9 Cantidad de vehiculos activos" << std::endl;
        std::cout << "10 Salir" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;

        std::cin >> opcion;
        std::cout << "--------------------------------------------------" << std::endl;

        switch (opcion) {

        case 1: {

            std::string placa, marca;
            int Year;
            double km;

            std::cout << "Placa: ";
            std::cin >> placa;

            std::cout << "Marca: ";
            std::cin >> marca;

            std::cout << "Year: ";
            std::cin >> Year;

            std::cout << "Kilometraje: ";
            std::cin >> km;

            Vehiculo* v = new Vehiculo(placa, marca, Year, km);
            flota.agregar(v);

            break;
        }

        case 2: {

            std::string placa;

            std::cout << "Placa: ";
            std::cin >> placa;

            Vehiculo* v = flota.buscarPorPlaca(placa);

            if (v != nullptr)
                v->mostrar();
            else
                std::cout << "Vehiculo no encontrado\n";

            break;
        }

        case 3: {

            std::string marca;

            std::cout << "Marca: ";
            std::cin >> marca;

            flota.mostrarPorMarca(marca);

            break;
        }

        case 4: {

            std::string placa;
            double km;

            std::cout << "Placa: ";
            std::cin >> placa;

            Vehiculo* v = flota.buscarPorPlaca(placa);

            if (v != nullptr) {

                std::cout << "Kilometros a agregar: ";
                std::cin >> km;

                v->registrarKilometros(km);
            }

            break;
        }

        case 5: {

            std::string placa;

            std::cout << "Placa: ";
            std::cin >> placa;

            Vehiculo* v = flota.buscarPorPlaca(placa);

            if (v != nullptr)
                v->desactivar();

            break;
        }

        case 6: {

            std::string placa;

            std::cout << "Placa: ";
            std::cin >> placa;

            Vehiculo* v = flota.buscarPorPlaca(placa);

            if (v != nullptr)
                v->reactivar();

            break;
        }

        case 7: {

            std::string placa;

            std::cout << "Placa: ";
            std::cin >> placa;

            flota.eliminar(placa);

            break;
        }

        case 8:

            flota.mostrarTodos();
            break;

        case 9:

            std::cout << "Vehiculos activos: "
                << flota.contarActivos()
                << std::endl;
            break;

        case 10:

            std::cout << "Saliendo del programa...\n";
            break;

        default:

            std::cout << "Opcion invalida\n";
        }

    } while (opcion != 10);

    return 0;
}