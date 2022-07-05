/*
Escribir un programa que reciba una serie de cadenas de caracteres
como argumentos. El programa deberá concatenarlas y dar la vuelta a la cadena
concatenadotante. La cadena que almacene la concatenación de los argumentos debe
utilizar la memoria justa y necesaria
*/

#include <stdio.h>      // Libreria para entradas y salidas

int lenghtStr(char *str)        // Esta funcion devuelve la longitud de un string sin contar el \0
{
        int i = 0;              // Esta variable almacenara la longitud del string
        while (str[i] != '\0')  // Mientras la casilla no sea \0 entonces se sumara 1 a i
        {
                i++;
        }
        return i;               // Devuelve la longitud del string
}

/*
Una funcion no puede devolver un array de forma normal, para logralo hay que usar 
la memoria dinamica. Y el uso de la memoria dinamica en este ejercicio esta prohibido
asi que para solucionar esa problematica lo que se hara es modificar directamente la
variable donde se esta almacenando el array
*/

/*
La funcion cancatStr tiene 3 parametros, str1, str2 y var, Esta funcion concatena dos palabras. 
La primera palabra es str1, la palabra a concatenar es str2 y var sera donde se almacenara
el resultado de la concatenacion
*/

void concatStr(char *str1, char *str2, char *var)
{

        int lenght1 = lenghtStr(str1);  // Se obtiene el tamaño del string1 
        int lenght2 = lenghtStr(str2);  // Se obtiene el tamaño del string2

        // concat
        for (size_t i = 0; i < lenght1 + lenght2; i++)  // Es te bucle funcionara hasta que se recorran los dos strings
        {
                if (i < lenght1) // si i es menor a lenght1 entonces en el parametro var[i] se guardara str1[i]
                {
                        var[i] = str1[i];
                }
                else    // si no lo es entonces significa que se debe concatenar la segunda variable
                {
                        var[i] = str2[i - lenght1];     // en el parametro var[i] se guarda la casilla str2[i - lenght1]
                                                        // el i - lenght1 se usa para que el conteo sea desde 0
                }
        }
        var[lenght1 + lenght2] = '\0';  // Se introduce en la ultima casilla disponible el \0 dando por terminado ese string
}


/*
La funcion cancatStrEsp tiene 3 parametros, str1, str2 y var, esta funcion hace lo mismo que concatStr
pero la diferencia es que pone un espacio en la concatenacion de las dos palabras
*/

void concatStrEsp(char *str1, char *str2, char *var)
{

        int lenght1 = lenghtStr(str1);  // Se obtiene el tamaño del string1 
        int lenght2 = lenghtStr(str2);  // Se obtiene el tamaño del string2

        // Concat Espaciado
        for (size_t i = 0; i < lenght1 + lenght2 + 1; i++)      // Es te bucle funcionara hasta que se recorran los dos strings + 1
        {
                if (i < lenght1) // si i es menor a lenght1 entonces en el parametro var[i] se guardara str1[i]
                {
                        var[i] = str1[i];
                }
                else if (i == lenght1)  // si i es igual a la longitud de lenght1 entonces se le introducira un espacio en esa casilla
                {
                        var[i] = ' ';
                }
                else    // si no lo es entonces significa que se debe concatenar la segunda variable
                {
                        var[i] = str2[i - lenght1 - 1]; // i - lenght - 1 hace que se comience a contar las casillas desde el 0
                }
        }
        var[lenght1 + lenght2 + 1] = '\0';      // Se introduce en la ultima casilla disponible el \0 dando por terminado ese string
}



/*
La funcion strInvStr tiene 2 parametros, str y var, esta funcion le da la vuelta a un string,
str es el string al que se le dara la vuelta y var es donde se guardara ese string
*/

void strInvStr(char *str, char *var) 
{

        int lenght = lenghtStr(str);  // Se obtiene el tamaño del string

        // concat invert
        for (int i = lenght; i > 0; i--)        // el bucle comienza desde el final del array y termina cuando sea igual a 0
        {
                var[lenght - i] = str[i - 1];   /*
                                                lenght - i hace que la posicion de i comience desde 0 hasta el tamaño del array - 1,
                                                i - 1 sirve para obtener la casilla alterior a i*/
        }
        var[lenght] = '\0';     // Almacena en la ultima casilla \0
}

int main()
{
        char str1[150]; // Se crea un string con un maximo de 150 letras
        char str2[150]; // Se crea un string con un maximo de 150 letras

        puts("Introdusca Primer String: ");
        gets(str1);     // Se almacena en str1 el primer string

        puts("Introdusca Segundo String: ");
        gets(str2);     // Se almacena en str2 el segundo string

        int lenght1 = lenghtStr(str1);  // Obtiene el tamaño del primer string
        int lenght2 = lenghtStr(str2);  // Obtiene el tamaño del primer string

        char concat[lenght1 + lenght2 + 1];     // Reserva la memoria para un string con el tamaño de los dos strings a concatenar, 
                                                // esta variable guardara los dos strings concatenados
        char concatInv[lenght1 + lenght2 + 1];  /* Reserva en memoria la concatenacion de los dos strings invertidos */

        char concatEsp[lenght1 + lenght2 + 2];  /* Reserva en memoria la concatenacion de los dos strings mas 1 */
        char concatInvEsp[lenght1 + lenght2 + 2];/* Reserva en memoria la concatenacion inversa de los dos strings mas 1 */

        concatStr(str1, str2, concat);  // Concatena los dos strings y los guarda en la variable concat
        strInvStr(concat, concatInv);   // Invierte el string concat y lo guarda en concatInv
        concatStrEsp(str1, str2, concatEsp);    // concatena con un espacio en medio los dos strings y lo guarda en concatEsp
        strInvStr(concatEsp, concatInvEsp);     // Invierte la concatenacion con un espacio

        // Imprime en pantalla el resultado de las funciones
        printf("Strings Concatenados: %s\n", concat);
        printf("Strings Concatenados con Espacio Entre Palabra: %s\n", concatEsp);
        printf("Strings Concatenado Alreves: %s\n", concatInv);
        printf("Strings Concatenado Alreves con Espacio Entre Palabras: %s\n", concatInvEsp);
        return 0;
}