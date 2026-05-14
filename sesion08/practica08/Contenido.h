#ifndef CONTENIDO_H
#define CONTENIDO_H
#include <string>
#include <sstream>

namespace EIF{}
	class Contenido
	{ 
protected:
	std::string name;
	int duration;


	public:
		Contenido(const std::string& name, int duration) : name(name), duration(duration) {
		
		}

		virtual ~Contenido() {}

		virtual double calcularRegalias() const = 0;
		virtual std::string getTipo() const = 0;
		virtual int getNivelPopularidad() const = 0;
		virtual std::string toString()const {
			std::ostringstream oss;	
			oss << "|Tipo" << getTipo() << "[Nombre:" << name << "| Duracion:" << duration << "]";
			return oss.str();	
		}
		std::string getRegalias() const
		{return name;}
		int setDuracion()const
		{return duration;}
};



#endif