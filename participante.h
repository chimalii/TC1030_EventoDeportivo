/*
 * Proyecto Evento Deportivo
 * Gabriela Chimali Nava Ramirez
 * A01710530
 * 16/06/2023
 *
 * Declaracion de clase "Participante" con los atributos y metodos para
 * obterner e imprimir datos del participante, asi como para validad algunas
 * variables en esta u otra clase compuesta por esta
 *
 */

#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

//Bibliotecas
#include <iostream> //permite realizar operaciones de entrada y salida en consola
#include <cstdlib> //para generar de numeros aleatorios y manipular cademas de caracteres
#include <ctime> //para trabajar con hora, apoya a generacion de numero aleatorio
#include <string> //para usar getline y leer una linea completa de entrada

using namespace std;

//Declaracion de clase Participante
class Participante{
    
    //Variables de instancia
    private:
        string nombre, genero, DID, num_competidor;
        int edad;
        bool agrego_DID = false;

    //Metodos del objeto    
    public:
        Participante(): nombre(""), genero(""), edad(0), DID("NA"){}; //Constructor default
        Participante(string nom, string gen, int ed, string _did): 
            nombre(nom), genero(gen), edad(ed), DID(_did){}; //Constructor con parametros
        
        //Getters
        string get_nombre();
        string get_genero();
        int get_edad();
        string get_DID();
        
        //Setters
        bool set_DID(string);
        bool set_agrego_DID();
        
        void muestra_persona();
        float calc_precio_total(float);

};

/**
 * get_nombre obtiene el nombre completo del participante
 * Se muestra una indicacion y el usiario teclea su nombre.
 *
 * @param
 * @return string con nombre completo del participante
*/
string Participante::get_nombre(){
    cout << "Nombre completo del participante: ";
    getline(cin >> ws, nombre);
    return nombre;
}

/**
 * get_genero obtiene el genero del participante
 * Se muestra una indicacion y el usiario teclea su genero.
 *
 * @param
 * @return string con genero del participante
 */
string Participante::get_genero(){
    cout << "Genero (MASCULINO/FEMENINO): "; cin >> genero;
    return genero;
}

/**
 * get_genero obtiene la edad del participante
 * Se muestra una indicacion y el usiario teclea su edad.
 *
 * @param
 * @return int con edad del participante
 */
int Participante::get_edad(){
    cout << "Edad: "; cin >> edad;
    return edad;
}

/**
 * get_DID obtiene el DID del participante 
 * Este puede ser un numero o NA (No Aplica), se pregunta si lo desea adquirir, 
 * de ser asi genera un numero aleatorio entre 100 y 9999 y le suma 10000 
 * pues debe comenzar en 1, finalmente lo convierte a string.
 *
 * @param
 * @return string con el DID del participante
 */
string Participante::get_DID(){
    srand(time(NULL));
    string ad_DID;
    int num_DID;
    cout << "Si cuentas con DID introduce tu numero de afiliacion, si no es asi escribe NA: "; cin >> DID;
    if (DID == "NA"){
        cout << "\n*.* IMPORTANTE *.*\nContar con DID te permite RANKEAR A NIVEL NACIONAL y obtener"
             << " DESCUENTOS en los eventos de toda la temporada anual."
             << "\nTENDRIA UN COSTO ADICIONAL DE $1000.00" 
             << "\nDesea adquirirlo (SI/NO): "; cin >> ad_DID;
        if (ad_DID == "SI") {
            agrego_DID = true;
            // Generar número aleatorio entre 100 y 9999
            num_DID = 100 + rand() % 9900;
            num_DID += 10000;
            DID = to_string(num_DID);
        } else {
            agrego_DID = false;
        }
    }
    return DID;
}

/**
 * set_DID establece si el participante tiene o no DID
 *
 * @param _DID el valor a comparar
 * @return bool indicando si el parametro corresponde a la inclusion de un DID
 */
bool Participante::set_DID(string _DID){
    if(DID == _DID){
        return true;
    }
    else{return false;}
}

/**
 * set_DID establece si el participante agrego o no DID
 *
 * @param 
 * @return bool indicando si el participante agrego o no un DID
 */
bool Participante::set_agrego_DID(){
    return agrego_DID;
}

/**
 * calc_precio_total calcula el precio total 
 * Considerando el descuento si tiene DID.
 *
 * @param precio el precio base a considerar
 * @return float con el precio calculado
 */
float Participante::calc_precio_total(float precio) {
    if (set_DID("NA") == false) {
        return precio * 0.8;
    }
    return precio;
}

/**
 * muestra_persona muestra en consola los datos del participante
 * Muestra el nombre, edad, género y categoría del participante,
 * dependiendo su edad y genero, así como el número de competidor 
 * y el estado del DID.
 *
 * @param
 * @return
 */
void Participante::muestra_persona(){
    srand(time(NULL));
    int num_comp = 1 + rand() % 1000;
    cout << "\n ----------- DATOS PERSONA -----------"
         << "\n* Nombre: " << nombre
         << "\n* Edad: " << edad << " anios"
         << "\n* Genero:  " << genero << "\n";

    if (edad <= 18 && genero == "MASCULINO") {
        cout << "Categoria Varonil Junior (DMJ) 14-18\n";
    } else if (edad <= 18 && genero == "FEMENINO") {
        cout << "Categoria Femenil Junior (DWJ) 14-18\n";
    } else if (edad <= 40 && genero == "MASCULINO") {
        cout << "Categoria Varonil Elite (DME) 19-40\n";
    } else if (edad <= 40 && genero == "FEMENINO") {
        cout << "Categoria Femenil Elite (DWE) 19-40\n";
    } else if (edad <= 50 && genero == "MASCULINO") {
        cout << "Categoria Varonil Master 40 (DMM1) 40-50\n";
    } else if (edad <= 50 && genero == "FEMENINO") {
        cout << "Categoria Femenil Master 40 (DWM1) 40-50\n";
    } else if (edad >= 51 && genero == "MASCULINO") {
        cout << "Categoria Varonil Master +50 (DMM2)\n";
    } else if (edad >= 51 && genero == "FEMENINO") {
        cout << "Categoria Femenil Master +50 (DMM2)\n";
    }
    
    cout << "* Numero de competidor: " << num_comp << "\n";
    if (set_DID("NA") == false){
        cout << "* Tu DID es: " << DID << " /// APLICA DESCUENTO 20 %\n";
    } else {
        cout << "NO CUENTAS CON DID.\n";
    }
}

#endif //PARTICIPANTE_H
