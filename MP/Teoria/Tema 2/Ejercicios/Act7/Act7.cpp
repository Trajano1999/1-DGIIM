/*
7. Implemente las siguientes funciones sobre cadenas de caracteres estilo C usando aritmética de punteros
(sin usar el operador []):
	(a) Función comparar_cadenas que compara dos cadenas. Devuelve un valor negativo si la primera es
		más pequeña, positivo si es más grande y cero si son iguales.
	(b) Función insertar_cadena que inserte una cadena dentro de otra, en una posición dada.
		Se supone que hay suficiente memoria en la cadenas de destino.
*/

#include <iostream>

using namespace std;

const int tamano = 80;

void LeerCadena(char vector[], int& util){
	char caracter;
	
	cin >> caracter;
	while(caracter != '#'){
		for(int i = 0; i<tamano; i++){
			vector[i] = caracter;
			util++;
		}
		cin >> caracter;
	}
}

void MostrarCadena(char vector[], const int& util){
	for(int i = 0; i<util; i++)
		cout << vector[i] << " "; 
}

int CompararCadenas(const char *v1, const char *v2){
	const char *p1, *p2;
	int resultado = 0, elem1 = 0, elem2 = 0;
	
	for(p1=v1; *p1 != '\0'; p1++)
		elem1++;
		
	for(p2=v2; *p2 != '\0'; p2++)
		elem2++;
		
	if(elem1 > elem2)
		resultado = -1;
	if(elem1 < elem2)
		resultado = 1;
		
	return resultado;	
}

void InsertarCadena(const char *v1, const char *cadena, const int& pos){
	for(int i = 0; i<pos; i++)
		cout << *(v1+i);
	
	cout << cadena;
	cout << v1+pos;	
}

int main(){
	int posicion = 0;
	int util1 = 0, util2 = 0, util3 = 0;
	char vector1[tamano], vector2[tamano], cadena[tamano];
	
	cout << "Introduce la primera sentencia (finalizar con #): ";
	LeerCadena(vector1, util1);
	MostrarCadena(vector1, util1);
	
/*	cout << "Introduce la segunda sentencia (finalizar con #): ";
	LeerCadena(vector2, util2);
	
	cout << "Introduce la cadena que quieras agregar: ";
	LeerCadena(cadena, util3);
	
	cout << "Introduce la posicion donde desea introducir la nueva cadena: ";
	cin >> posicion;
	
	CompararCadenas(vector1, vector2);
	InsertarCadena(vector1, cadena, posicion);*/
}

/*int main(){
	int posicion = 0;
	const char *vector1="Hola soy Juanma";
	const char *vector2="Encantado de conocerte";
	
	const char *cadena="SOY PEPE ";
	cout << "Introduce la posicion donde desea introducir la nueva cadena: ";
	cin >> posicion;
	
	CompararCadenas(vector1, vector2);
	InsertarCadena(vector1, cadena, posicion);
}*/
