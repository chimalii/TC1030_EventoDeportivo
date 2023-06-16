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

## Para qué sirve y para qué no sirve // Casos de falla
Este programa recibirá los datos del participante, del(los) perro(s) y modalidad(es) inscrita(s). Después mostrará los datos de la inscripción, previamente introducidos, así como los costos calculados. Sólo puede realizarse una inscripción a la vez y deben introducirse los datos tal como se solicitan.
Si los organizadores (quienes se espera tengan control del programa) quisieran realizar algún cambio en los precios, distancia o cantidad de perros lo pueden hacer directamente en donde se crean los objetos que heredan de Modalidad en el archivo "inscripcion.h".

## Cómo se usa
En la consola se van indicando los datos que se deben introducir y el usuario teclea su información, el código ya cuenta con instrucciones claras para evitar salir del programa, una vez que se llenan estos, la consola se limpia y se muestra un resumen de la infromación de la inscripción, además estos se guardan en un archivo .txt.

Para correr el código en Windows debes guardar los archivos .h, .cpp y .txt en una misma carpeta, abrir el Símbolo del Sistema, copiar el path de la carpeta donde guardaste los archivos, enter y usar la forma:
- g++ main.cpp -o main.exe
- Enter
- main
- Enter

## Correcciones (y dónde observarlas)
1. Genero un diagrama de clases UML correcto y y explico su relación con el problema de forma clara -> Archivo pdf con UML, se ordenó e indicaron correctemente los tipos de datos en el UML. La clase Participante compone Inscripcion, debido a una confusión se invirtió la direción de la relación.
2. Implementación correcta del concepto Herencia, sobrecarga y sobreescritura de métodos -> se agregó el Archivo "modalidad.h". Ejemplos: Herencia -> línea 46, 84; Sobreescritura -> 64, 112.
3. Implementación correcta del concepto Clases Abstractas -> Archivo "modalidad.h", en la clase padre Modalidad, se declaran virtuales los métodos (líneas 41-42), no se puede crear un objeto de este tipo, pero si de las clases que lo heredan, esto es visible en el archivo "inscripcion.h", por ejemplo en la línea 98 y 106. Además separé las clases en diferentes archivos para facilitar su comprensión y análisis.
4. Se agregaron más comentarios al código y una descripción más amplia en el README para facilitar la compresión del programa, su funcionalidad y los casos de falla.
5. Encada archivo se puede revisar el historial de commits, que incluye breves descripciones de los cambios en las funciones o la relación entre clases, implementadas a lo largo del periodo para cumplir con las competencias y optimizar el código.
