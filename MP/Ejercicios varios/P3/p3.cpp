#include <iostream>

using namespace std;

struct Celda{
	double valor;
	Celda* puntero;
};

int main(int narg, char* argv[]){
	Celda lista;
	double valor;
	
	cin >> valor;
	lista = 0;
	while(valor != 0.0){
		Celda* aux = new Celda;
		aux->valor = valor;
		aux->puntero = lista;
		lista = aux;
		cin >> valor;
	}
	
	//Mostrar lista
	
	aux = lista;
	while(aux != 0){
		cout << aux->dato;
		aux = aux->puntero;
	}
	cout << endl;
	
	//Destruccion de lista
	
	while(lista != 0){
		Celda* aux= lista;
		lista=aux->puntero;
		delete aux;
	}
	
	return 0;
}
