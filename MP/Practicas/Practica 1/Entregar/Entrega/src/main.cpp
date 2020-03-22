/** 
 * @file   intervalo.cpp
 * @author Juan Manuel Mateos Pérez
 *
 */

#include <iostream>
#include <assert.h>

#include "intervalo.h"

using namespace std;

int main(){
	int nintervalos;
	Intervalo vacio;
	Intervalo punto(1,1);
	Intervalo interv[10];

	// Lectura de datos
	cout << "Cuantos intervalos se van a introducir? (max 10): ";
	do{
		cin >> nintervalos;
	} while(nintervalos > 10);

	cout << "Introduce [ o ( cotaInferior, cotaSuperior ) o ]" << endl;
	for(int i = 0; i < nintervalos; i++)
		leer(interv[i]);

	// Comprobaciones
	clog << endl << "Comprobando intervalo vacio" << endl;
	escribir(vacio);
	if (vacio.esVacio())
		cout << " Es vacío " << endl;
	else
		cout << " No es vacío " << endl;
	cout << endl;
	escribir(punto);
	if (punto.esVacio())
		cout << " Es vacío " << endl;
	else
		cout << " No es vacío " << endl;
	cout << endl;
	
	// Dado un conjunto de valores −1, −0.001, 0, 5.7, 9.6, 10
	double v[]= {-1, -0.001, 0, 5.7, 9.6, 10};
	int numvalores = 6;
	
	for(int i = 0; i < nintervalos; i++){
		escribir(interv[i]);
		cout << "Valores dentro del intervalo: ";
		for(int j = 0; j < numvalores; j++){
			if(interv[i].estaDentro(v[j]))
				cout << v[j] << " ";
		}
		cout << endl << "Valores fuera del intervalo: ";
		for (int j= 0; j < numvalores; j++){
			if (!interv[i].estaDentro(v[j]))
				cout << v[j] <<" ";
		}
		cout << endl;
	}
	return 0; 

}
