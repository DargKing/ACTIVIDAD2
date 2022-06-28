#include <stdio.h> // Libreria para entradas y salidas

/*
        Funcion para sumar dos valores, esta sigue la formula c = a + b, 
        donde a y b son variables de tipo flotante.
        Esta funcion retorna un valor de tipo float
*/

float suma(float a, float b){
        float c = a + b; // La variable c almacena el resultado de la suma de a y b
        return c; // Se retorna el resultado de a y b almacenado en la variable c
}

/*
        Dentro de la funcion main se pediran los valores que despues se pasaran a la funcion suma
*/

int main (){
        float a, b; // Se reserva el espacio en memoria de las variables a y b

        printf("Introdusca N1: "); // Esta salida le indica al usuario que tiene que ingresar un numero
        scanf("%f", &a); // El valor introducido por el usuario se almacena en la variable a

        printf("Introdusca N2: "); // Esta salida le indica al usuario que tiene que ingresar un numero
        scanf("%f", &b); // El valor introducido por el usuario se almacena en la variable a

        float c = suma(a, b); // Se almacena en esta variable el valor retornado de la variable suma despues de haberle pasado a y b como argumento

        printf("%f mas %f es igual a %.2f", a, b, c); // Se imprime en pantalla a y b junto con el resultado de la suma de esos dos
        return 0; // Se detiene el programa
}