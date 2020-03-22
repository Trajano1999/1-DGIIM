#include <iostream>

using namespace std;

const int total_elem = 100;

void ImprimirArray(int vector[], const int& elem_utiles){
	cout << elem_utiles << endl; 
	
	for(int i = 0; i<elem_utiles; i++)
		cout << vector[i] << " "; 
}

void LeerArray(int vector[], const int& elem_utiles){
	for(int i = 0; i<elem_utiles; i++)
		cin >> vector[i];
}

bool ExisteElemento(const int& elemento, int vector[], const int& inicial, const int& final_){
	bool existe = false;
	
	for(int i = inicial; i<=final_ && !existe; i++)
		if(elemento == vector[i])
			existe = true;
			
	return existe;		
}

void EliminarRepetidosArray2(int vector[], int& elem_utiles){
	for(int i = 0; i<elem_utiles; )
		if(ExisteElemento(vector[i], vector, 0, i-1)){
			for(int j = i; j<elem_utiles-1; j++)
				vector[j] = vector[j+1];
			elem_utiles--;	
		}else
			i++;
}

void EliminarRepetidosArray(int v[], const int& utiles_v, int w[], int& utiles_w){
	utiles_w = 1;
	w[0] = v[0];
	
	for(int i = 1; i<utiles_v; i++)
		if(!ExisteElemento(v[i], v, 0, i-1)){
			w[utiles_w] = v[i];
			utiles_w++;
		}
}

int main(){
	int vectorc[total_elem];
	int elem_utiles;
	
	cout << "Introduce el numero de elementos del vector: ";
	cin >> elem_utiles;
	
	cout << "Introduce los valores del vector: " << endl;
	LeerArray(vectorc, elem_utiles);
	
	cout << "Los valores del vector son: " << endl;
	ImprimirArray(vectorc, elem_utiles);
	
	int no_repes[total_elem];
	int utiles_no_repes;
	
	EliminarRepetidosArray(vectorc, elem_utiles, no_repes, utiles_no_repes);
	cout << "\n\nEl vector sin repetir es (1ª funcion): " << endl;
	ImprimirArray(no_repes,utiles_no_repes);
	
	EliminarRepetidosArray2(vectorc, elem_utiles);
	cout << "\n\nEl vector sin repetir es (2ª funcion): " << endl;
	ImprimirArray(vectorc, elem_utiles);
}
