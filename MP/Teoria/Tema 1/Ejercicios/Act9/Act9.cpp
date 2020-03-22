/*
	9. Implemente una funcion mezclarUnico de tipo int que reciba como entrada dos arrays
	ordenados de datos de tipo double y los mezcle en un tercer array. Tenga en cuenta que:
		
		Los arrays de entrada estan ordenados y sin valores repetidos.
		
		El array de salida tendra los elementos ordenados y sin repetidos.
		Puede asumir que el array de salida tiene capacidad suficiente para todos los elementos.
		
		La funcion devuelve un entero que es el numero de elementos que contiene el array de salida.

		Nota: Sera menor o igual que la suma de los de entrada.
*/

#include <iostream>

using namespace std;

const int total = 100;

void Intercambiar(int& a, int& b){
	int aux = a;
	a = b;
	b = aux;
}

void LeerArray(int v[], const int& elem_utiles){
	for(int i = 0; i<elem_utiles; i++)
		cin >> v[i];
}

void MostrarVector(int v[], const int& elem_utiles){
	for (int i = 0; i<elem_utiles; i++)
		cout << v[i] << " ";
	cout << endl;
}

void OrdenarArray(int v[], const int& elem_utiles){
	int min, aux;
    
    for (int i = 0; i < elem_utiles-1; i++){
		min = i;
		for (int j = i+1; j < elem_utiles; j++)
			if(v[min] > v[j])
		    	min = j;
		Intercambiar(v[min], v[i]);
	}
}

void EliminarRepetidosArray(int v[], int& elem_utiles){
	int lectura = 1, escritura = 1;

	while(lectura < elem_utiles){
		if(v[lectura] != v[lectura-1]){
			v[escritura] = v[lectura];
			lectura++;
			escritura++;
		}else
			lectura++;
	}
	elem_utiles = escritura;
}

int MezclarUnico(const int v[], const int w[], const int& utiles_v, const int& utiles_w){
	int resultado[total];
	int elem_utiles = utiles_v + utiles_w;

	for(int i = 0; i<utiles_v; i++)
		resultado[i] = v[i];
	for(int i = 0; i<utiles_w; i++)
		resultado[i+utiles_v] = w[i];

	OrdenarArray(resultado,elem_utiles);
	EliminarRepetidosArray(resultado,elem_utiles);

	return elem_utiles;
}

/*
util_mezcla = 0;
int i_v = 0, i_w = 0; //Indices

while(i_v < util_v || i_w < util_w){
	if(v[i_v] > w[i_w] && !Existe(w[i_w],mezcla,util_mezcla)){
		mezcla[util_mezcla] = w[i_w];
		i_w++;
		util_mezcla++;
	}else
		if(!Existe(v[i_v],mezcla,util_mezcla)){
			mezcla[util_mezcla] = v[i_v];
			i_v++;
			util_mezcla++;
		}
	return util_mezcla;
}
*/

int main(){
	int vector[total];
	int elem_utiles;

	cout << "Introduce el numero de elementos utiles del primer vector: ";
	cin >> elem_utiles;

	cout << "Introduce los elementos del primer vector: " << endl;
	LeerArray(vector,elem_utiles);
	OrdenarArray(vector,elem_utiles);
	EliminarRepetidosArray(vector,elem_utiles);

	cout << "Los valores del primer vector son: " << endl;
	MostrarVector(vector,elem_utiles);

	int v2[total];
	int elem_utiles2;

	cout << "Introduce el numero de elementos utiles del segundo vector: ";
	cin >> elem_utiles2;

	cout << "Introduce los elementos del segundo vector: " << endl;
	LeerArray(v2,elem_utiles2);
	OrdenarArray(v2,elem_utiles2);
	EliminarRepetidosArray(v2,elem_utiles2);

	cout << "Los valores del segundo vector son: " << endl;
	MostrarVector(vector,elem_utiles);

	cout << "El tamaño del vector mezcla es: " << MezclarUnico(vector,v2,elem_utiles,elem_utiles2) << endl;

	return 0;
}