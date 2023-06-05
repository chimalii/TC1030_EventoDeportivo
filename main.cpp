# include "modalidad.h"
# include "participante.h"
# include <iostream>

int main(){

    Participante inscripcion;
    inscripcion.get_nombre();
    inscripcion.get_edad();
    inscripcion.get_genero();
    inscripcion.get_cant_mod();
    inscripcion.get_DID();
    inscripcion.calc_precio_total();
    inscripcion.datos_persona();

    return 0;
}
