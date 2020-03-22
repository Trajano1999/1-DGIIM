/** 
 * @file Idioma.cpp
 * @author DECSAI
 * @warning Código incompleto. Implementar la clase completa
*/

#include <fstream>
#include <iostream>
#include <cstring>
#include "Idioma.h"

using namespace std;

Idioma::Idioma(){
    _idioma = ' ';
    _conjunto = 0;
    _nBigramas = 0;
}

Idioma::Idioma(int nbg){
    _idioma = ' ';
    _conjunto = 0;
    _nBigramas = nbg;
}

void Idioma::reservarMemoria(int n){
    if(_conjunto != 0){
        delete [] _conjunto;
        _conjunto = 0;
    }

    _conjunto = new Bigrama [n];
    _nBigramas = n;
}   

void Idioma::ampliarMemoria(int n){
    Bigrama *aux=new Bigrama [_nBigramas + n];

    for(int i=0; i<_nBigramas && i<_nBigramas + n; i++)
        aux[i] = _conjunto[i];

    delete [] _conjunto; 
    _conjunto = aux;    
    _nBigramas = _nBigramas+n;
    aux = 0;
}

void Idioma::liberarMemoria(){
    delete [] _conjunto;
    _conjunto = 0;
    _nBigramas = 0;
}

std::string Idioma::getIdioma() const{
    return _idioma;
}

void Idioma::setIdioma(const std::string& id){
    _idioma = id;
}

Bigrama Idioma::getPosicion(int p) const{
    if(p >= 0 && p < _nBigramas)
        return _conjunto[p];
}

void Idioma::setPosicion(int p, const Bigrama & bg){
    ampliarMemoria(1);
    
    for(int i=_nBigramas-2; i>p; i--)
        _conjunto[i+1]=_conjunto[i];
    
    _conjunto[p] = bg;
}

int Idioma::getSize() const{
    return _nBigramas;
}

int Idioma::findBigrama(const std::string bg) const{
    int numero=-1;
    
    for(int i=0; i<_nBigramas && numero==-1; i++)
        if( strcmp( _conjunto[i].getBigrama(),bg.c_str() ) == 0 )
            numero = i;
        
    return numero;
}

void Idioma::addBigrama(const Bigrama & bg){
    int pos = findBigrama(bg.getBigrama());
    
    if(pos == -1){
        ampliarMemoria(1);
        _conjunto[_nBigramas-1] = bg;
    }else
        _conjunto[pos].setFrecuencia(bg.getFrecuencia() + _conjunto[pos].getFrecuencia());
}

bool Idioma::cargarDeFichero(const char *fichero){
    bool cargado = false;
    int frec;
    char v1[3];
    Bigrama bigramita;
    
    ifstream lectura;
    lectura.open(fichero);
    cout << "Abriendo fichero " << fichero << endl;
    
    if(lectura){
        lectura >> _idioma;

        if(_idioma == "MP-BIGRAMAS_IDIOMA-T-1.0"){
            lectura >> _idioma;
            cout << "Idioma detectado: " << _idioma << endl;
            lectura >> _nBigramas;
            cout << "Leyendo " << _nBigramas << " bigramas" << endl; 

            _conjunto = new Bigrama[_nBigramas];

            for(int i=0; i<_nBigramas; i++){
                lectura >> v1;
                lectura >> frec;
                bigramita.setBigrama(v1);
                bigramita.setFrecuencia(frec);
                _conjunto[i] = bigramita;
            }
            
            if(lectura){
                cargado = true;
                cout << "OK" << endl;
            }else
                cerr << "Fallo en la lectura del fichero " << fichero << endl;
        }else
            cerr << "Fallo en la lectura del fichero " << fichero << endl;
    }else
        cerr << "Fallo en la apertura del fichero " << fichero << endl;
    
    lectura.close();
    return cargado;
}
      
bool Idioma::addDeFichero(const char *fichero){
    bool noerrores = false;
    std::string el_idioma;
    char v1[3];
    int tamano, frec, pos;
    Bigrama bigramita;
    
    ifstream lectura;
    lectura.open(fichero); 
    cout << "Abriendo el fichero " << fichero << endl;
    
    if (lectura){
        lectura >> el_idioma;
        lectura >> el_idioma;
        
        cout << "Idioma detectado: " << el_idioma << endl;
        
        if(el_idioma == _idioma){
            lectura >> tamano;
            
            cout << "Leyendo " << tamano << " bigramas " << endl;
            
            for(int i=0; i<tamano; i++){
                lectura >> v1;
                lectura >> frec;

                bigramita.setBigrama(v1);
                bigramita.setFrecuencia(frec);
                
                addBigrama(bigramita);
            }
            
            if(lectura){
                noerrores = true;
                cout << "OK" << endl;
            }else
                cerr << "Fallo en la lectura del fichero " << fichero << endl;
        }else
            cerr << "No coinciden el idioma con " << _idioma << endl;
    }else
        cerr << "Fallo en la apertura del fichero " << fichero << endl;
     
    lectura.close();
    return noerrores;
}