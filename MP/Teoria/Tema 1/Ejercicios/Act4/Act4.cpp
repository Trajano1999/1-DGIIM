#include <iostream>

using namespace std;

const int total_elem = 100;

void ImprimirArray(int vector[], const int& elem_utiles){
	cout << endl << elem_utiles << endl;
	
	for(int i = 0; i<elem_utiles; i++)
		cout << vector[i] << " ";
}

void LeerArray(int vector[], const int& elem_utiles){
	for(int i = 0; i<elem_utiles; i++)
		cin >> vector[i];
}

void InvertirArray(int vector[], const int& elem_utiles){
	for(int i = elem_utiles - 1; i>=0; i--)
		cout << vector[i] << " ";
}

int main(){
	int elem_utiles;
	int vectorc[total_elem];
	
	cout << "Introduce el numero de elementos (maximo 100): ";
	cin >> elem_utiles;
	
	clog << "Introduce los elementos del vector: " << endl;
	LeerArray(vectorc, elem_utiles);
	
	ImprimirArray(vectorc,elem_utiles);
	cout << endl;
	InvertirArray(vectorc,elem_utiles);
}
