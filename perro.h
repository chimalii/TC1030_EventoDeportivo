/*
 * Proyecto Evento Deportivo
 * Gabriela Chimali Nava Ramirez
 * A01710530
 * 16/06/2023
 *
 * Declaracion de clase "Perro" con los atributos y metodos para
 * obterner e imprimir datos del perro.
 *
 */

#ifndef PERRO_H
#define PERRO_H

//Bibliotecas
#include <iostream> //permite realizar operaciones de entrada y salida en consola
#include <string> //para usar getline y leer una linea completa de entrada

using namespace std;

//Declaracion de clase Perro
class Perro{
    
    //Variables de instancia
    private:
        string nom_perro, raza;
        int edad_perro;
        bool sextuple, desparacitacion;

    //Metodos del objeto
    public: 
        Perro(): nom_perro (""), raza (""), edad_perro (0.0), sextuple(false), desparacitacion(false) {}; //Constructor default
        Perro(string nom_pe, string raz, float ed_pe, bool sext, bool desp):
            nom_perro(nom_pe), raza(raz), edad_perro(ed_pe), sextuple(sext), desparacitacion(desp) {}; //Constructor con parametros

        //Getters
        void get_datos_pe();
        void muestra_perro();
};

/**
 * get_datos_pe solicita al usuario ingresar los datos del Perro
 * Pide el nombre, raza, edad, y el estado de vacunacion.
 * getline se utiliza para leer una línea de entrada del usuario 
 * y asignarla a la variable nom_perro, ws descarta cualquier espacio 
 * en blanco inicial antes de leer la línea completa
 * 
 * 
 * @param
 * @return
 */
void Perro::get_datos_pe(){
    cout << "\nSobre el PERRO, ingresa lo solicitado.\nNombre: "; getline(cin >> ws, nom_perro);
    cout << "Raza: "; getline(cin >> ws, raza); 
    cout << "Edad (anios): "; cin >> edad_perro;
    cout << "Vacunacion (1 = SI / 0 = NO)\nSextuple --> "; cin >> sextuple;
    cout << "Desparacitacion --> "; cin >> desparacitacion;
}

/**
 * muestra_perro muestra en consola la informacion del Perro
 * Muestra el nombre, raza, edad y el estado de vacunacion, asi como
 * mensajes relacionados con la vacunación.
 * 
 * @param
 * @return
 */
void Perro::muestra_perro(){
    cout <<"\n ------------- DATOS PERRO -------------\n* Nombre: " << nom_perro 
    << "\n* Raza: " << raza 
    << "\n* Edad: " << edad_perro << " anios\n";
    if (sextuple == true && desparacitacion == true){ 
        cout << "Vacunacion COMPLETA.\n";
    } else if (sextuple == false || desparacitacion == false){
        cout << "Vacunacion INCOMPLETA, podrias tener PROBLEMAS EN LA REVISION antes de la competencia.\n";
    }
}

#endif //PERRO_H