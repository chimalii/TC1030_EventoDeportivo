/*
 * Proyecto Evento Deportivo
 * Gabriela Chimali Nava Ramirez
 * A01710530
 * 16/06/2023
 *
 * Este programa permite llenar ordenadamente una inscripcion 
 * a una carrera con diferentes modalidades, introducir datos
 * del participante y las mascotas con las que competira.
 *
 */

//Bibliotecas
#include <iostream> //permite realizar operaciones de entrada y salida en consola.
#include <cstdlib> //para generar de numeros aleatorios y manipular cademas de caracteres.
#include <ctime> //para trabajar con hora, apoya a generacion de numero aleatorio.
#include <string> //para usar getline y leer una linea completa de entrada.
#include <cstdio> //para guardar info que se imprime en consola en un archivo tipo txt.

#include "inscripcion.h"

using namespace std;

int main(){
    Inscripcion insc;
    insc.agrega_persona();
    insc.agrega_mods();
    insc.agrega_perro();

    // Limpiar la consola
    #ifdef _WIN32
        system("cls"); // En Windows
    #else
        system("clear"); // En UNIX (Linux, macOS)
    #endif

    insc.imprime_todo();

    //Escribir en el archivo inscripcion_lleva.txt la informacion introducida por el usuario
    FILE* archivo = freopen("inscripcion_llena.txt", "w", stdout);
    insc.imprime_todo();
    fclose(archivo);
    
    return 0;
}