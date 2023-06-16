#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "perro.h"
#include "modalidad.h"

using namespace std;

class Participante{
    private:
        string nombre, genero, DID, num_competidor;
        int edad;
        bool agrego_DID = false;
        
    public:
        Participante(): nombre(""), genero(""), edad(0), DID("NA"){};
        Participante(string nom, string gen, int ed, string _did): 
            nombre(nom), genero(gen), edad(ed), DID(_did){};
        
        string get_nombre();
        string get_genero();
        int get_edad();
        string get_DID();
        
        bool set_DID(string);
        bool set_agrego_DID();
        
        void muestra_persona();
        float calc_precio_total(float);

};

string Participante::get_nombre(){
    cout << "Nombre completo del participante: ";
    getline(cin >> ws, nombre);
    return nombre;
}


string Participante::get_genero(){
    cout << "Genero (MASCULINO/FEMENINO): "; cin >> genero;
    return genero;
}

int Participante::get_edad(){
    cout << "Edad: "; cin >> edad;
    return edad;
}

string Participante::get_DID(){
    srand(time(NULL));
    string ad_DID;
    int num_DID;
    cout << "Si cuentas con DID introduce tu numero de afiliacion, si no es asi escribe NA: "; cin >> DID;
    if (DID == "NA"){
        cout << "\n*.* IMPORTANTE *.*\nContar con DID te permite RANKEAR A NIVEL NACIONAL y obtener"
        << " DESCUENTOS en los eventos de toda la temporada anual.\nTENDRIA UN COSTO ADICIONAL DE $1000.00" 
        << "\nDesea adquirirlo (SI/NO): "; cin >> ad_DID;
        if (ad_DID == "NO"){
            return DID;}
        else if (ad_DID == "SI"){
            agrego_DID = true;
            // Generera num aleatorio entre 100 y 9999
            num_DID = 100 + rand() % 10000 - 100;
            num_DID += 10000;
            return DID = to_string(num_DID);}
    }
    return DID;
}

bool Participante::set_DID(string _DID){
    if(DID == _DID){
        return true;
    }
    else{return false;}
}

bool Participante::set_agrego_DID(){
    return agrego_DID;
}

float Participante::calc_precio_total(float precio) {
    if (set_DID("NA") == false) {
        return precio * 0.8;
    }
    return precio;
}

void Participante::muestra_persona(){
    srand(time(NULL));
    int num_comp;
    cout << "\n ----------- DATOS PERSONA -----------"
    << "\n* Nombre: " << nombre
    << "\n* Edad: " << edad << " anios"
    << "\n* Genero:  " << genero << "\n";
    if (edad <= 18 && genero == "MASCULINO"){
        cout << "Categoria Varonil Junior (DMJ) 14-18\n";}
    else if (edad <= 18 && genero == "FEMENINO"){
        cout << "Categoria Femenil Junior (DWJ) 14-18\n";}
    else if (edad <= 40 && genero == "MASCULINO"){
        cout << "Categoria Varonil Elite (DME) 19-40\n";}
    else if (edad <= 40 && genero == "FEMENINO"){
        cout << "Categoria Femenil Elite (DWE) 19-40\n";}
    else if (edad <= 50 && genero == "MASCULINO"){
        cout << "Categoria Varonil Master 40 (DMM1) 40-50\n";}
    else if (edad <= 50 && genero == "FEMENINO"){
        cout << "Categoria Femenil Master 40 (DWM1) 40-50\n";}
    else if (edad >= 51 && genero == "MASCULINO"){
        cout << "Categoria Varonil Master +50 (DMM2)\n";}
    else if (edad >= 51 && genero == "FEMENINO"){
        cout << "Categoria Femenil Master +50 (DMM2)\n";}
    num_comp = 1 + rand() % 1001 - 1;
    cout << "* Numero de competidor: " << num_comp << "\n";
    if (set_DID("NA") == false){
        cout << "* Tu DID es: " << DID << " /// APLICA DESCUENTO 20 %\n";}
    else {cout << "NO CUENTAS CON DID."<< "\n";}
}

#endif
