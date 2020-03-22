/** 
 * @file   intervalo.cpp
 * @author Juan Manuel Mateos Pérez
 *
 */

#include <iostream>
#include <assert.h>

using namespace std;

class Intervalo{
	private:
		double cotainf;
		double cotasup;
		bool cerradoinf;
		bool cerradosup;
		
		/**
		 * @brief comprueba que los argumentos definen un intervalo correcto
		 * @param cotaInferior
		 * @param cotaSuperior
		 * @param cerradoInferior
		 * @param cerradoSuperior
		 * @pre cotaInferior < cotaSuperior 
		 * @pre cotaInferior == cotaSuperior && cerradoInferior == cerradoSuperior 
		 * @return @retval true si correcto @retval false en otro caso
		*/
		bool validar(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
	
	public:
		/** 
		 *  @brief Crea un intervalo vacio 
		*/
		Intervalo();
		
		/** 
		 * @brief Crea un Intervalo cerrado 
		 * @param cotaInferior
		 * @param cotaSuperior
		 * @pre El intervalo es válido
		*/
		Intervalo(double cotaInferior, double cotaSuperior);
		
		/** 
		 * @brief Crea un intervalo cualquiera 
		 * @param cotaInferior
		 * @param cotaSuperior
		 * @param cerradoInferior
		 * @param cerradoSuperior
		 * @pre El intervalo es válido
		*/
		Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
		
		/** 
		 * @brief Devuelve la cota inferior del intervalo
		 * @return El valor de la cota
		*/
		double getCotaInf()const;
		
		/** 
		 * @brief Devuelve la cota superior del intervalo
		 * @return El valor de la cota
		*/
		double getCotaSup()const;
		
		/** 
		 * @brief Consulta si el intervalo es cerrado en su cota inferior
		 * @return @retval true si es cerrado @retval false si es cerrado
		*/
		bool esCerradoInf()const;
		
		/** 
		 * @brief Consulta si el intervalo es cerrado en su cota superior
		 * @return @retval true si es cerrado @retval false si es cerrado
		*/
		bool esCerradoSup()const;
		
		/** 
		 * @brief Consulta si el intervalo almacenado es vacío o no
		 * @return @retval true si es un intervalo vacío, @retval false en otro caso 
		*/
		bool esVacio()const;
		
		/** 
		 * @brief Consulta si un determinado valor está dentro del intervalo
		 * @param n El valor consultado
		 * @return @retval true si el valor @p n pertenece al intervalo, @retval false en otro caso 
		*/
		bool estaDentro(double n)const;
		
};

bool Intervalo::validar(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
	return (cotaInferior < cotaSuperior || (cotaInferior == cotaSuperior && cerradoInferior == cerradoSuperior));
}

Intervalo::Intervalo(){
	cotainf = 0;
	cotasup = 0;
	cerradoinf = false;
	cerradosup = false;
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior){
	assert (validar(cotaInferior,cotaSuperior, true, true));
	
	cotainf = cotaInferior;
	cotasup = cotaSuperior;
	cerradoinf = true;
	cerradosup = true;
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
	assert (validar(cotaInferior,cotaSuperior, cerradoInferior, cerradoSuperior));
	
	cotainf = cotaInferior;
	cotasup = cotaSuperior;
	cerradoinf = cerradoInferior;
	cerradosup = cerradoSuperior;
}

double Intervalo::getCotaInf()const {
	return cotainf;
}

double Intervalo::getCotaSup()const {
	return cotasup;
}

bool Intervalo::esCerradoInf()const {
	return cerradoinf;
}

bool Intervalo::esCerradoSup()const {
	return cerradosup;
}

bool Intervalo::esVacio()const {
	return (cotainf == cotasup && !cerradoinf && !cerradosup);
}

bool Intervalo::estaDentro(double n)const {
	bool pertenece = false;
	
	if(cerradoinf && cerradosup){
		if(n >= cotainf && n <= cotasup)
			pertenece = true;
	}else{
		if(!cerradoinf && !cerradosup){
			if(n > cotainf && n < cotasup)
				pertenece = true;
		}else{
			if(cerradoinf && !cerradosup){
				if(n >= cotainf && n < cotasup)
					pertenece = true;
			}else{
				if(n > cotainf && n <= cotasup)
					pertenece = true;
			}
		}
	}
	return pertenece;
}

//FIN DE LA CLASE
//FUNCIONES AUXILIARES

/** 
* @brief Imprime los valores de un intervalo de forma visual según lo indicado en el guión
* @param i El intervalo
*/
void escribir(const Intervalo &i){
	if(i.esCerradoInf())
		cout << " [";
	else
		cout <<" (";
  
	cout << i.getCotaInf() << " , " << i.getCotaSup();
  
	if(i.esCerradoSup())
		cout << "] ";
	else
		cout << ") ";
	cout << endl;  
}

/** 
* @brief Lee los valores del intervalo según el formato indicado en el guión
* @param i El intervalo
*/
void leer(Intervalo &i){
	char signo_inicial, signo_final, coma;
	double cota1, cota2;
	bool cerradoinferior = false, cerradosuperior = false;
	
	cin >> signo_inicial >> cota1 >> coma >> cota2 >> signo_final;
	
	if(signo_inicial == '[')
		cerradoinferior = true;
	if(signo_final == ']')
		cerradosuperior = true;
		
	Intervalo intervalito(cota1,cota2,cerradoinferior,cerradosuperior);
	i = intervalito;
}

int main(){
	int nintervalos;
	Intervalo vacio;
	Intervalo punto(1,1);
	Intervalo interv[10];

	// Lectura de datos
	cout << "Cuantos intervalos se van a introducir? (max 10): ";
	do{
		cin >> nintervalos;
	} while(nintervalos > 10);

	cout << "Introduce [ o ( cotaInferior, cotaSuperior ) o ]" << endl;
	for(int i = 0; i < nintervalos; i++)
		leer(interv[i]);

	// Comprobaciones
	clog << endl << "Comprobando intervalo vacio" << endl;
	escribir(vacio);
	if (vacio.esVacio())
		cout << " Es vacío " << endl;
	else
		cout << " No es vacío " << endl;
	cout << endl;
	escribir(punto);
	if (punto.esVacio())
		cout << " Es vacío " << endl;
	else
		cout << " No es vacío " << endl;
	cout << endl;
	
	// Dado un conjunto de valores −1, −0.001, 0, 5.7, 9.6, 10
	double v[]= {-1, -0.001, 0, 5.7, 9.6, 10};
	int numvalores = 6;
	
	for(int i = 0; i < nintervalos; i++){
		escribir(interv[i]);
		cout << "Valores dentro del intervalo: ";
		for(int j = 0; j < numvalores; j++){
			if(interv[i].estaDentro(v[j]))
				cout << v[j] << " ";
		}
		cout << endl << "Valores fuera del intervalo: ";
		for (int j= 0; j < numvalores; j++){
			if (!interv[i].estaDentro(v[j]))
				cout << v[j] <<" ";
		}
		cout << endl;
	}
	return 0; 

}
