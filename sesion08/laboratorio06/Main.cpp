#include <iostream>
#include "Bitacora.h"
#include "AnalisisAves.h"

using namespace EIF201;

int main()
{
    NodoAve* lista = nullptr;

    Bitacora bit("datos/anillamientos.txt");
    AnalisisAves analisis;

    int opcion;

    do {

        std::cout << "\n===== MENU =====\n";
        std::cout << "1. Cargar aves validas\n";
        std::cout << "2. Contar aves\n";
        std::cout << "3. Sumar pesos\n";
        std::cout << "4. Contar especie\n";
        std::cout << "5. Buscar anillo\n";
        std::cout << "6. Ave mas pesada\n";
        std::cout << "7. Imprimir cronologico\n";
        std::cout << "8. Imprimir inverso\n";
        std::cout << "9. Liberar lista\n";
        std::cout << "0. Salir\n";

        std::cout << "\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {

        case 1: {

            int subopcion;

            do {
                std::cout << "\n===== VALIDAR AVES =====\n";
                std::cout << "1. Cargar aves validas desde archivo\n";
                std::cout << "2. Registrar ave manualmente\n";
                std::cout << "0. Volver al menu principal\n";
                std::cout << "\nSeleccione una opcion: ";
                std::cin >> subopcion;

                switch (subopcion) {

                case 1: {
                    int cargadas = bit.cargarValidas(lista);

                    std::cout << "\nAves validas cargadas: "
                        << cargadas << std::endl;

                    std::cout << "Lineas descartadas: "
                        << bit.getDescartadas()
                        << std::endl;

                    break;
                }

                case 2: {
                    std::string anillo;
                    std::string especie;
                    std::string pesoTexto;
                    char sexo;
                    std::string fecha;

                    std::cout << "\nDigite el anillo: ";
                    std::cin >> anillo;

                    std::cout << "Digite la especie: ";
                    std::cin >> especie;

                    std::cout << "Digite el peso: ";
                    std::cin >> pesoTexto;

                    std::cout << "Digite el sexo (M/H): ";
                    std::cin >> sexo;

                    std::cout << "Digite la fecha (YYYY-MM-DD): ";
                    std::cin >> fecha;

                    double peso = std::stod(pesoTexto);

                    bool registro = bit.registarAve(anillo, especie, peso, sexo, fecha);

                    if (registro) {
                        std::cout << "\nAve registrada exitosamente.\n";

                        NodoAve* nuevo = new NodoAve(anillo, especie, peso, sexo, fecha);

                        if (lista == nullptr) {
                            lista = nuevo;
                        }
                        else {
                            NodoAve* temp = lista;
                            while (temp->siguiente != nullptr) {
                                temp = temp->siguiente;
                            }
                            temp->siguiente = nuevo;
                        }
                    }
                    else {
                        std::cout << "\nError al registrar el ave.\n";
                    }

                    break;
                }

                case 0: {
                    std::cout << "\nVolviendo al menu principal...\n";
                    break;
                }

                default:
                    std::cout << "\nOpcion invalida.\n";
                }

            } while (subopcion != 0);

            break;
        }

        case 2: {

            std::cout << "\nCantidad total de aves: "
                << analisis.contar(lista)
                << std::endl;

            break;
        }

        case 3: {

            std::cout << "\nSuma total de pesos: "
                << analisis.sumapesos(lista)
                << std::endl;

            break;
        }

        case 4: {

            std::string especie;

            std::cout << "\nDigite la especie: ";
            std::cin >> especie;

            std::cout << "Cantidad encontrada: "
                << analisis.contarEspecie(lista, especie)
                << std::endl;

            break;
        }

        case 5: {

            std::string anillo;

            std::cout << "\nDigite el anillo: ";
            std::cin >> anillo;

            if (analisis.existeanillo(lista, anillo)) {

                std::cout << "El anillo existe.\n";
            }
            else {

                std::cout << "El anillo no existe.\n";
            }

            break;
        }

        case 6: {

            NodoAve* pesada = analisis.aveMasPesada(lista);

            if (pesada != nullptr) {

                std::cout << "\nAve mas pesada:\n";

                std::cout << pesada->anillo << " | "
                    << pesada->especie << " | "
                    << pesada->peso << " | "
                    << pesada->sexo << " | "
                    << pesada->fecha << std::endl;
            }
            else {

                std::cout << "La lista esta vacia.\n";
            }

            break;
        }

        case 7: {

            std::cout << "\n--- CRONOLOGICO ---\n";

            analisis.imprimirCronologico(lista);

            break;
        }

        case 8: {

            std::cout << "\n--- INVERSO ---\n";

            analisis.imprimirInverso(lista);

            break;
        }

        case 9: {

            Bitacora::liberarLista(lista);

            std::cout << "\nLista liberada.\n";

            break;
        }

        case 0: {

            std::cout << "\nSaliendo...\n";

            break;
        }

        default:

            std::cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 0);

    Bitacora::liberarLista(lista);

    return 0;
}