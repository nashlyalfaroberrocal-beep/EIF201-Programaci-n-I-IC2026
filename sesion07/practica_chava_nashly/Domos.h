#ifndef DOMOS_H
#define DOMOS_H
#include "Colonia.h"
#include <string>

class Domo {
private:
	int id;
	std::string Type;
	float OxygenCapacity;
	int CapacityColonos;
	bool clous;


public:

    Domo(int id, const std::string& Type, float OxygenCapacity, int CapacityColonos);
	~Domo();

	int getId() const;
	std::string getType() const;
	float getOxygenCapacity() const;
	int getCapacityColonos() const;
	bool getClous() const;

	void setId(int id);
    void setType(const std::string& Type);
	void setOxygenCapacity(float OxygenCapacity);
	void setCapacityColonos(int CapacityColonos);
	void setClous(bool clous);
};






#endif // DOMOS_H
