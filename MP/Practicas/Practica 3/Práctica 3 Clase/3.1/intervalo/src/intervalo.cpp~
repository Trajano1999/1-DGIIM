/** 
 * @file   intervalo.cpp
 * @author Juan Manuel Mateos Pérez
 *
 */

#include <iostream>
#include <assert.h>

#include "intervalo.h"

using namespace std;

bool Intervalo::validar(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior) const{
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

Intervalo interseccion(const Intervalo &i1, const Intervalo &i2){
	double cotainfir, cotasupir;
	bool cerradoinfir, cerradosupir; 

	if(i1.getCotaInf() > i2.getCotaInf()){
		cotainfir = i1.getCotaInf();
		cerradoinfir = i1.esCerradoInf();
	}else{
		cotainfir = i2.getCotaInf();
		cerradoinfir = i2.esCerradoInf();
	}

	if(i1.getCotaSup() < i2.getCotaSup()){
		cotasupir = i1.getCotaSup();
		cerradosupir = i1.esCerradoSup();
	}else{
		cotasupir = i2.getCotaSup();
		cerradosupir = i2.esCerradoSup();
	}
	
	if(i1.validar(cotainfir,cotasupir, cerradoinfir, cerradosupir)){
		Intervalo ir(cotainfir,cotasupir, cerradoinfir, cerradosupir);
		return ir;
	}else{
		Intervalo ir;
		return ir;
	}
}

//FIN DE LA CLASE
//FUNCIONES AUXILIARES

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
