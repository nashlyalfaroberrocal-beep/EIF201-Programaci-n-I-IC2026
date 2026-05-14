#include "Domos.h"
#include <sstream>
#include <iostream>

Domo::Domo(int id, const std::string& Type, float OxygenCapacity, int CapacityColonos)
{
	this->id = id;
	this->Type = Type;
	this->OxygenCapacity = OxygenCapacity;
	this->CapacityColonos = CapacityColonos;
	this->clous = false;
}

Domo::~Domo()
{
}

int Domo::getId() const
{
	return id;
}

std::string Domo::getType() const
{
	return Type;
}


float Domo::getOxygenCapacity() const
{
	return OxygenCapacity;
}

int Domo::getCapacityColonos() const
{
	return CapacityColonos;
}

bool Domo::getClous() const
{
    return clous;
}

void Domo::setId(int id)
{
    this->id = id;
}

void Domo::setType(const std::string& Type)
{
	this->Type = Type;
}

void Domo::setOxygenCapacity(float OxygenCapacity)
{
    this->OxygenCapacity = OxygenCapacity;
}

void Domo::setCapacityColonos(int CapacityColonos)
{
    this->CapacityColonos = CapacityColonos;
}

void Domo::setClous(bool clous)
{
    this->clous = clous;
}
