#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct Infociudad{
	char* nombre;
	int poblacion;
};

class Redciudades{
	private:
		int num_ciudades;
		Infociudad* info;
		double** distancia;
		
		void liberarmemoria();
		void reservarmemoria(int n);
		void copiar(const Redciudades& la_redciudad);
		
	public:
		Redciudades();
		Redciudades(const char* fichero);
		Redciudades(const Redciudades& la_redciudad);
		~Redciudades();
		Redciudades& operator=(const Redciudades& la_redciudad);
		int Numciudades() const;
		int Distancia(int a, int b) const;
		int Distancia(const Infociudad& la_ciudad1, const Infociudad& la_ciudad2) const;	
		char* Nombreciudad(const Infociudad& la_ciudad) const;
		int Poblacionciudad(const Infociudad& la_ciudad) const;
		Redciudades Leerredciudades(const char* fichero);
		bool Escribirredciudades(const char* fichero) const;
		int CiudadMejorConectada() const;
		int MejorEscalaEntre(int a, int b) const;
		
		friend ostream& operator<<(ostream& flujo, const Redciudades& la_redciudad);
		friend istream& operator>>(istream& flujo, Redciudades& la_redciudad);
};

//PRIVATE

void Redciudades::liberarmemoria(){
	num_ciudades = 0;
	
	for(int i=0; i<num_ciudades; i++)
		delete [] info[i].nombre;
	delete [] info;
	info = 0;
	
	for(int i=0; i<num_ciudades; i++)
		delete [] distancia[i];
	delete [] distancia; 
	distancia = 0;
}

void Redciudades::reservarmemoria(int n){
	liberarmemoria();
	num_ciudades = n;
	info = new Infociudad[n];
	distancia = new double* [n];
	
	for(int i=0; i<n; i++)
		distancia[i] = new double[n];
}

void Redciudades::copiar(const Redciudades& la_redciudad){
	num_ciudades = la_redciudad.num_ciudades;
	
	for(int i=0; i<num_ciudades; i++){
		info[i].poblacion = la_redciudad.info[i].poblacion;
		strcpy(la_redciudad.info[i].nombre,info[i].nombre);
	}
	
	for(int i=0; i<num_ciudades; i++)
		for(int j=0; j<num_ciudades; j++)
			distancia[i][j] = la_redciudad.distancia[i][j];
}

//PUBLIC

Redciudades::Redciudades(){
	num_ciudades = 0;
	info = 0;
	distancia = 0;
}

Redciudades::Redciudades(const char* fichero){
	char primera_linea[4];
	
	ifstream fentrada;
	fentrada.open(fichero);
	if(fentrada){
		fentrada >> primera_linea;
		if(strcmp(primera_linea,"RED") == 0){
			fentrada >> *this;			
		}else
			cerr << "Se ha producido un fallo en la lectura de " << fichero << endl;
	}else
		cerr << "Se ha producido un fallo en la apertura de " << fichero << endl;
	
	fentrada.close();
}

Redciudades::Redciudades(const Redciudades& la_redciudad){
	copiar(la_redciudad);
}

Redciudades::~Redciudades(){
	liberarmemoria();
}

Redciudades& Redciudades::operator=(const Redciudades& la_redciudad){
	copiar(la_redciudad);
	return *this;
}

int Redciudades::Numciudades()const{
	return num_ciudades;
}

int Redciudades::Distancia(int a, int b) const{
	return distancia[a][b];
}

int Redciudades::Distancia(const Infociudad& la_ciudad1, const Infociudad& la_ciudad2) const{
	if(info != 0){
		int pos_i = -1, pos_j = -1;
		int aux = -1;
		
		for(int i=0; i<num_ciudades; i++)
			if(info[i].nombre == la_ciudad1.nombre && info[i].poblacion == la_ciudad1.poblacion)
				pos_i = i;
				
		for(int j=0; j<num_ciudades; j++)
			if(info[j].nombre == la_ciudad2.nombre && info[j].poblacion == la_ciudad2.poblacion)
				pos_j = j;
				
		if(pos_i != -1 && pos_j != -1)
			aux = distancia[pos_i][pos_j];
		return aux;
	}else
		return -1;
}

char* Redciudades::Nombreciudad(const Infociudad& la_ciudad) const{
	return la_ciudad.nombre;
}

int Redciudades::Poblacionciudad(const Infociudad& la_ciudad) const{
	return la_ciudad.poblacion;
}

Redciudades Redciudades::Leerredciudades(const char* fichero){
	this->liberarmemoria();
	Redciudades redciudad(fichero);
	return redciudad;
}

bool Redciudades::Escribirredciudades(const char* fichero) const{
	bool salida = false;
	
	ofstream fsalida;
	fsalida.open(fichero);
	if(fsalida){
		cout << "RED" << endl << *this;
		salida = true;
	}else
		cerr << "Se ha producido un fallo en la apertura de " << fichero << endl;
	
	fsalida.close();
	return salida;
}

int Redciudades::CiudadMejorConectada() const{
	int conexiones = 0, mayor_conexion = 0, pos=0;
	
	for(int i=0; i<num_ciudades; i++){
		conexiones = 0;
		for(int j=0; j<num_ciudades; j++){
			if(distancia[i][j] > 0)
				conexiones++;
			if(conexiones > mayor_conexion){
				mayor_conexion = conexiones;
				pos = i;
			}
		}
	}

	return pos+1;
}

int Redciudades::MejorEscalaEntre(int a, int b) const{
	int contador = 0, min_contador = distancia[a-1][0] + distancia[b-1][0];
	int pos=-2;
	
	for(int i=0; i<num_ciudades; i++){
		contador = distancia[a-1][i] + distancia[b-1][i];
		if(contador > 0 && contador <= min_contador){
			min_contador = contador;
			pos = i;
		}
	}
	return pos+1;
}

//FUNCIONES ADICIONALES

ostream& operator<<(ostream& flujo, const Redciudades& la_redciudad){
	flujo << la_redciudad.num_ciudades << endl;
	
	for(int i=0; i<la_redciudad.num_ciudades; i++)
		flujo << i << " " << la_redciudad.info[i].nombre << " " << la_redciudad.info[i].poblacion << endl;
	
	for(int i=0; i<la_redciudad.num_ciudades; i++)
		for(int j=0; j<la_redciudad.num_ciudades; j++)
			flujo << i << " " << j << la_redciudad.distancia[i][j];
	return flujo;
}

istream& operator>>(istream& flujo, Redciudades& la_redciudad){
	la_redciudad.liberarmemoria();
	flujo >> la_redciudad.num_ciudades;
	la_redciudad.reservarmemoria(la_redciudad.num_ciudades);

	int numCiudad;
	string cadena;
	
	for(int i=0; i<la_redciudad.num_ciudades; i++){
		flujo >> numCiudad >> cadena;
		la_redciudad.info[numCiudad].nombre = new char[cadena.size()];
		for(int j=0; j<cadena.size(); j++)
			la_redciudad.info[numCiudad].nombre[j] = cadena[j];
		flujo >> la_redciudad.info[numCiudad].poblacion;
	}
	
	return flujo;
}

int main(int narg, char* argv[]){
	Redciudades redciudad(argv[1]);
	int contador=0;
	int i, j;
	
	for(i=0; i<redciudad.Numciudades(); i++)
		for(int j=0; j<redciudad.Numciudades(); j++)
			if(redciudad.Distancia(i,j) != -1)
				contador = redciudad.MejorEscalaEntre(i,j);
	
	if(contador != -1)
		cout << "La mejor escala entre la ciudad " << i+1 << " y la ciudad " << j+1 << " es " << contador << endl;
	else
		cout << "NO hay mejor escala entre la ciudad " << i+1 << " y la ciudad " << j+1 << endl;
	
	return 0;
}
