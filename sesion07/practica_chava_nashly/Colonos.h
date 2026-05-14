#ifndef COLONOS_H
#define COLONOS_H

#include <string>

class Colonos {
private:
	int id;
	std::string nombre;
	std::string specialty;
	double OxygenConsumption;
	int Productivity;

public:
    Colonos(int id, const std::string& nombre, const std::string& specialty, double OxygenConsumption, int Productivity);
	~Colonos();

	int getId() const;
	std::string getNombre() const;
	std::string getSpecialty() const;
	double getOxygenConsumption() const;
	int getProductivity() const;

	void setId(int id);
	void setNombre(const std::string& nombre);
	void setSpecialty(const std::string& specialty);
	void setOxygenConsumption(double OxygenConsumption);
	void setProductivity(int Productivity);
};







#endif

