/*
6. Dado un array de 10 elementos, haz un bucle que busque el máximo y el mı́nimo (sin usar el operador
[]). Al acabar el bucle tendremos un puntero apuntando a cada uno de ellos.
*/

#include <iostream>

using namespace std;

const int tamano = 10;

int main(){
	int array[tamano]={1,2,3,4,5,6,7,8,9,10};
	
	int *p = array;
	int *maximo = p, *minimo = p;
	
	for(int i = 0; i < tamano; i++)
		if(*maximo < *(p+i))
			maximo = (p+i);
			
	cout << "El maximo es: " << *maximo << endl;
	
	for(int i = 0; i<tamano; i++)
		if(*minimo > *(p+i))
			minimo = (p+i);
			
	cout << "El minimo es: " << *minimo;		
}
