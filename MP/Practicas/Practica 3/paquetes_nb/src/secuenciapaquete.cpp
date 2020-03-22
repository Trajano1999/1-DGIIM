/**
   @file secuenciapaquete.cpp
   @author decsai.ugr.es
   @warning Código incompleto
**/

#include "paquete.h"
#include "secuenciapaquete.h"

void cleanSecuenciaPaq(Paquete s[], int& util){
    Paquete vacio(-1);
    
    for(int i = 0; i< util; i++)
        s[i] = vacio;
    util = 0;
}

bool addSecuenciaPaq(Paquete s[], int& util, const Paquete& p){
    bool insercion = false;
    
    if(util < MAXPAQ){
        s[util] = p;
        util++;
        insercion = true;
    }
    return insercion;
}

double getTotalSecuenciaPaq(const Paquete s[], const int& util){
    double suma = 0;
    
    for(int i = 0; i < util; i++){
        suma = suma + s[i].getFactura();
    }
    return suma;
}

Paquete paqueteMayorSecuenciaPaq(const Paquete s[], const int& util){
    Paquete mayorvolumen = s[0];
    
    for(int i = 0; i < util; i++)
        if(mayorvolumen.getVolumen() < s[i].getVolumen())
            mayorvolumen = s[i];
    
    return mayorvolumen;
}

double getMediaSecuenciaPaq(const Paquete s[], const int& util){
    double suma = 0;
    
    for(int i = 0; i < util; i++){
        suma = suma + s[i].getFactura(); 
    }
    
    return suma/util;
}

int numPaqueteAltosSecuenciaPaq(const Paquete s[], const int& util, const int& altura){
    int contador = 0;
    
    for(int i = 0; i < util; i++)
        if(s[i].getAlto() > altura)
            contador++;
        
    return contador;
}

int numPaquetesSuperiorSecuenciaPaq(const Paquete s[], const int& util){
    int contador = 0;
    
    for(int i = 0; i < util; i++)
        if(s[i].getFactura() > getMediaSecuenciaPaq(s, util))
            contador++;
    return contador;
}