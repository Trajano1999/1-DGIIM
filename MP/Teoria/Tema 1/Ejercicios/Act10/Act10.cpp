/*
	10. Haz un programa que lea un texto desde cin y que, al finalizar la entrada de datos,
	muestre cuantas veces aparece cada letra (a..z), teniendo en cuenta lo siguiente:
		
		- la entrada de datos finaliza con el caracter #.
		
		- no se diferenciaran mayusculas y minusculas.

		- el texto se lee caracter a caracter en una funcion que guarda los caracteres en un
		array de char recibido como parametro.
		
		- usaremos una funcion que reciba como parametro un array de caracteres y construya
		un array de enteros con la frecuencia para cada caracter.
*/

#include <iostream>

using namespace std;

const int total = 99;

void MostrarTexto(const char cadena[],const int& elem){
	for(int i = 0; i<elem; i++)
		cout << cadena[i];
}

void LeerTexto(char cadena[], int& numeroelem){
	char dato;
	int posicion = 0;

	cin >> dato;
	while(dato != '#'){
		numeroelem++;
		cadena[posicion] = dato;
		posicion++;
		cin >> dato;	
	}	
}

void TextoSinRepetir(char cadena[], const int& elem){
	
	for()

}

int main(){
	char cadena[total];
	int numeroelem = 0;

	cout << "Introduce un texto: " << endl;
	LeerTexto(cadena, numeroelem);
	
	cout << "El texto guardado es: " << endl;
	MostrarTexto(cadena,numeroelem);
	cout << endl;

	TextoSinRepetir(cadena,numeroelem);
}

/*
PARA SABER EL VALOR EN TABLA ASCII DE CUALQUIER CARACTER
cout << "Introduce un texto: ";
	char letra;
	cin >> letra;

	int numero = letra;

	cout << "Su valor de mierda en ASCII es: " << numero << endl;
*/