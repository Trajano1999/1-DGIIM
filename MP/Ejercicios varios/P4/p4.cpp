#include <iostream>
#include <fstream>
#include <cmath>
#include <assert.h>

using namespace std;

class Polinomio{
	private:
		double* coeficientes;
		int maximogrado;
		
		void liberarmemoria();
		void reservarmemoria(int n);
		void copiar(const Polinomio& mi_polinomio);
	public:
		Polinomio();
		Polinomio(int maximogrado);
		Polinomio(const Polinomio& mi_polinomio);
		~Polinomio();
		Polinomio& operator=(const Polinomio& mi_polinomio);
		inline int getMaximogrado() const;
		inline double getCoeficiente(int pos) const;
		void setCoeficiente(int pos, double valor);
		Polinomio operator+(const Polinomio& polinomio);
		
		friend ostream& operator<<(ostream& flujo, const Polinomio& p);
		friend istream& operator>>(istream& flujo, Polinomio& p);
};

//PRIVATE

void Polinomio::liberarmemoria(){
	if(coeficientes != 0){
		delete [] coeficientes;
		coeficientes = 0;
	}
	maximogrado = 0;
}

void Polinomio::reservarmemoria(int n){
	coeficientes = new double[n];
}

void Polinomio::copiar(const Polinomio& mi_polinomio){
	coeficientes = mi_polinomio.coeficientes;
	maximogrado = mi_polinomio.maximogrado;
}

//PUBLIC

Polinomio::Polinomio(){
	coeficientes = 0;
	maximogrado = 0;
}

Polinomio::Polinomio(int maximogrado){
	assert(maximogrado >= 0);
	
	(*this).maximogrado = maximogrado;
	coeficientes = new double[maximogrado+1];
	
	for(int i=0; i<maximogrado+1; i++)
		coeficientes[i] = 0.0;
}

Polinomio::Polinomio(const Polinomio& mi_polinomio){
	copiar(mi_polinomio);
}

Polinomio::~Polinomio(){
	liberarmemoria();
}

Polinomio& Polinomio::operator=(const Polinomio& mi_polinomio){
	copiar(mi_polinomio);
	return (*this);
}

inline int Polinomio::getMaximogrado() const{
	return maximogrado;
}

inline double Polinomio::getCoeficiente(int pos) const{
	assert(pos <= maximogrado);
	return coeficientes[pos];
}

void Polinomio::setCoeficiente(int pos, double valor){
	if(pos > maximogrado){
		double* vector;
		vector = new double[pos+1];
		
		for(int i=0; i<=maximogrado; i++)
			vector[i] = coeficientes[i];
		vector[pos] = valor;
		
		delete [] coeficientes;
		coeficientes = vector;
		vector = 0;
		maximogrado = pos;		
	}else
		if(pos == maximogrado && valor == 0){
			Polinomio aux;
			aux.coeficientes = new double[maximogrado];
			for(int i=0; i<maximogrado; i++)
				aux.coeficientes[i] = coeficientes[i];
			maximogrado--;
		}else
			coeficientes[pos] = valor;
}

Polinomio Polinomio::operator+(const Polinomio& p){
	Polinomio resultado;
	
	if(maximogrado >= p.maximogrado)
		resultado.maximogrado = maximogrado;
	else
		resultado.maximogrado = p.maximogrado;
		
	for(int i=0; i<resultado.maximogrado+1; i++)
		resultado.coeficientes[i] = coeficientes[i] + p.coeficientes[i];
		
	return resultado;	
}

/*
	Polinomio operator+(const Polinomio& p1, const Polinomio& p2){
		Polinomio resultado;
	
		if(p1.maximogrado >= p2.maximogrado)
			resultado.maximogrado = p1.maximogrado;
		else
			resultado.maximogrado = p2.maximogrado;
		
		for(int i=0; i<resultado.maximogrado+1; i++)
			resultado.coeficientes[i] = p1.coeficientes[i] + p2.coeficientes[i];
		
		return resultado;	
	} 
 */

//FUNCIONES AUXILIARES

ostream& operator<<(ostream& flujo, const Polinomio& p){
	for(int i=p.maximogrado; i>=0; i--){
		if(p.coeficientes[i] >= 0)
			flujo << "+" << p.coeficientes[i] << "x^" << i;
		else
			flujo << "-" << abs(p.coeficientes[i]) << "x^" << i;
	}
	return flujo;
}

istream& operator>>(istream& flujo, Polinomio& p){
	p.liberarmemoria();
	
	double coef;
	int valor;
	char signo;
	
	flujo >> signo >> coef >> signo >> signo >> p.maximogrado;
	p.reservarmemoria(p.maximogrado+1);
	
	for(int i=p.maximogrado; i>=0; i--)
		flujo >> signo >> p.coeficientes[i] >> signo >> signo >> valor;
	
	return flujo;
}

//----------------------------------------------------------------------

int main(int narg, char* agrv[]){
	Polinomio p1(3);
	p1.setCoeficiente(3,6);
	p1.setCoeficiente(1,-4);
	p1.setCoeficiente(1,-2);
	cout << p1;
	return 0;
}
