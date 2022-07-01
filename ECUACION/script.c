/*
Escribir una función que calcule y presente las raíces reales de la
ecuación de segundo grado
*/

#include <stdio.h> // Libreria para entradas y salidas
#include <math.h> // Libreria para funciones matematicas

/*
Se crean dos funciones que cambiaran levemente las ecuaciones 
para que devuelvan x1 y x2.
Estas funciones devuelven el resultado de las ecuaciones de segundo grado
ax^2 + bx + c = 0
La formula utilizada para resolver esta ecuacion es
-b +- √(b^2 -4ac)
------------------
        2a
Esta formula tiene dos resultados, x1 y x2

De una forma que lo entenderia un lengueje de programacion seria
X1 = (-b - √(b * b (-4 * a * c))) / (2 * a)
X2 = (-b + √(b * b (-4 * a * c))) / (2 * a)
*/


// Esta funcion devuelve el resultado de la ecuacion ((-b - √Δ) / 2 * a)
float ecuationX1(float a, float b, float c){
        float discriminante = (b * b - 4 * (a * c));    /* Esta intruccion obtiene el determinante de la ecuacion
                                                        el determinante es Δ = b^2 - 4ac */
        if(discriminante < 0){ // si Δ < 0 entonces la funcion no tiene solucion real, por lo tanto finaliza la ejecucion de la funcion
                printf("( %f + √(%f)) / %f\n", b, discriminante, a * 2);
                printf("No Tiene Solucion Real");
                return 0;       // Termina la ejecucion de la funcion
        } else {
                float resul = (-b - sqrt(discriminante)) / (a * 2);     // Obtiene el resultado de x1
                return resul;   // Devuelve x1
        }
}

// Esta funcion devuelve el resultado de la ecuacion ((-b + √Δ) / 2 * a)
float ecuationX2(float a, float b, float c){
        float discriminante = (b * b - 4 * (a * c));    /* Esta intruccion obtiene el determinante de la ecuacion
                                                        el determinante es Δ = b^2 - 4ac */
        if(discriminante < 0){ // si Δ < 0 entonces la funcion no tiene solucion real, por lo tanto finaliza la ejecucion de la funcion
                printf("( %f + √(%f)) / %f", b, discriminante, a * 2);
                printf("No Tiene Solucion Real");
                return 0;       // Termina la ejecucion de la funcion
        } else {
                float resul = -(b + sqrt(discriminante)) / (a * 2);     // Obtiene el resultado de x2
                return resul;   // Devuelve x2
        }
}

int main(){
        float a, b, c;  // Se reserva el espacio en memoria de a (x^2), b (x) ý c

        printf("Ingrese ax^2: ");       // Se le solicita al usuario ingresar ax^2
        scanf("%f", &a);                // Se almacena en "a" el numero ingresado

        printf("Ingrese bx");           // Se le solicita al usuario ingresar bx
        scanf("%f", &b);                // Se almacena en "b" el numero ingresado
        
        printf("Ingrese c");            // Se le solicita al usuario ingresar c
        scanf("%f", &c);                // Se almacena en "c" el numero ingresado

        float x1 = ecuationX1(a, b, c);         /* Se almacena en memoria el resultado devuelto por la 
                                                funcion ecuationX1, este resultado equivaldria a X1 */

        float x2 = ecuationX2(a, b, c);         /* Se almacena en memoria el resultado devuelto por la 
                                                funcion ecuationX2, este resultado equivaldria a X2 */
                                                
        printf("X1: %f\nX2: %f", x1, x2);       /* Se imprime en pantalla el resultado de X1 y X2 */
        return 0;
}