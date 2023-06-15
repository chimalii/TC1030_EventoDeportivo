#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "modalidad.h"
#include "datos.h"

using namespace std;

int main(){
    Participante persona1;
    Perro *perros[10];
    Modalidad *mods[3];
    int cont_perros = 0;
    string insc_c = "";
    string insc_b = "";
    string insc_s = "";
    
    int cant_perros;
    cout << "Cantidad de perros que inscribiras (1-10 MAX): "; cin >> cant_perros;
    while (cont_perros < cant_perros){
        perros[cont_perros] = new Perro(); 
        perros[cont_perros] -> get_datos_pe();
        cont_perros++;              
    }
    
    persona1.get_nombre();
    persona1.get_edad();
    persona1.get_genero();
    persona1.get_DID();

    cout << "\nInscribiras Canicross (SI/NO): "; cin >> insc_c;
    if (insc_c == "SI"){
        mods[0] = new Correr(4.5, 1);
        if (persona1.set_DID("NA") == false){
            (mods[0] -> calc_precio(200.0)) * 0.8;
        }
        mods[0] -> calc_precio(200.0);
    }
    cout << "\nInscribiras Bikejoring (SI/NO): "; cin >> insc_b;
    if (insc_b == "SI"){
        mods[1] = new Bicicleta(4.5, 1, 80.0, 250.0, 300.0);
        if (persona1.set_DID("NA") == false){
            (mods[1] -> calc_precio(300.0)) * 0.8;
        }
        else{mods[1] -> calc_precio(300.0);}
    }
    cout << "\nInscribiras Scooter (SI/NO): "; cin >> insc_s;
    if (insc_s == "SI"){ 
        mods[2] = new Scooter(4.5, 2, 80.0, 270.0, 320.0);
        if (persona1.set_DID("NA") == false){
            (mods[2] -> calc_precio(320.0)) * 0.8;
        }
        else{mods[2] -> calc_precio(320.0);}
    }

    persona1.imp_datos_persona();
    if (insc_c == "SI"){
        mods[0] -> imprime_info();
    }
    if (insc_b == "SI"){
        mods[1] -> imprime_info();
    }
    if (insc_s == "SI"){
        mods[2] -> imprime_info();
    }
    for(int i = 0; i < cont_perros; i++)
        perros[i] -> imp_datos_perro();
    
   return 0;
}
