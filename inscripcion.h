
#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "modalidad.h"
#include "participante.h"
#include "perro.h"

using namespace std;

class Inscripcion{
    private:
        Participante persona1;
        Perro *perros[10];
        Modalidad *mods[3];
        int cont_perros = 0;
        string insc_c = "";
        string insc_b = "";
        string insc_s = "";
        float p_c, p_b, p_s;

    public:
        Inscripcion(){};
        void agrega_perro();
        void agrega_persona();
        void agrega_mods();
        void imprime_todo();
};

void Inscripcion::agrega_perro(){
    int cant_perros;
    cout << "\nCantidad de perros que inscribiras (1-10 MAX): "; cin >> cant_perros;
    while (cont_perros < cant_perros){
        perros[cont_perros] = new Perro(); 
        perros[cont_perros] -> get_datos_pe();
        cont_perros++;              
    }
}

void Inscripcion::agrega_persona(){
    cout << "\nIntroduciras los datos de tu inscripcion, escribe tal y como se especifica."
    "\nPreferentemente en MAYUSCULAS y SIN ACENTOS."
    "\nPresiona ENTER al terminar de llenar cada espacio de informacion.\n\n";
    persona1.get_nombre();
    persona1.get_edad();
    persona1.get_genero();
    persona1.get_DID();
}

void Inscripcion::agrega_mods(){
    cout << "\nInscribiras Canicross (SI/NO): "; cin >> insc_c;
    if (insc_c == "SI") {
        mods[0] = new Correr(4.5, 1);
        float precio_cani = 200.0;
        float precio_t_cani = persona1.calc_precio_total(precio_cani);
        p_c = mods[0] -> calc_precio(precio_t_cani);
    }

    cout << "\nInscribiras Bikejoring (SI/NO): "; cin >> insc_b;
    if (insc_b == "SI") {
        mods[1] = new Bicicleta(4.5, 1, 80.0, 250.0, 300.0);
        float precio_bike = 300.0;
        float precio_t_bike = persona1.calc_precio_total(precio_bike);
        p_b = mods[1] -> calc_precio(precio_t_bike);
    }

    cout << "\nInscribiras Scooter (SI/NO): "; cin >> insc_s;
    if (insc_s == "SI") {
        mods[2] = new Scooter(4.5, 2, 80.0, 270.0, 320.0);
        float precio_scooter = 320.0;
        float precio_t_scooter = persona1.calc_precio_total(precio_scooter);
        p_s = mods[2] -> calc_precio(precio_t_scooter);
    }
}

void Inscripcion::imprime_todo(){
    persona1.muestra_persona();
    float precio_total = p_c + p_b + p_s;
    if (persona1.set_agrego_DID() == true){
        precio_total = precio_total + 1000;
        cout << "*.*Acabas de adquirir un DID por $1000.00 pesos*.*\n";
    }
    cout << " ~~~~~~~ COSTO TOTAL: $" << precio_total << " pesos ~~~~~~~\n";
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
        perros[i] -> muestra_perro();
}

#endif