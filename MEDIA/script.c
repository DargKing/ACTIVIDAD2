#include <stdio.h> // Libreria para entradas y salidas


/*
        La funcion media tiene de parametros un array de datos tipo float que contendra a todos 
        los numeros a promediar, y como segundo parametro tiene un tipo size_t que es la longitud del array mas un numero
*/

float media(float *array, size_t n)
{
        float sum = 0; // Esta variable acomulara la suma de todos los elementos del array
        for (int i = 0; i < n; i++) // se seguira iterando hasta que i sea igual a n
        {
                sum += array[i]; // Se suma el valor actual de la variable sum con el valor que tenga esa casilla del array
        }
        return sum / n; // Se divide la suma de todos los elementos del array por su tamaño + 1
}

float main()
{
        int n; // Se reserva el espacio en memoria de la variable
        printf("Introdusca la cantidad de datos a poner "); // Se le indica al usuario ingresar la cantidad de numeros a promediar
        scanf("%d", &n); // Se almacena en n la cantidad de numeros a promediar
        float array[n]; // Se reserva el espacio en memoria del array

        for (int i = 0; i < n; i++){ // se seguira iterando hasta que i sea igual a n
                printf("\nIntrodusca valor N%d ", i); // Se le indica al usuario que introdusca un valor
                scanf("%f", &array[i]); // almacena en memoria el valor
        }

        float resultado = media(array, n); // Se guarda en esta variable el valor que retorna la funcion media
        printf("\nLa media es %f", resultado); // Se imprime en pantalla la variable resultado
        return 0; // Se termina el programa
}