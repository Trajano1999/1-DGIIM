#include <iostream>
#include <cmath> // floor
#include <ctime> // time
#include <cstdlib> // rand

using namespace std;

void ImprimirArray(const int numeros[], const int& elem_utiles){
	for(int i = 0; i<elem_utiles; i++)
		cout << numeros[i] << " ";
}

void GenerarArray(int num[], const int& max, const int& min, const int& elem){
	srand ((int) time(0));
	
	for(int i = 0; i<elem; i++){
		double u01 = rand() / (RAND_MAX+1.0); // Uniforme01
		num[i] = floor(min + u01 * (max-min+1));
	}
}

int main(int argc, char* argv[]){
		int elem_utiles, minimo, maximo;
		
		cout << "Introduce el numero de elementos del array: ";
		cin >> elem_utiles;
		cout << "Introduce el elemento minimo: ";
		cin >> minimo;
		cout << "Introduce el elemento maximo: ";
		cin >> maximo;
		
		int numeros[500];
		
		cout << elem_utiles << endl;
		
		GenerarArray(numeros, maximo, minimo, elem_utiles);
		ImprimirArray(numeros,elem_utiles);
}
