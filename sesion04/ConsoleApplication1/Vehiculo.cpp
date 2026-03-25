#include "Vehiculo.h"


namespace UNA {

    Vehiculo::Vehiculo(std::string placa, std::string marca, int Year, double kilometraje) {
        this->placa = placa;
        this->marca = marca;
        this->Year = Year;
        this->kilometraje = kilometraje;
        this->activo = true;
    }

    std::string Vehiculo::getPlaca() const {
        return placa;
    }

    std::string Vehiculo::getMarca() const {
        return marca;
    }

    int Vehiculo::getYear() const {
        return Year;
    }

    double Vehiculo::getKilometraje() const {
        return kilometraje;
    }

    bool Vehiculo::getActivo() const {
        return activo;
    }

    void Vehiculo::registrarKilometros(double km) {

        if (!activo) {
            std::cout << "Error: El vehiculo esta fuera de servicio" << std::endl;
            return;
        }

        if (km <= 0) {
            std::cout << "Error: Los kilometros deben ser positivos" << std::endl;
            return;
        }

        kilometraje += km;
    }

    void Vehiculo::desactivar() {

        if (!activo) {
            std::cout << "El vehiculo ya esta fuera de servicio" << std::endl;
            return;
        }

        activo = false;
    }

    void Vehiculo::reactivar() {

        if (activo) {
            std::cout << "El vehiculo ya esta activo" <<std::endl;
            return;
        }

        activo = true;
    }

    void Vehiculo::mostrar() const {

        std::cout << "Placa: " << placa << std::endl;
        std::cout << "Marca: " << marca << std::endl;
        std::cout << "Anio: " << Year << std::endl;
        std::cout << "Kilometraje: " << kilometraje << std::endl;

        if (activo)
            std::cout << "Estado: ACTIVO\n";
        else
            std::cout << "Estado: FUERA DE SERVICIO" << std::endl;

        std::cout << "----------------------" << std::endl;
    }

}
