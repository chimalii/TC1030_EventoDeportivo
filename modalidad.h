#ifndef MODALIDAD_H
#define MODALIDAD_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Modalidad {
protected:
    string tipo;
    float distancia, precio;
    int num_perros;

public:
    // Constructor default
    Modalidad():  tipo(""), distancia(0), num_perros(0) {}
    Modalidad(string t, float dist, int num_pe): 
        tipo(t), distancia(dist), num_perros(num_pe){};

    float get_dist() { return distancia; }
    int get_num_pe() { return num_perros; }
    void set_dist(float dist) { distancia = dist; }
    void set_num_pe(int num_pe) { num_perros = num_pe; }

    virtual float calc_precio(float) = 0;
    virtual void imprime_info() = 0;
};

// / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

class Correr: public Modalidad{

    public:
        // Constructor default
        Correr(): Modalidad("Canicross", 0, 1) {}
        Correr(float dist, int num_pe): Modalidad("Canicross", dist, num_pe) {};

        float calc_precio(float precio_base);       
        void imprime_info();
};

float Correr::calc_precio(float precio_base){
    precio = precio_base;
    return precio;
}

void Correr::imprime_info(){
    cout << "\n----------- DATOS CANICROSS -----------"
    << "\nDistancia: " << distancia << " km"
    << "\nCant de perros para participar: " << num_perros
    << "\nCosto: $" << precio << " pesos\n";
}

// / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

class Bicicleta: public Modalidad{
    private:
        float renta_1, renta_2, renta_3;
        float precio_renta = 0.0;
        string eq_1 = "ACCESORIOS (lentes, casco, guantes)";
        string eq_2 = "Solo BICICLETA";
        string eq_3 = "BICICLETA y ACCESORIOS ";

    public:
        Bicicleta(): Modalidad("Bikejoring", 0.0, 1) {}
        Bicicleta(float dist, int num_pe, float r_1, float r_2, float r_3): 
            Modalidad("Bikejoring", dist, num_pe), renta_1(r_1), renta_2(r_2), renta_3(r_3) {}; 

        float calc_precio(float precio_base);
        void imprime_info();
};

float Bicicleta::calc_precio(float precio_base){
    string renta;
    int opcion;
    cout << "\nDeseas rentar equipo para BIKEJORING (SI/NO): "; cin >> renta;
    if (renta == "SI"){
        cout << "\n   *.* IMPORTANTE *.*\nSi el equipo sufre algun danio se cobraran extras en reparacion.\n"
        << " 1. " << eq_1 << "-------------------------> $" << renta_1 << ".00\n"
        << " 2. " << eq_2 << "----------------------------------------------> $" << renta_2 << ".00\n"
        << " 3. " << eq_3 << " --------------------------------------> $" << renta_3 << ".00\n"
        << "\nElige el equipo que deseas rentar: ";
        
        cin >> opcion;
        if (opcion == 1){
            precio_renta = renta_1;
            return precio = precio_base + precio_renta;
        }
        else if (opcion == 2){
            precio_renta = renta_2;
            return precio = precio_base + precio_renta; 
        }
        else if (opcion == 3){
            precio_renta = renta_3;
            return precio = precio_base + precio_renta;
        }
    }
    return precio = precio_base;
}

void Bicicleta::imprime_info(){
    cout << "\n----------- DATOS BIKEJORING -----------" 
    << "\nDistancia: " << distancia << " km"
    << "\nCant de perros para participar: " << num_perros
    << "\nCosto: $" << precio << " pesos\n";
    if (precio_renta != 0.0){
        cout << "Rentaste: ";
        if (precio_renta == renta_1){
            cout << eq_1;
        }
        else if (precio_renta == renta_2){
            cout << eq_2;
        }
        else if (precio_renta == renta_3){ 
            cout << eq_3;
        }
        cout << " /// Por $" << precio_renta << " pesos \n";
    }
}

// / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

class Scooter: public Modalidad{
    public:
        float renta_1, renta_2, renta_3;
        float precio_renta = 0.0;
        string eq_1 = "ACCESORIOS (lentes, casco, guantes)";
        string eq_2 = "Solo SCOOTER";
        string eq_3 = "SCOOTER y ACCESORIOS ";
    
    public:
        Scooter(): Modalidad("Scooter", 0.0, 1){};
        Scooter(float dist, int num_pe, float r_1, float r_2, float r_3): 
            Modalidad("Scooter", dist, num_pe), renta_1(r_1), renta_2(r_2), renta_3(r_3) {};

        float calc_precio(float precio_base);
        void imprime_info();
};

float Scooter::calc_precio(float precio_base){
    string renta;
    int opcion;
    cout << "\nDeseas rentar equipo para SCOOTER (SI/NO): "; cin >> renta;
    if (renta == "SI"){
        cout << "\n*.* IMPORTANTE *.*\n Si el equipo sufre algun danio se cobraran extras en reparacion."
        << "\n1. " << eq_1 << " -------------------------> $" << renta_1 << ".00"
        << "\n2. " << eq_2 << " ------------------------------------------------> $" << renta_2 << ".00"
        << "\n3. " << eq_3 << " ----------------------------------------> $" << renta_3 << ".00\n"
        << "\nElige el equipo que deseas rentar: ";
        
        // Se introduce el numero respecto a lo que se quiere rentar
        cin >> opcion;
        if (opcion == 1){
            precio_renta = renta_1;
            return precio = precio_base + precio_renta;
        }
        else if (opcion == 2){
            precio_renta = renta_2;
            return precio = precio_base + precio_renta; 
        }
        else if (opcion == 3){
            precio_renta = renta_3;
            return precio = precio_base + precio_renta;
        }
    }
    return precio = precio_base;
}

void Scooter::imprime_info(){
    cout << "\n----------- DATOS SCOOTER -----------" 
    << "\nDistancia: " << distancia << " km"
    << "\nCant de perros para participar: " << num_perros
    << "\nCosto: $" << precio << " pesos\n";
    if (precio_renta != 0.0){
        cout << "Rentaste: ";
        if (precio_renta == renta_1){
            cout << eq_1;
        }
        else if (precio_renta == renta_2){
            cout << eq_2;
        }
        else if (precio_renta == renta_3){ 
            cout << eq_3;
        }
        cout << " /// Por $" << precio_renta << " pesos \n";
    }
}

#endif
