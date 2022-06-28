/*
Escribir una función que calcule y presente las raíces reales de la
ecuación de segundo grado
*/

#include <stdio.h>
#include <math.h>

float ecuationX1(float a, float b, float c){
        float discriminante = (b * b - 4 * (a * c));
        b = b * -1;
        if(discriminante < 0){
                printf("( %f + √(%f)) / %f", b, discriminante, a * 2);
                printf("No Tiene Solucion Real");
                return 0;
        } else {
                float resul = (b - sqrt(discriminante)) / (a * 2);
                return resul;
        }
}

float ecuationX2(float a, float b, float c){
        float discriminante = (b * b - 4 * (a * c));
        b = b * -1;
        if(discriminante < 0){
                printf("( %f + √(%f)) / %f", b, discriminante, a * 2);
                printf("No Tiene Solucion Real");
                return 0;
        } else {
                float resul = (b + sqrt(discriminante)) / (a * 2);
                return resul;
        }
}

float main(){
        float a, b, c;

        printf("Ingrese ax^2");
        scanf("%f", &a);

        printf("Ingrese bx");
        scanf("%f", &b);
        
        printf("Ingrese c");
        scanf("%f", &c);

        float x1 = ecuationX1(a, b, c);
        float x2 = ecuationX2(a, b, c);
        printf("X1: %f\nX2: %f", x1, x2);
        getchar();
}