/*
Escribir un programa que reciba una serie de cadenas de caracteres
como argumentos. El programa deberá concatenarlas y dar la vuelta a la cadena
concatenadotante. La cadena que almacene la concatenación de los argumentos debe
utilizar la memoria justa y necesaria
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int lenghtStr(char *str)
{
        int i = 0;
        while (str[i] != '\0')
        {
                i++;
        }
        return i;
}

void *pushWord(char *str, char word)
{
        int lenght = lenghtStr(str);
        str = (char *)realloc(str, lenght + 2);
        str[lenght] = word;
        str[lenght + 1] = '\0';
}

char *invertString(char *str)
{
        int lenght = lenghtStr(str);
        char *strInv = (char *)malloc(lenght + 1);
        for (size_t i = lenght; 0 < i; i--)
        {
                strInv[lenght - i] = str[i - 1];
        }
        strInv[lenght] = '\0';
        return strInv;
}

int main()
{
        char *str;
        bool run = true;
        bool first = true;
        while (run)
        {
                char temp;
                printf("Inserte Caracter: ");
                scanf("%s", &temp);
                if (temp == '0')
                {
                        run = false;
                        break;
                }
                if (first)
                {
                        str = (char *)malloc(2);
                        str[0] = temp;
                        str[1] = '\0';
                        first = false;
                }
                else
                {
                        pushWord(str, temp);
                }
        }

        char *strInv = invertString(str);

        printf("Caracteres Concatenados: %s\n", str);
        printf("Caracteres Alreves: %s\n", strInv);
        free(str);
        free(strInv);
        return 0;
}