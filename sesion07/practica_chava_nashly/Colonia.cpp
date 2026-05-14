#include "Colonia.h"
#include <sstream>
#include <iostream>

Colonia::Colonia(std::string name, std::string Planet, int DomeSet)
{
	Name = name;
	this->Planet = Planet;
	this->DomeSet = DomeSet;
}

Colonia::~Colonia()
{
}


std::string Colonia::getName() const
{
	return Name;
}

std::string Colonia::getPlanet() const
{
	return Planet;
}

void Colonia::setName(const std::string& name)
{
	Name = name;
}

void Colonia::setPlanet(const std::string& planet)
{
	Planet = planet;
}





