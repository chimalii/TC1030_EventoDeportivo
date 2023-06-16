#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstdio> //para guardar info que se imprime en consola en un archivo tipo txt

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

    FILE* archivo = freopen("inscripcion_llena.txt", "w", stdout);
    insc.imprime_todo();
    fclose(archivo);
    
    return 0;
}