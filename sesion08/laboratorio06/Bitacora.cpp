#include "Bitacora.h"
#include <fstream>
#include <sstream>
namespace EIF201 {
	

	Bitacora::Bitacora(const std::string& ruta) : validas_(0), descartadas_(0), ruta_(ruta)
	{ 
		ruta_ = "datos/anillamientos.txt";

	}



	bool Bitacora::registarAve(const std::string& anillo, const std::string& especie, double peso, char sexo, const std::string& fecha)
	{
		std::ofstream archivo(ruta_, std::ios::app);
		if (!archivo.is_open()) {
			return false;
		};
		archivo << anillo << ";"
			<< especie << ";"
			<< peso << ";"
			<< sexo << ";"
			<< fecha << std::endl;
		
		archivo.close();
		return true;
	}



	int Bitacora::cargarTodas(NodoAve*& cabeza)
	{
		cabeza = nullptr;
		std::string linea;
		int contador = 0;
		std::ifstream archivo(ruta_);
		if (!archivo.is_open()) {
			cabeza = nullptr;
			return 0;
		}

		while (getline(archivo, linea)) {
			std::stringstream ss(linea);
			std::string anillo;
			std::string especie;
			std::string pesoTexto;
			std::string sexoTexto;
			std::string fecha;

			getline(ss, anillo, ';');
			getline(ss, especie, ';');
			getline(ss, pesoTexto, ';');
			getline(ss, sexoTexto, ';');
			getline(ss, fecha, ';');

			double peso = std::stod(pesoTexto);
			char sexo = sexoTexto[0];

			NodoAve* nuevo = new NodoAve(anillo,especie,peso,sexo,fecha);
			

			if (cabeza == nullptr) {
				cabeza = nuevo;
			}
			else {
				NodoAve* temp = cabeza;
				while (temp->siguiente != nullptr) {
					temp = temp->siguiente;
				}
				temp->siguiente = nuevo;
			}

			contador++;
			
		}
		archivo.close();
		return contador;
		
	}



	int Bitacora::cargarValidas(NodoAve*& cabeza)
	{

		cabeza = nullptr;
		validas_ = 0;
		descartadas_ = 0;

		std::ifstream archivo(ruta_);

		if (!archivo.is_open()) {
			return 0;
		}

		std::string linea;

		while (getline(archivo, linea)) {
			if (linea.empty()) {
				descartadas_++;
				continue;
			}

			std::stringstream ss(linea);
			std::string anillo;
			std::string especie;
			std::string pesoTexto;
			std::string sexoTexto;
			std::string fecha;

			if (!std::getline(ss, anillo, ';') ||
				!std::getline(ss, especie, ';') ||
				!std::getline(ss, pesoTexto, ';') ||
				!std::getline(ss, sexoTexto, ';') ||
				!std::getline(ss, fecha, ';')) {

				descartadas_++;
				continue;
			}
			double peso;
			try {
				peso = std::stod(pesoTexto);
			}

			catch (...) {
				descartadas_++;
				continue;
			}

			char sexo = sexoTexto[0];

			if (sexo != 'M' && sexo != 'H' && sexo != 'X') {
				descartadas_++;
				continue;
			}

			NodoAve* nuevo = new NodoAve(anillo, especie, peso, sexo, fecha);

			nuevo->siguiente = nullptr;
			if (cabeza == nullptr) {
				cabeza = nuevo;
			}
			else {
				NodoAve* temp = cabeza;
				while (temp->siguiente != nullptr) {
					temp = temp->siguiente;
				}
				temp->siguiente = nuevo;
			}
			validas_++;

		}
		archivo.close();
		return validas_;
	}

	

	int Bitacora::getValidas() const
	{
		return validas_;

	}



	int Bitacora::getDescartadas() const
	{
		return descartadas_;
	}



	void Bitacora::liberarLista(NodoAve*& cabeza)
	{
		while (cabeza != nullptr) {
			NodoAve* temp = cabeza->siguiente;
			delete cabeza;
			cabeza = temp;
		}
	}

}
