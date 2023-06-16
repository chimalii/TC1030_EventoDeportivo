/*
 * Proyecto Evento Deportivo
 * Gabriela Chimali Nava Ramirez
 * A01710530
 * 16/06/2023
 *
 * Declaracion de clase "Modalidad" con los atributos y metodos genericos de 
 * sus tres clases derivadas: "Correr", "Bicicleta" y "Scooter", cada una
 * con su propia logica para calcular el precio y mostrar informacion.
 *
 */

#ifndef MODALIDAD_H
#define MODALIDAD_H

#include <iostream> //Biblioteca que permite realizar operaciones de entrada y salida en consola

using namespace std;

//Declaracion de clase Modalidad que es abstracta
class Modalidad {

    //Variables de instancia
    protected:
        string tipo;
        float distancia;
        float precio;
        int num_perros;

    //Metodos del objeto
    public:
        Modalidad():  tipo(""), distancia(0), num_perros(0) {}; //Constructor default
        Modalidad(string t, float dist, int num_pe): 
            tipo(t), distancia(dist), num_perros(num_pe){}; //Constructor con parametros

        //Getters
        float get_dist() { return distancia; }
        int get_num_pe() { return num_perros; }

        //Metodos abstractos que se sobreescribiran
        virtual float calc_precio(float) = 0;
        virtual void imprime_info() = 0;
};

//Declaracion de clase Correr que hereda de Modalidad
class Correr: public Modalidad{

    //Metodos del objeto
    public:
        Correr(): Modalidad("Canicross", 0, 1) {} //Constructor default
        Correr(float dist, int num_pe): Modalidad("Canicross", dist, num_pe) {}; //Constructor con parametros

        float calc_precio(float precio_base);       
        void imprime_info();
};

/**
 * calc_precio calcula el precio para modalidad de Bicicleta
 * Iguala la variable precio al precio base recibido.
 *
 * @param precio_base El precio base para la modalidad
 * @return float con el precio
 */
float Correr::calc_precio(float precio_base){
    precio = precio_base;
    return precio;
}

/**
 * imprime_info muestra en consola la información de la modalidad de Correr
 * Muestra la distancia, cantidad de perros y el costo.
 * 
 * @param
 * @return
 */
void Correr::imprime_info(){
    cout << "\n ----------- DATOS CANICROSS -----------"
    << "\nDistancia: " << distancia << " km"
    << "\nCant de perros para participar: " << num_perros
    << "\nCosto: $" << precio << " pesos\n";
}

//Declaracion de clase Bicicleta que hereda de Modalidad
class Bicicleta: public Modalidad{
    
    //Variables de instancia
    private:
        float renta_1, renta_2, renta_3;
        float precio_renta = 0.0;
        string eq_1 = "ACCESORIOS (lentes, casco, guantes)";
        string eq_2 = "Solo BICICLETA";
        string eq_3 = "BICICLETA y ACCESORIOS ";

    //Metodos del objeto
    public:
        Bicicleta(): Modalidad("Bikejoring", 0.0, 1) {}; //Constructor default
        Bicicleta(float dist, int num_pe, float r_1, float r_2, float r_3): 
            Modalidad("Bikejoring", dist, num_pe), renta_1(r_1), renta_2(r_2), renta_3(r_3) {}; //Constructor con parametros

        float calc_precio(float precio_base);
        void imprime_info();
};

/**
 * calc_precio calcula el precio para modalidad de Bicicleta
 * Solicita al usuario si desea rentar equipo y muestra las opciones disponibles
 * ademas guarda en precio_renta el costo del equipo rentado.
 *
 * @param precio_base El precio base para la modalidad
 * @return float con el precio actualizado
 */
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
        
        cin >> opcion; // Se introduce el numero respecto a lo que se quiere rentar
        if (opcion == 1){
            precio_renta = renta_1;
            return precio = precio_base + precio_renta;
        } else if (opcion == 2){
            precio_renta = renta_2;
            return precio = precio_base + precio_renta; 
        } else if (opcion == 3){
            precio_renta = renta_3;
            return precio = precio_base + precio_renta;
        }
    }
    return precio = precio_base;
}

/**
 * imprime_info muestra en consola la información de la modalidad de Bicicleta
 * Muestra la distancia, cantidad de perros, costo y si se ha rentado equipo.
 * 
 * @param
 * @return
 */
void Bicicleta::imprime_info(){
    cout << "\n ----------- DATOS BIKEJORING -----------" 
    << "\nDistancia: " << distancia << " km"
    << "\nCant de perros para participar: " << num_perros
    << "\nCosto: $" << precio << " pesos\n";
    if (precio_renta != 0.0){
        cout << "Rentaste: ";
        if (precio_renta == renta_1){
            cout << eq_1;
        } else if (precio_renta == renta_2){
            cout << eq_2;
        } else if (precio_renta == renta_3){ 
            cout << eq_3;
        }
        cout << " /// Por $" << precio_renta << " pesos \n";
    }
}

//Declaracion de clase Bicicleta que hereda de Modalidad
class Scooter: public Modalidad{
    
    //Variables de instancia
    public:
        float renta_1, renta_2, renta_3;
        float precio_renta = 0.0;
        string eq_1 = "ACCESORIOS (lentes, casco, guantes)";
        string eq_2 = "Solo SCOOTER";
        string eq_3 = "SCOOTER y ACCESORIOS ";
    
    //Metodos del objeto
    public:
        Scooter(): Modalidad("Scooter", 0.0, 1){}; //Constructor default
        Scooter(float dist, int num_pe, float r_1, float r_2, float r_3): 
            Modalidad("Scooter", dist, num_pe), renta_1(r_1), renta_2(r_2), renta_3(r_3) {}; //Constructor con parametros

        float calc_precio(float);
        void imprime_info();
};

/**
 * calc_precio calcula el precio para modalidad de Scooter
 * Solicita al usuario si desea rentar equipo y muestra las opciones disponibles
 * ademas guarda en precio_renta el costo del equipo rentado.
 *
 * @param precio_base El precio base para la modalidad
 * @return float con el precio actualizado
 */
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
        
        cin >> opcion; // Se introduce el numero respecto a lo que se quiere rentar
        if (opcion == 1){
            precio_renta = renta_1;
            return precio = precio_base + precio_renta;
        } else if (opcion == 2){
            precio_renta = renta_2;
            return precio = precio_base + precio_renta; 
        } else if (opcion == 3){
            precio_renta = renta_3;
            return precio = precio_base + precio_renta;
        }
    }
    return precio = precio_base;
}

/**
 * imprime_info muestra en consola la información de la modalidad de Scooter
 * Muestra la distancia, cantidad de perros, costo y si se ha rentado equipo.
 * 
 * @param
 * @return
 */
void Scooter::imprime_info(){
    cout << "\n ----------- DATOS SCOOTER -----------" 
    << "\nDistancia: " << distancia << " km"
    << "\nCant de perros para participar: " << num_perros
    << "\nCosto: $" << (precio - precio_renta) << " pesos\n";
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

#endif //MODALIDAD_H