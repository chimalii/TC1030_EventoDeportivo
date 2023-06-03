#ifndef MODALIDAD_H
#define MODALIDAD_H

#include <iostream>
using namespace std;

class Modalidad{
    protected:
        float distancia;
        int num_perros;
        float precio;
    
    public:
        Modalidad(): distancia(0), num_perros(0) {};
        Modalidad(float dist, int num_pe):
        distancia(dist), num_perros(num_pe) {};

        float get_dist(){return distancia;};
        int get_num_pe(){return num_perros;};
        void set_dist(float dist) {distancia = dist;}
        void set_num_pe(int num_pe) {num_perros = num_pe;}

        virtual void calc_precio(float precio_base);
        virtual void imprime_info();
};

void Modalidad::calc_precio(float precio_base){
    string DID;
    string ad_DID;
    cout << "Cuenta con DID (SI/NO): "; cin >> DID;
    if (DID == "NO"){
        cout << "Desea adquirirlo (SI/NO): "; cin >> ad_DID;
        if (ad_DID == "NO"){
            precio = precio_base;
        }
        precio = precio_base*0.8;
    }
    precio = precio_base*0.8;
}

void Modalidad::imprime_info(){
    cout << "Distancia: " << distancia << endl;
    cout << "Cantidad de perros para participar: " << num_perros << endl;
}


class Correr: public Modalidad{
    private:
        string tipo;

    public:
        Correr(): tipo(""), Modalidad(){};
        Correr(float dist, int num_pe, string t):Modalidad(dist, num_pe){ 
			distancia = dist;
            num_perros = num_pe;
            tipo = t;
		}
        
        // void calc_precio(float precio_base);
        void imprime_info();
};

void Correr::imprime_info(){
    cout << endl << "----------- DATOS " << tipo << " -----------" << endl;
    cout << "Distancia: " << distancia << " km" << endl;
    cout << "Cant de perros para participar: " << num_perros << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Costo: " << precio << " pesos" << endl;
}

class Bicicleta: public Modalidad{
    private:
        string tipo;
        float precio_renta;

    public:
        Bicicleta(): tipo(""), Modalidad(){};
        Bicicleta(float dist, int num_pe, string t):Modalidad(dist, num_pe){ 
			distancia = dist;
            num_perros = num_pe;
            tipo = t;
		}

        void calc_renta();
        void imprime_info();

};

/*
bool Bicicleta::get_renta(){
    string renta;
    cout << "Deseas rentar equipo (SI/NO): "; cin >> renta;
    if (renta == "SI"){
        renta_equipo = true;
        return renta_equipo;
    }
    renta_equipo = false;
    return renta_equipo;
}
*/

void Bicicleta::calc_renta(){
    string renta;
    int opcion;
    cout << "Deseas rentar equipo para BICICLETA (SI/NO): "; cin >> renta;
    if (renta == "SI"){
        cout << endl << "*.* IMPORTANTE *.*" << endl
        << "Si el equipo sufre algun danio se cobraran extras en reparacion." << endl
        << endl << " 1. Accesorios (lentes, casco, guantes) -------------------------> $100" << endl
        << " 2. Solo Bicicleta ----------------------------------------------> $300" << endl
        << " 3. Bicicleta y accesorios --------------------------------------> $350" << endl
        << "Elige el equipo que deseas rentar: ";
        cin >> opcion;
        if (opcion == 1){
            precio_renta = 100.0;
        }
        else if (opcion == 2){
            precio_renta = 300.0;
        }
        else {precio_renta = 350.0;}
    }
    else {precio_renta = 0.0;}
}

void Bicicleta::imprime_info(){
    float precio_total;
    cout << endl << "----------- DATOS " << tipo << " -----------" << endl;
    cout << "Distancia: " << distancia << " km" << endl;
    cout << "Cant de perros para participar: " << num_perros << endl;
    cout << "Tipo: " << tipo << endl;
    if (precio_renta != 0.0){
        cout << "Rentaste: ";
        if (precio_renta == 100.0){
            cout << "ACCESORIOS, que incluyen casco, lentes y guantes." << endl;
            precio_total = precio + precio_renta;
        }
        else if (precio_renta == 300.0){
            cout << "Solo la BICICLETA." << endl;
            precio_total = precio + precio_renta;
        }
        else {
            cout << "BICICLETA y ACCESORIOS, que incluyen casco, lentes y guantes." << endl;
            precio_total = precio + precio_renta;
        }
        cout << "Costo: " << precio_total << " pesos" << endl;
    }
    else {cout << "Costo: " << precio << " pesos" << endl;}
}

class Scooter: public Modalidad{
    public:
        string tipo;
        float precio_renta;
    
    public:
        Scooter(): tipo(""), Modalidad(){};
        Scooter(float dist, int num_pe, string t):Modalidad(dist, num_pe){ 
			distancia = dist;
            num_perros = num_pe;
            tipo = t;
		}

        void calc_renta();
        void imprime_info();
}; 

void Scooter::calc_renta(){
    string renta;
    int opcion;
    cout << "Deseas rentar equipo para SCOOTER (SI/NO): "; cin >> renta;
    if (renta == "SI"){
        cout << endl << "*.* IMPORTANTE *.*" << endl
        << "Si el equipo sufre algun danio se cobraran extras en reparacion." << endl
        << endl << " 1. Accesorios (lentes, casco, guantes) -------------------------> $100" << endl
        << " 2. Solo Scooter ------------------------------------------------> $320" << endl
        << " 3. Scooter y accesorios ----------------------------------------> $370" << endl
        << "Elige el equipo que deseas rentar: ";
        cin >> opcion;
        if (opcion == 1){
            precio_renta = 100.0;
        }
        else if (opcion == 2){
            precio_renta = 320.0;
        }
        else {precio_renta = 370.0;}
    }
    else {precio_renta = 0.0;}
}

void Scooter::imprime_info(){
    float precio_total;
    cout << endl << "----------- DATOS " << tipo << " -----------" << endl;
    cout << "Distancia: " << distancia << " km" << endl;
    cout << "Cant de perros para participar: " << num_perros << endl;
    cout << "Tipo: " << tipo << endl;
    if (precio_renta != 0.0){
        cout << "Rentaste: ";
        if (precio_renta == 100.0){
            cout << "ACCESORIOS, que incluyen casco, lentes y guantes." << endl;
            precio_total = precio + precio_renta;
        }
        else if (precio_renta == 320.0){
            cout << "Solo el SCOOTER." << endl;
            precio_total = precio + precio_renta;
        }
        else {
            cout << "SCOOTER y ACCESORIOS, que incluyen casco, lentes y guantes." << endl;
            precio_total = precio + precio_renta;
        }
        cout << "Costo: " << precio_total << " pesos" << endl;
    }
    else {cout << "Costo: " << precio << " pesos" << endl;}
}


#endif