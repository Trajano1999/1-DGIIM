/**
   @file paquete.cpp
   @author Juanma
**/

#include "paquete.h"

Paquete::Paquete(int id, double peso, int largo, int ancho, int alto){
    if(id != -1){
        _id=id;
        _peso=peso;
        _largo=largo;
        _ancho=ancho;
        _alto=alto;
    }
}

void Paquete::setId(int id){
    if(id != -1)
        _id=id;
}

int  Paquete::getId() const{
    return _id;
}

void Paquete::setPeso(int peso){
    _peso=peso;
}

double Paquete::getPeso() const{
    return _peso;
}

void Paquete::setLargo(int largo){
    _largo=largo;
}

int Paquete::getLargo() const{
    return _largo;
}

void Paquete::setAncho(int ancho){
    _ancho=ancho;
}

int Paquete::getAncho() const{
    return _ancho;
}

void Paquete::setAlto(int alto){
    _alto=alto;
}

int Paquete::getAlto() const{
    return _alto;
}

void Paquete::setPaquete(int id, int peso, int largo, int ancho, int alto){
    if(id >= 0 && peso > 0 && largo > 0 && ancho > 0 && alto > 0){
        _id=id;
        _peso=peso;
        _largo=largo;
        _ancho=ancho;
        _alto=alto;
    }
}

double Paquete::getVolumen() const{
    return _largo*_ancho*_alto;
}

double Paquete::calculaPesoVolumetrico() const{
    double peso_volumetrico;

    peso_volumetrico = getVolumen() / _FACTORVOLUMETRICO;
    if(_peso > peso_volumetrico)
        return _peso;
    else
        return peso_volumetrico;
}

double Paquete::getFactura() const{
    double precio;

    if(calculaPesoVolumetrico() <= _RANGO1)
        precio = _TARIFA1 + _TARIFA1*_IVA;
    else{
        if(calculaPesoVolumetrico() > _RANGO1 && calculaPesoVolumetrico() <= _RANGO2)
            precio = _TARIFA2 + _TARIFA2*_IVA;
        else
            if(calculaPesoVolumetrico() > _RANGO2 && calculaPesoVolumetrico() <= _RANGO3)
                precio = _TARIFA3 + _TARIFA3*_IVA;          
    }
    return precio;
}
