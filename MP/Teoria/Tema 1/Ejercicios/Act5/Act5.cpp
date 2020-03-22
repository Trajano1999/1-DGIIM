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

/*int BuscarMinimoArray(int vector[], const int& inicio, const int& final_){
	int min = inicio;
	
	for(int i = inicio; i<final_; i++)
		if(vector[i] < min)
			min = vector[i];
			
	return min;
}*/

void OrdenarPorInsercion(int vector[], const int& elem_utiles){
	int min, aux;
    
    for(int i = 0; i < elem_utiles-1; i++){
		min = i;
		for(int j = i+1; j<elem_utiles; j++)
			if(vector[min] > vector[j])
				min = j;
		aux = vector[min];
        vector[min] = vector[i];
        vector[i] = aux ;
    }
}

int main(){
	int vectorc[total_elem];
	int elem_utiles;
	
	cout << "Introduce el numero de elementos: ";
	cin >> elem_utiles;
	
	cout << "Introduce los valores del vector: " << endl;
	LeerArray(vectorc,elem_utiles);
	ImprimirArray(vectorc,elem_utiles);
	
	cout << "\n\nEl vector ordenado es: ";
	OrdenarPorInsercion(vectorc, elem_utiles);
	ImprimirArray(vectorc,elem_utiles);
}
