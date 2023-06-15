#ifndef DATOS_H
#define DATOS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "modalidad_buena.h"

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
        void imp_datos_perro();
};

void Perro::get_datos_pe(){
    cout << "\nSobre el PERRO, ingresa lo solicitado.\nNombre: "; cin >> nom_perro;
    cout << "Raza: "; cin >> raza; 
    cout << "Edad: "; cin >> edad_perro;
    cout << "Vacunacion (1 = SI / 0 = NO)" 
    << "\nSextuple --> "; cin >> sextuple;
    cout << "Desparacitacion --> "; cin >> desparacitacion; cout << "\n";
}

void Perro::imp_datos_perro(){
    cout <<"\n------------- DATOS PERRO -------------\n* Nombre: " << nom_perro 
    << "\n* Raza: " << raza 
    << "\n* Edad: " << edad_perro << " meses\n";
    if (sextuple == true && desparacitacion == true){ 
        cout << "Vacunacion COMPLETA.\n";
    }
    else if (sextuple == false || desparacitacion == false){
        cout << "Vacunacion INCOMPLETA.\n";
    }
}

// / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

class Participante{
    private:
        string nombre, genero, DID, num_competidor;
        int edad;
        
    public:
        Participante(): nombre(""), genero(""), edad(0), DID("NA"){};
        Participante(string nom, string gen, int ed, string _did): 
            nombre(nom), genero(gen), edad(ed), DID(_did){};
        
        string get_nombre();
        string get_genero();
        int get_edad();
        string get_DID();
        
        bool set_DID(string);
        
        //void agrega_c();
        //void agrega_b();
        //void agrega_s();
        //void agrega_perros();
        void imp_datos_persona();
        void calc_precio_total();

};

string Participante::get_nombre(){
    cout << "Nombre completo: ";
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
        cout << "Desea adquirirlo (SI/NO): "; cin >> ad_DID;
        if (ad_DID == "NO"){
            return DID;}
        else if (ad_DID == "SI"){
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

void Participante::imp_datos_persona(){
    srand(time(NULL));
    int num_comp;
    cout << endl << "----------- DATOS PERSONA -----------" << endl;
    cout << "* Nombre: " << nombre << endl;
    cout << "* Edad: " << edad << " anios" << endl;
    cout << "* Genero:  " << genero << endl;
    if (edad <= 18 && genero == "MASCULINO"){
        cout << "Categoria Varonil Junior (DMJ) 14-18" << endl;}
    else if (edad <= 18 && genero == "FEMENINO"){
        cout << "Categoria Femenil Junior (DWJ) 14-18" << endl;}
    else if (edad <= 40 && genero == "MASCULINO"){
        cout << "Categoria Varonil Elite (DME) 19-40" << endl;}
    else if (edad <= 40 && genero == "FEMENINO"){
        cout << "Categoria Femenil Elite (DWE) 19-40" << endl;}
    else if (edad <= 50 && genero == "MASCULINO"){
        cout << "Categoria Varonil Master 40 (DMM1) 40-50" << endl;}
    else if (edad <= 50 && genero == "FEMENINO"){
        cout << "Categoria Femenil Master 40 (DWM1) 40-50" << endl;}
    else if (edad >= 51 && genero == "MASCULINO"){
        cout << "Categoria Varonil Master +50 (DMM2)" << endl;}
    else if (edad >= 51 && genero == "FEMENINO"){
        cout << "Categoria Femenil Master +50 (DMM2)" << endl;}
    num_comp = 1 + rand() % 1001 - 1;
    cout << "* Numero de competidor: " << num_comp << endl;
    if (set_DID("NA") == false){
        cout << "* Tu DID es: " << DID << endl;}
    else {cout << "NO CUENTAS CON DID."<< endl;}
}

#endif
