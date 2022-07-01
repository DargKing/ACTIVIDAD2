/*
Escribir un programa que reciba una serie de cadenas de caracteres
como argumentos. El programa deberá concatenarlas y dar la vuelta a la cadena
concatenadotante. La cadena que almacene la concatenación de los argumentos debe
utilizar la memoria justa y necesaria
*/

#include <stdio.h>
#include <stdlib.h>

int lenghtStr(char *str)
{
        int i = 0;
        while (str[i] != '\0')
        {
                i++;
        }
        return i;
}

void concatStr(char *str1, char *str2, char *var)
{

        int lenght1 = lenghtStr(str1);
        int lenght2 = lenghtStr(str2);

        // concat
        for (size_t i = 0; i < lenght1 + lenght2; i++)
        {
                if (i < lenght1)
                {
                        var[i] = str1[i];
                }
                else
                {
                        var[i] = str2[i - lenght1];
                }
        }
        var[lenght1 + lenght2] = '\0';
}

void concatStrEsp(char *str1, char *str2, char *var)
{

        int lenght1 = lenghtStr(str1);
        int lenght2 = lenghtStr(str2);

        // Concat Espaciado
        for (size_t i = 0; i < lenght1 + lenght2 + 1; i++)
        {
                if (i < lenght1)
                {
                        var[i] = str1[i];
                }
                else if (i == lenght1)
                {
                        var[i] = ' ';
                }
                else
                {
                        var[i] = str2[i - lenght1 - 1];
                }
        }
        var[lenght1 + lenght2 + 1] = '\0';
}

void strInvStr(char *str, char *var)
{

        int lenght = lenghtStr(str);

        // concat invert
        for (int i = lenght; i > 0; i--)
        {
                var[lenght - i] = str[i - 1];
                printf("%c\n", var[lenght - i]);
        }
        var[lenght] = '\0';
}

int main()
{
        char str1[150];
        char str2[150];

        puts("Introdusca Primer String: ");
        gets(str1);

        puts("Introdusca Segundo String: ");
        gets(str2);

        int lenght1 = lenghtStr(str1);
        int lenght2 = lenghtStr(str2);

        char concat[lenght1 + lenght2 + 1];
        char concatInv[lenght1 + lenght2 + 1];

        char concatEsp[lenght1 + lenght2 + 2];
        char concatInvEsp[lenght1 + lenght2 + 2];

        concatStr(str1, str2, concat);
        strInvStr(concat, concatInv);
        concatStrEsp(str1, str2, concatEsp);
        strInvStr(concatEsp, concatInvEsp);

        printf("Strings Concatenados: %s\n", concat);
        printf("Strings Concatenados con Espacio Entre Palabra: %s\n", concatEsp);
        printf("Strings Concatenado Alreves: %s\n", concatInv);
        printf("Strings Concatenado Alreves con Espacio Entre Palabras: %s\n", concatInvEsp);
        return 0;
}