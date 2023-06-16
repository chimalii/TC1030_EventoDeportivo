#ifndef PERRO_H
#define PERRO_H

#include <iostream> //para realizar operaciones de entrada y salida
#include <string> //para usar getline y leer una línea completa de entrada

using namespace std;

class Perro{
    private:
        string nom_perro, raza;
        int edad_perro;
        bool sextuple, desparacitacion;

    public: 
        Perro(): nom_perro (""), raza (""), edad_perro (0.0), sextuple(false), desparacitacion(false) {};
        Perro(string nom_pe, string raz, float ed_pe, bool sext, bool desp):
            nom_perro(nom_pe), raza(raz), edad_perro(ed_pe), sextuple(sext), desparacitacion(desp) {};

        void get_datos_pe();
        void muestra_perro();
};

void Perro::get_datos_pe(){
    cout << "\nSobre el PERRO, ingresa lo solicitado.\nNombre: "; getline(cin >> ws, nom_perro);
    cout << "Raza: "; getline(cin >> ws, raza); 
    cout << "Edad (anios): "; cin >> edad_perro;
    cout << "Vacunacion (1 = SI / 0 = NO)" 
    << "\nSextuple --> "; cin >> sextuple;
    cout << "Desparacitacion --> "; cin >> desparacitacion;
}

void Perro::muestra_perro(){
    cout <<"\n ------------- DATOS PERRO -------------\n* Nombre: " << nom_perro 
    << "\n* Raza: " << raza 
    << "\n* Edad: " << edad_perro << " anios\n";
    if (sextuple == true && desparacitacion == true){ 
        cout << "Vacunacion COMPLETA.\n";
    }
    else if (sextuple == false || desparacitacion == false){
        cout << "Vacunacion INCOMPLETA, podrias tener PROBLEMAS EN LA REVISION antes de la competencia.\n";
    }
}

#endif