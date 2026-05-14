#ifndef SKILL_H
#define SKILL_H

#include <string>

namespace EIF201 {
	class Skill {
	private:
		std::string Name;
		std::string DamegeType;
		int Power;  //1-200
		int EnergyCost; //0-100
		int Clamprange(int value, int min, int max);
		bool isValidType(std::string type);



	public:
		Skill(std::string Name, std::string DamageType, int Power, int EnergyCost);

		~Skill();

		std::string getName() const;
		std::string getDamageType() const;

	};








}

#endif