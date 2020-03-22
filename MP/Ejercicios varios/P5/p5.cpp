#include <iostream>

using namespace std;

class Entrada{
	private: 
		char* entrada;
		int frecuencia;
		
		void limpiarmemoria();
		void reservarmemoria(int n);
		void copiar(const Entrada& entradita);
	public:
		Entrada();
		Entrada(const Entrada& entradita);
		~Entrada();
		Entrada& operator=(const Entrada& entradita);
		Entrada operator+(const Entrada& entradita);
		
		friend ostream& operator<<(ostream& flujo, const Entrada& entradita);
		friend istream& operator>>(istream& flujo, Entrada& entradita);
};

void Entrada::limpiarmemoria(){
	delete [] entrada;
	entrada = 0;
	frecuencia = 0;
}

void Entrada::reservarmemoria(int n){
	entrada = new char[n];
}

void Entrada::copiar(const Entrada& entradita){
	entrada = entradita.entrada;
	frecuencia = entradita.frecuencia;
}

Entrada::Entrada(){
	entrada = 0;
	frecuencia = 0;
}

Entrada::Entrada(const Entrada& entradita){
	copiar(entradita);
}

Entrada::~Entrada(){
	limpiarmemoria();
}

Entrada& Entrada::operator=(const Entrada& entradita){
	limpiarmemoria();
	copiar(entradita);
	return (*this);
}

Entrada Entrada::operator+(const Entrada& entradita){
	Entrada resultado;
	
	resultado.frecuencia = frecuencia + entradita.frecuencia;
	resultado.reservarmemoria(resultado.frecuencia);
	
	for(int i=0; i<frecuencia; i++)
		resultado.entrada[i] = entrada[i];
	for(int i=0; i<entradita.frecuencia; i++)
		resultado.entrada[i+frecuencia] = entradita.entrada[i];
		
	return resultado;
}

ostream& operator<<(ostream& flujo, const Entrada& entradita){
	for(int i=0; i<entradita.frecuencia; i++)
		flujo << entradita.entrada[i] << " " << entradita.frecuencia << endl;
	return flujo;
}

istream& operator>>(istream& flujo, Entrada& entradita){
	entradita.limpiarmemoria();
	flujo >> entradita.frecuencia;
	entradita.reservarmemoria(entradita.frecuencia);
	
	for(int i=0; i<entradita.frecuencia; i++)
		flujo >> entradita.entrada[i];
	return flujo;
}

//----------------------------------------------------------------------

class Frecuencias{
	private:
		Entrada* entradas;
		int nEntradas;
		
		void liberarmemoria();
		void reservarmemoria(int n);
		void copiar(const Frecuencias& f);
	public:
		Frecuencias();
		Frecuencias(const Frecuencias& f);
		~Frecuencias();
		Frecuencias& operator=(const Frecuencias& f);
		Frecuencias operator+(const Frecuencias& f);
		
		friend ostream& operator<<(ostream& flujo, const Frecuencias& f);
		friend istream& operator>>(istream& flujo, Frecuencias& f);
};

void Frecuencias::liberarmemoria(){
	delete [] entradas;
	entradas = 0;
	nEntradas = 0;
}

void Frecuencias::reservarmemoria(int n){
	entradas = new Entrada[n];
}

void Frecuencias::copiar(const Frecuencias& f){
	reservarmemoria(f.nEntradas);
	nEntradas = f.nEntradas;
	
	for(int i=0; i<f.nEntradas; i++)
		entradas[i] = f.entradas[i];
}

Frecuencias::Frecuencias(){
	entradas = 0;
	nEntradas = 0;
}

Frecuencias::Frecuencias(const Frecuencias& f){
	copiar(f);	
}

Frecuencias::~Frecuencias(){
	liberarmemoria();
}

Frecuencias& Frecuencias::operator=(const Frecuencias& f){
	liberarmemoria();
	copiar(f);
	return (*this);
}

Frecuencias Frecuencias::operator+(const Frecuencias& f){
	Frecuencias resultado;
	
	resultado.nEntradas = nEntradas + f.nEntradas;
	resultado.reservarmemoria(resultado.nEntradas);
	
	for(int i=0; i<nEntradas; i++)
		resultado.entradas[i] = entradas[i];
	for(int i=0; i<f.nEntradas; i++)
		resultado.entradas[i + nEntradas] = f.entradas[i];
		
	return resultado;
}

ostream& operator<<(ostream& flujo, const Frecuencias& f){
	flujo << f.nEntradas << endl;
	for(int i=0; i<f.nEntradas; i++)
		flujo << f.entradas[i];
	return flujo;
}

istream& operator>>(istream& flujo, Frecuencias& f){
	f.liberarmemoria();
	flujo >> f.nEntradas;
	f.reservarmemoria(f.nEntradas);
	
	for(int i=0; i<f.nEntradas; i++)
		flujo >> f.entradas[i];
	return flujo;
}

//----------------------------------------------------------------------

int main(int narg, char* agrv[]){
	return 0;
}
