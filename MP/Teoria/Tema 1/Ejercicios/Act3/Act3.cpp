#include <iostream>

using namespace std;

const int total_elem = 100;

void ImprimirArray(int vector[], const int& elem_utiles){
	cout << endl << elem_utiles << endl;
	for(int i = 0; i<elem_utiles; i++){
		cout << vector[i] << " ";
	}
	
}

void LeerArray(int vector[], const int& elem_utiles){
	for(int i = 0; i<elem_utiles; i++){
		cin >> vector[i];
	}
}

int BusquedaSecuencialArray(const int& dato, int vector[], const int& inicial, const int& final_){
	int pos = 0;
	bool encontrado = false;
	
	for(int i = 0; i<final_ && !encontrado; i++)
		if(vector[i] == dato){
			pos = i;
			encontrado = true;
		}
	
	if(pos == 0)
		pos = -1;
	
	return pos;
}

int main(){
	int elem_utiles, dato_buscar;
	int vectorc[total_elem];
	
	cout << "Introduce el numero de elementos (maximo 100): ";
	cin >> elem_utiles;
	cout << "Introduce el numero a buscar: ";
	cin >> dato_buscar;
	
	clog << "Introduce los valores del vector: " << endl;
	LeerArray(vectorc, elem_utiles);
	
	ImprimirArray(vectorc, elem_utiles);
	
	cout << endl << "\nLa posicion es: " << BusquedaSecuencialArray(dato_buscar,vectorc,0,elem_utiles) + 1;
}
