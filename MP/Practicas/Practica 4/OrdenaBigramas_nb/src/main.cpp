/** 
 * @file main.cpp
 * @author DECSAI
*/
#include <iostream>
#include <cstring>
#include "Bigrama.h"

using namespace std;

int main(){
    // char s[60];
    // int frec;
    int nv1, nv2, nv3;
    Bigrama *v1=NULL, *v2=NULL, *v3=NULL;
    
    // Lee número de elementos del primer vector
    cout << "Introduce el numero de elementos del primer vector: ";
    cin >> nv1;
    // Le hacemos el new
    v1 = new Bigrama [nv1];
    // Lee el primer vector
    char a,b;
    int frec1;
    for(int i=0; i<nv1; i++){
        cin >> a >> b;
        const char vectorc1[3]={a,b,'\0'};
        (v1+i)->setBigrama(vectorc1);
        cin >> frec1;
        (v1+i)->setFrecuencia(frec1);
    }
   
    // Lee número de elementos del segundo vector
    cout << "Introduce el numero de elementos del segundo vector: ";
    cin >> nv2;
    // Le hacemos el new
    v2 = new Bigrama [nv2];
    // Lee el segundo vector
    char c,d;
    int frec2;
    for(int i=0; i<nv1; i++){
        cin >> c >> d;
        const char vectorc2[3]={c,d,'\0'};
        (v2+i)->setBigrama(vectorc2);
        cin >> frec2;
        (v2+i)->setFrecuencia(frec2);
    }
    
    cout << endl << "Contenido de v1" << endl;
    imprimeBigramas(v1, nv1);
    cout << endl << "\nContenido de v2" << endl;
    imprimeBigramas(v2, nv2);
    
    // Posibles operaciones intermedias sobre v1 o v2
    cout << "\n\nSumando v1 y v2 en v3 ...";
    nv3 = nv1;
    v3 = new Bigrama[nv3];
    
    sumaBigramas(v1, nv1, v2, nv2, v3, nv3);
    ordenaAscFrec(v3, nv3);
    cout << endl << "\nContenido de v3" << endl;
    imprimeBigramas(v3, nv3);
    cout << endl;

    // Limpieza de memoria
    delete [] v1;
    v1 = NULL;
    delete [] v2;
    v2 = NULL;
    delete [] v3;
    v3 = NULL;
    
    return 0;
}
