/*
	2. Implementa una función que reciba un puntero a entero y que:
		(a) Eleve al cuadrado el dato apuntado.
		(b) Ponga a cero el puntero.
	
	Tal función podrı́a usarse de la siguiente forma:
		int a=6;
		int *q;
		q = &a;
		elevarAlCuadrado(q);
		cout << a << q; // Deberı́a salir 36 0
*/

#include <iostream>

using namespace std;

void elevarAlCuadrado(int *q){
	*q = *q * *q;
}

int main(){
	
	int a = 6, *q = &a;
	
	elevarAlCuadrado(q);
	q = 0;
	
	cout << a << endl << q;
}
