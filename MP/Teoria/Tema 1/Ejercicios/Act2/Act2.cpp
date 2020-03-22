#include <iostream>

using namespace std;

const int total_elem = 100;

void ImprimirArray(int vector[],const int& elem){
	cout << endl << elem << endl;
	
	for(int i = 0; i<elem; i++)
		cout << vector[i] << " ";
} 

void LeerArray(int vector[], const int& total_elem, int& elem_utiles){
	for(int i = 0; i<elem_utiles; i++){
		cout << "Elemento " << i << " : ";
		cin >> vector[i]; 
	}
}

int BuscarMinimoArray(int vector[], const int& pos_elem_inicial, const int& pos_elem_final){
	int pos_min = 0, min = vector[pos_elem_inicial];
	
	for(int i = 0; i < pos_elem_final; i++)
		if(vector[i] < min){
			min = vector[i];
			pos_min = i;
		}

	return pos_min;
}

/*int BuscarMinimoArray(int vector[], const int& inicial, const int& elem_final, const int elem_utiles){
	int pos_min = 0, min = inicial;
	
	for(int i = 0; i < elem_utiles; i++)
		if(vector[i] < min){
			min = vector[i];
			pos_min = i;
		}
	
	return pos_min;
}*/

int main(){
	int elem_utiles, valores;
	int vectorc[total_elem];
	
	cout << "Numero de elementos (maximo 100): ";
	cin >> elem_utiles;
	
	LeerArray(vectorc,total_elem,elem_utiles);
	
	cout << "\nEl vector leido es: " << endl;
	ImprimirArray(vectorc,elem_utiles);
	int pos_min = BuscarMinimoArray(vectorc, 0, elem_utiles);
	
	cout << "\n\nMinimo: " << vectorc[pos_min]; 
	
	return 0;
}
