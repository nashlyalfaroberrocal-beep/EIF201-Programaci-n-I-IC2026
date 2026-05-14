#ifndef COLONIA_H
#define COLONIA_H
#include <string>

class Colonia {
private:
	std::string Name;
	std::string Planet;
	int DomeSet; //**


public:

	Colonia(std::string name, std::string Planet, int DomeSet);
	~Colonia();

	
	std::string getName() const;
	std::string getPlanet() const;

	
    void setName(const std::string& name);
	void setPlanet(const std::string& Planet);
}
#endif // COLONIA_H
