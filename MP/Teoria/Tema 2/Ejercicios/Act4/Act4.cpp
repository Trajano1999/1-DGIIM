/*
4. Declare una variable v como un array de 1000 enteros. Escriba un trozo de código que recorra el array y
	modique todos los enteros negativos cambiándolos de signo. No se permite usar el operador [], es decir, el
	recorrido se efectuará usando aritmética de punteros y el bucle se controlará mediante un contador entero.
*/

#include <iostream>

using namespace std;

const int tamano = 10;

int main(){
	int vector[tamano] = {1,-4,6,-2,3,6,8,-5,-6,10};
	int *p = vector;
	
	for(int i = 0; i<tamano; i++)
		if(*(p+i) < 0)
			*(p+i) = *(p+i) * (-1);
	
	for(int i = 0; i<tamano; i++)
		cout << *(p+i) << " ";
}
