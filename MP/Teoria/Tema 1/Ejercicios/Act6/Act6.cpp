#include <iostream>

using namespace std;

const int total_elem = 100;

void LeerArray(int vector[], const int& elem_utiles){
	for(int i = 0; i<elem_utiles; i++)
		cin >> vector[i];
}

void ImprimirArray(int vector[], const int& elem_utiles){
	for(int i = 0; i<elem_utiles; i++)
		cout << vector[i] << " ";
}

void OrdenarVector(int vector[], const int& elem_utiles){
	for(int i = 0; i<elem_utiles; i++)
		for(int j = 0; j<elem_utiles - 1; j++)
			if(vector[j] > vector[j+1]){
				int aux = vector[j];
				vector[j] = vector[j+1];
				vector[j+1] = aux;
			}
}

int BusquedaBinariaArray(const int& numero, int vector[], const int& elem_utiles){
	int izq = 0;
	int der = elem_utiles-1;
	int central = (izq+der)/2;
	int posicion = -1;
	
	while(posicion == -1 && izq != der){
		if(vector[central] == numero)
			posicion = central;
		else{
			if(numero < vector[central])
				der = central;
			else
				izq = central;
			central = (izq+der)/2;
		}
	}
	return posicion;
}

int main(){
	int elem_utiles, numero;
	int vectorc[100];
	
	cout << "Introduce el numero de elementos: ";
	cin >> elem_utiles;
	
	cout << "Introduce los valores del vector: " << endl;
	LeerArray(vectorc, elem_utiles);
	OrdenarVector(vectorc, elem_utiles);
	
	cout << "El vector ordenado es: " << endl;
	ImprimirArray(vectorc, elem_utiles);
	
	cout << "\nIntroduce un numero: ";
	cin >> numero;
	
	int posicion = BusquedaBinariaArray(numero,vectorc,elem_utiles);
	cout << "\nLa posicion de " << numero << " es " << posicion;
}
