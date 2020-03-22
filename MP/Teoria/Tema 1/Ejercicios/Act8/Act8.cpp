/*
	Haz un programa que obtenga la mayor secuencia monótona creciente de un array 
	de enteros leído de la entrada estándar, guardándola en otro array que se 
	mostrará en la salida estándar.
*/

#include <iostream>

using namespace std;

const int total = 100;
	
void LeerArray(int v[], const int& elem_utiles){
	for(int i = 0; i<elem_utiles; i++)
		cin >> v[i];
}

void MostrarArray(const int v[], const int& elem_utiles){
	for(int i = 0; i<elem_utiles; i++)
		cout << v[i] << " ";
}

/*void MayorSecuenciaMonotonaArray(const int v[], const int& elem_utiles, int secuencia[], int& utiles_secuencia){ 	
	int pos = 0;
	int pos_max = 0, utiles_secuencia_max = 0;
	utiles_secuencia = 1;

	for(int i = 1; i<elem_utiles; i++){
		if(v[i] >= v[i-1])
			utiles_secuencia++;
		else{
			if(utiles_secuencia_max < utiles_secuencia){
				utiles_secuencia_max = utiles_secuencia;
				pos_max = pos;	
			}
			pos = i;
			utiles_secuencia = 1;
		}
	}

	for(int j = 0; j<utiles_secuencia_max; j++){
		secuencia[j] = v[pos_max+j];
	}
}*/

void MayorSecuenciaMonotonaArray(const int v[], const int & elem_utiles, int secuencia[], int & utiles_secuencia){ 
	int pos = 0, pos_max;
	int tamano = 1;
	utiles_secuencia = 0;
	
	for (int i = 1; i<elem_utiles; i++)
		if (v[i] >= v[i-1])
			tamano++;
		else{
			if(tamano > utiles_secuencia){
				utiles_secuencia = tamano;
				pos_max = pos;
			}
			pos = i;
			tamano = 1;
		}
	
	for( int i = 0; i<utiles_secuencia; i++)
		secuencia[i] = v[i+pos_max];
}

int main(){
	int v[total];
	int elem_utiles;
	
	cout << "Introduce el numero de elementos utiles: ";
	cin >> elem_utiles;
	
	cout << "Introduce los elementos del vector: " << endl;
	LeerArray(v, elem_utiles);
	clog << "El vector de los valores es: " << endl;
	MostrarArray(v,elem_utiles);
	
	int secuencia[total];
	int utiles_secuencia;
	
	MayorSecuenciaMonotonaArray(v,elem_utiles,secuencia,utiles_secuencia);
	cout << "\nLa mayor secuencia monotona es: " << endl;
	MostrarArray(secuencia,utiles_secuencia);
	cout << endl;
}

// [2,3,6,7,  1,2,3,5,9,10,  1,2,3]