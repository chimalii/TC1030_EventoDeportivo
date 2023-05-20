# TC1030_EventoDeportivo
La inscripción a una Dryland necesita escencialmente los datos nombre completo, género y edad, se permite inscribir de una a tres mosalidades:
1. Canicross, unicamente correr con tu perro.
2. Bikejoring, también con perro y para la cual se usa una bicicleta, si decides rentar el equipo incluye un costo adicional.
3. Scooter, con uno o dos perros (lo establecerán los organizadores, pudiendolo modficar en una variable del código) y un scooter, si decides rentar el equipo también hay un costo adicional.

Para participar debes formar parte de la FEMEDCAN (Federación Mexicana de Dryland Canino) y debes contar con un número de competidor, otorgado por esta asociación, si este número inicia con 0 quiere decir que no cuentas con un DID, si es 1, cuentas con DID, el costo por modalidad puede variar si cuentas o no con DID, si lo tienes, te realiza un descuento de 20%. Se incluirá la opción de comprar un DID durante la inscripción por si quieres contar con los beneficios de este.

Este programa toma como base el proyecto para TC1033, pero cuenta con funcionalidades adicionales y mejoras en el código.

## UML
https://lucid.app/lucidchart/add87556-9b94-48e0-866e-aa280e5036fe/edit?viewport_loc=60%2C432%2C1743%2C815%2C0_0&invitationId=inv_e03eedff-d621-4a18-b4f3-ea878b518e58

## Para qué sirve y para qué no sirve
Este programa mostrará datos importantes de la carrera, como organizadores y sede, recibirá los datos del participante, del(los) perro(s) y modalidad(es) inscrita(s). Después mostrará los datos de la inscripción, previamente introducidos, así como los costos calculados. Sólo puede realizarse una inscripción a la vez y deben introducirse los datos tal como se solicitan.

## Cómo se usa
Se despliega un menú para que el usuario decida para qué modalidad quiere visualizar los ejemplos. Debe introducir únicamente número dentro del menú, si no lo hace saldrá del programa.

Para correr el código en Windows debes guardar los archivos .h y .cpp en una misma carpeta, abrir el Símbolo del Sistema, copiar el path de la carpeta donde guardaste los archivos, enter y usar la forma:
- g++ mainCarrera.cpp -o mainCarrera.exe
- Enter
- mainCarrera
- Enter
