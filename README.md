# TC1030_EventoDeportivo
La inscripción a una Dryland necesita escencialmente los datos nombre completo, género y edad, se permite inscribir de una a tres modalidades:
1. Canicross, unicamente CORRER con tu perro.
2. Bikejoring, también con perro y para la cual se usa una BICICLETA, si decides rentar el equipo incluye un costo adicional.
3. Scooter, con uno o dos perros (lo establecerán los organizadores, pudiéndolo modoficar en una variable del código, en esta ocación se estableceron 2) y un SCOOTER, si decides rentar el equipo también hay un costo adicional.

Cualquiera puede participar, pero para rankear debes formar parte de la FEMEDCAN (Federación Mexicana de Dryland Canino) y debes contar con un DID que te permite tener un número de afiliación, otorgado por esta asociación. Si cuentas con DID, al costo de cada modalidad que inscribas se le aplicará un descuento del 20%. Se incluirá la opción de comprar un DID durante la inscripción por si quieres contar con los beneficios de este.

A parte de la aplicación del descuento o no, si decides rentar equipo, se despliega un mení con las opciones de renta y los costos, esto se suma al precio total y al imprimir los datos se indicará lo que rentaste y su costo, así como la cotización total de tu inscripción.

Como es un deporte acompañado de tus mascotas, se pregunta cuántos perros llevarás a la competencia y se llena la información para cada uno de estos.

Finalmente, tras llenar los datos, estos se guardarán en un archivo de texto.

Este programa toma como base el proyecto para TC1033, pero cuenta con funcionalidades adicionales y mejoras en el código.

## UML
https://lucid.app/lucidchart/add87556-9b94-48e0-866e-aa280e5036fe/edit?viewport_loc=60%2C432%2C1743%2C815%2C0_0&invitationId=inv_e03eedff-d621-4a18-b4f3-ea878b518e58

## Para qué sirve y para qué no sirve
Este programa mostrará datos importantes de la carrera, como organizadores y sede, recibirá los datos del participante, del(los) perro(s) y modalidad(es) inscrita(s). Después mostrará los datos de la inscripción, previamente introducidos, así como los costos calculados. Sólo puede realizarse una inscripción a la vez y deben introducirse los datos tal como se solicitan.

## Cómo se usa
En la consola se van indicando los datos que se deben introducir y el usuario teclea su información, el código ya cuenta con instrucciones claras para evitar salir del programa, una vez que se llenan estos, la consola se limpia y se muestra un resumen de la infromación de la inscripción, además estos se guardan en un archivo .txt.

Para correr el código en Windows debes guardar los archivos .h, .cpp y .txt en una misma carpeta, abrir el Símbolo del Sistema, copiar el path de la carpeta donde guardaste los archivos, enter y usar la forma:
- g++ main.cpp -o main.exe
- Enter
- main
- Enter
