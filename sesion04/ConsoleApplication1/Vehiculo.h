#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>

namespace UNA {

    class Vehiculo {

    private:
        std::string placa;
        std::string marca;
        int Year;
        double kilometraje;
        bool activo;

    public:
        Vehiculo(std::string placa, std::string marca, int Year, double kilometraje);
        std::string getPlaca() const;
        std::string getMarca() const;

        int getYear() const;
        double getKilometraje() const;
        bool getActivo() const;

        void registrarKilometros(double km);
        void desactivar();
        void reactivar();
        void mostrar() const;
    };

}

#endif
