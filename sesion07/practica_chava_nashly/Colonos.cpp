
#include "Colonos.h"
#include <iostream>

Colonos::Colonos(int id, const std::string& nombre, const std::string& specialty, double OxygenConsumption, int Productivity)
    : id(id), nombre(nombre), specialty(specialty), OxygenConsumption(OxygenConsumption), Productivity(Productivity)
{
}

Colonos::~Colonos() {}

int Colonos::getId() const { return id; }
std::string Colonos::getNombre() const { return nombre; }
std::string Colonos::getSpecialty() const { return specialty; }
double Colonos::getOxygenConsumption() const { return OxygenConsumption; }
int Colonos::getProductivity() const { return Productivity; }

void Colonos::setId(int id) { this->id = id; }
void Colonos::setNombre(const std::string& nombre) { this->nombre = nombre; }
void Colonos::setSpecialty(const std::string& specialty) { this->specialty = specialty; }
void Colonos::setOxygenConsumption(double OxygenConsumption) { this->OxygenConsumption = OxygenConsumption; }
void Colonos::setProductivity(int Productivity) { this->Productivity = Productivity; }
