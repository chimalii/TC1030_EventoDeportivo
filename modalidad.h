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

        virtual float calc_precio(float precio_base) = 0;
        virtual float calc_renta() = 0;
        virtual void imprime_info() = 0;
};

float Modalidad::calc_precio(float precio_base){
    precio = precio_base;  
    return precio;
}

float Modalidad::calc_renta(){
    return 0;
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
        
        void imprime_info();
};

void Correr::imprime_info(){
    cout << endl << "----------- DATOS " << tipo << " -----------" << endl;
    cout << "Distancia: " << distancia << " km" << endl;
    cout << "Cant de perros para participar: " << num_perros << endl;
    cout << "Tipo: " << tipo << endl;
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

        float calc_renta();
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

float Bicicleta::calc_renta(){
      float r_b_1 = 80.0;
    float r_b_2 = 250.0;
    float r_b_3 = 300.0;
    string renta;
    int opcion;
    cout << endl << "Deseas rentar equipo para BICICLETA (SI/NO): "; cin >> renta;
    if (renta == "SI"){
        cout << endl << "*.* IMPORTANTE *.*" << endl
        << "Si el equipo sufre algun danio se cobraran extras en reparacion." << endl
        << endl << " 1. Accesorios (lentes, casco, guantes) -------------------------> $" << r_b_1 << ".00" << endl
        << " 2. Solo Bicicleta ----------------------------------------------> $" << r_b_2 << ".00" << endl
        << " 3. Bicicleta y accesorios --------------------------------------> $" << r_b_3 << ".00" << endl
        << "Elige el equipo que deseas rentar: ";
        cin >> opcion;
        if (opcion == 1){
            precio_renta = r_b_1; return precio_renta;
        }
        else if (opcion == 2){
            precio_renta = r_b_2; return precio_renta;
        }
        else {precio_renta = r_b_3; return precio_renta;
        }
    }
    else {precio_renta = 0.0; return precio_renta;}
}

void Bicicleta::imprime_info(){
    float precio_total;
    cout << endl << "----------- DATOS " << tipo << " -----------" << endl;
    cout << "Distancia: " << distancia << " km" << endl;
    cout << "Cant de perros para participar: " << num_perros << endl;
    cout << "Tipo: " << tipo << endl;
    if (precio_renta != 0.0){
        cout << "Rentaste: ";
        if (precio_renta == 80.0){
            cout << "ACCESORIOS, que incluyen casco, lentes y guantes.()" << endl;
        }
        else if (precio_renta == 270.0){
            cout << "Solo la BICICLETA." << endl;
        }
        else {
            cout << "BICICLETA y ACCESORIOS, que incluyen casco, lentes y guantes." << endl;
        }
    }
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

        float calc_renta();
        void imprime_info();
}; 

float Scooter::calc_renta(){
    float r_s_1 = 80.0;
    float r_s_2 = 270.0;
    float r_s_3 = 320.0;
    string renta;
    int opcion;
    cout << endl << "Deseas rentar equipo para SCOOTER (SI/NO): "; cin >> renta;
    if (renta == "SI"){
        cout << endl << "*.* IMPORTANTE *.*" << endl
        << "Si el equipo sufre algun danio se cobraran extras en reparacion." << endl
        << endl << " 1. Accesorios (lentes, casco, guantes) -------------------------> $" << r_s_1 << ".00" << endl
        << " 2. Solo Scooter ------------------------------------------------> $" << r_s_2 << ".00" << endl
        << " 3. Scooter y accesorios ----------------------------------------> $" << r_s_3 << ".00" << endl
        << "Elige el equipo que deseas rentar: ";
        cin >> opcion;
        if (opcion == 1){
            precio_renta = r_s_1; return precio_renta;
        }
        else if (opcion == 2){
            precio_renta = r_s_2; return precio_renta;
        }
        else {precio_renta = r_s_3; return precio_renta;
        }
    }
    else {precio_renta = 0.0; return precio_renta;}
}

void Scooter::imprime_info(){
    float precio_total;
    cout << endl << "----------- DATOS " << tipo << " -----------" << endl;
    cout << "Distancia: " << distancia << " km" << endl;
    cout << "Cant de perros para participar: " << num_perros << endl;
    cout << "Tipo: " << tipo << endl;
    if (precio_renta != 0.0){
        cout << "Rentaste: ";
        if (precio_renta == 80.0){
            cout << "ACCESORIOS, que incluyen casco, lentes y guantes." << endl;
        }
        else if (precio_renta == 270.0){
            cout << "Solo el SCOOTER." << endl;
        }
        else {
            cout << "SCOOTER y ACCESORIOS, que incluyen casco, lentes y guantes. ($250.00)" << endl;
        }
    }
}


#endif
