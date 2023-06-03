#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include <iostream>
#include "modalidad.h"
using namespace std;

class Participante{
    private:
        string nombre;
        string genero;
        int edad;
        Modalidad *modalidades[3];
        int modalidades_inscritas;
        float total;

    public:
        Participante(): nombre(""), genero(""), edad(0){};
        Participante(string nom, string gen, int ed);
        string get_nombre();
        string get_genero();
        int get_edad();
        int get_cant_mod();

        void datos_persona();
        void calc_precio_total();
        // float calc_precio_total();

};

Participante::Participante(string nom, string gen, int ed){
    nombre = nom;
    genero = gen;
    edad = ed;
}

string Participante::get_nombre(){
    cout << "Nombre completo: ";
    getline(cin, nombre);
    return nombre;
}

string Participante::get_genero(){
    cout << "Genero: (MASCULINO/FEMENINO) "; cin >> genero;
    return genero;
}

int Participante::get_edad(){
    cout << "Edad: "; cin >> edad;
    return edad;
}

int Participante::get_cant_mod(){
    cout << "Cuantas modalidades inscribiras: "; cin >> modalidades_inscritas;
    return modalidades_inscritas;
}

/*
void Participante::agrega_modalidad(){
    modalidades[modalidades_inscritas] = mod;
    Modalidad *mod1 = new Correr();
    Modalidad *mod2 = new Bicicleta();
    Modalidad *mod3 = new Scooter();   
}
*/

void Participante::datos_persona(){
    cout << endl << "----------- DATOS PERSONA -----------" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Genero:  " << genero << endl;
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
    cout << endl;
}

void Participante::calc_precio_total(){
    float p_c;
    float p_b; float p_r_b;
    float p_s; float p_r_s;
    Modalidad *modalidades[modalidades_inscritas];
    modalidades[0] = new Correr(4.5, 1, "Canicross");
    modalidades[1] = new Bicicleta(4.5, 1, "Bikejoring");
    p_r_b = modalidades[1] -> calc_renta();
    modalidades[2] = new Scooter(4.5, 2, "Scooter");
    p_r_s = modalidades[2] -> calc_renta();


    p_c = modalidades[0] -> calc_precio(200.0);
    p_b = modalidades[1] -> calc_precio(300.0);
    p_s = modalidades[2] -> calc_precio(300.0);

    total = p_c + p_b + p_r_b + p_s + p_r_s;

    // total = (modalidades[0] -> calc_precio(200.0)) + (modalidades[1] -> calc_precio(300.0)) + (modalidades[2] -> calc_precio(300.0));
    modalidades[0] -> imprime_info();
    modalidades[1] -> imprime_info();
    modalidades[2] -> imprime_info();
    cout << endl << "El costo total seran: " << total << " pesos" << endl;
}


#endif
