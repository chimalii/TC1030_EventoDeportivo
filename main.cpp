# include "modalidad.h"
# include <iostream>

int main(){
    
    Correr mod1(4.5, 1, "Canicross");
    mod1.calc_precio(200.0);

    Bicicleta mod2(4.5, 1, "Bikejoring");
    mod2.calc_precio(300.0);
    mod2.calc_renta();

    Scooter mod3(4.5, 2, "Scooter");
    mod3.calc_precio(300.0);
    mod3.calc_renta();

    mod1.imprime_info();
    mod2.imprime_info();
    mod3.imprime_info();



}