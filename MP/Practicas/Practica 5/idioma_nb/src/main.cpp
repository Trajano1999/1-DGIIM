/** 
 * @file main.cpp
 * @author DECSAI
 * @warning Código incompleto. Completar donde se indica
*/
#include <iostream>
#include <cstring>
#include "Bigrama.h"
#include "Idioma.h"

using namespace std;

int main(int narg, char * args[]) {
    cout << endl;
    Idioma idiomita;
    bool verificar = true;
    
    if (narg  < 3){
        cerr << " Error en la llamada.\n   idioma <bigrama> <fich1.bgr> <fich2.bgr> ..." << endl;
        return 1;
    }
    
    if(idiomita.cargarDeFichero(args[2])){
        cout << endl;

        for(int i=3; i<narg && verificar; i++)
            verificar=idiomita.addDeFichero(args[i]);
        
        if(verificar){
            cout << "\nEl bigrama " << args[1] << " tiene una frecuencia de " << idiomita.getPosicion( idiomita.findBigrama(args[1]) ).getFrecuencia();
            cout << " en el idioma " << idiomita.getIdioma() << " (" << idiomita.getSize() << " bigramas) " << endl;
        }
    }
    
    idiomita.liberarMemoria();
    
    return 0;
}
