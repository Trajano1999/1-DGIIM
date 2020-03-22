/**
 * @file main.cpp
 * @brief Examen de laboratorio 
 * Universidad de Granada
 * Metodología de la Programación 
 * @nombre_del_alumno: Juan Manuel Mateos Pérez
 * @dni_del_alumno: 77555876Z
 * @ordenador: ei140180
 * 
 * @warning Por favor, rellene las funciones que se indican
*/
#include <iostream>
#include <string>
using namespace std;

/**
@brief Imprime el contenido de un vector de string
@param v 	Vector de string
@param n	Número de elementos que contiene @a v
*/
void imprimirVector(const string *v, const int n){
    if (v != NULL && n > 0)  {
        cout << n << " elementos" << endl;
        for (int i=0; i<n; i++)
                cout << "["<<i<<"] = " << v[i] << endl;
    }
    else
        cerr << "ERROR: Vector de datos vacío" << endl;
}

/**
 * @brief Implementa la función del enunciado 
 * @param v1 Primer vector
 * @param nv1 Número de elementos de @a v1
 * @param v2 Segundo vector
 * @param nv2 Número de elementos de @a v2
 * @param v3 Vector resultado. Debe reservarse memoria dentro de la función
 * @param nv3 Número de elementos de @a v3
 */
void funcion(string const *v1, int nv1, string *v2, int nv2, string * &v3, int &nv3){
    nv3 = 0;
    
    for(int i=0; i<nv1; i++)
        for(int j=0; j<nv2; j++)
            if(v1[i] == v2[j])
                nv3++;
    
    v3 = new string [nv3];
    
    int contador=0;
    
    for(int i=0; i<nv1; i++){
        for(int j=0; j<nv2; j++){
            if(v1[i] == v2[j]){
                v3[contador] = v1[i];
                contador++;
            }
        }
    }
}

int main(){
    int nv1=0, nv2=0, nv3=0;
    string *v1=NULL, *v2=NULL, *v3=NULL;
    
    cout << "Introduce el numero de elementos de v1: ";
    cin >> nv1;
    
    v1 = new string [nv1];
    
    for(int i=0; i<nv1; i++)
        cin >> v1[i];
    
    imprimirVector(v1, nv1);

    cout << "Introduce el numero de elementos de v2: ";
    cin >> nv2;
    
    v2 = new string [nv2];
    
    for(int i=0; i<nv2; i++)
        cin >> v2[i];
    
    imprimirVector(v2, nv2);

    funcion(v1, nv1, v2, nv2, v3, nv3);
    
    cout << "\nResultado: " << endl;
    imprimirVector(v3, nv3);
    
    delete [] v1;
    v1 = NULL;
    delete [] v2;
    v2 = NULL;
    delete [] v3;
    v3 = NULL;
    
    return 0;
}
