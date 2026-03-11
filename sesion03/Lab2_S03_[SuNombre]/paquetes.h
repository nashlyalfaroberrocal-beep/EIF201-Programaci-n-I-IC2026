#ifndef PAQUETES_H
#define	PAQUETES_H

double* CrearRegistro(int& cantidad);

void IngresoPesos(double* pesos, int cantidad);

double CalcularPesoTotal(double* pesos, int cantidad);

int ContarSobreLimite(const double* pesos, int cantidad, double limite);

const double* BuscarMasPesado(const double* pesos, int cantidad);


#endif // PAQUETES_H
