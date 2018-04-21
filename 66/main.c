#include <stdio.h>
#include <stdlib.h>
/*
 De los 30 empleados de una fábrica se registra la edad, el sexo y el legajo.
 Terminado el ingreso se pide conocer:  La edad promedio de los empleados de la fábrica.
 El legajo y sexo de la persona de mayor edad.  Cuántas mujeres nacieron en el año 1978.
*/

#define ELEM 3


int main()
{
    int edad[ELEM]=  {40, 27 , 33};
    char sexo[ELEM]= {'f', 'm', 'f'};
    int legajo[ELEM]= {111, 222, 333};
    int i;
    float acumulador = 0;
    float promedio;
    int contador = 0;


    int mayorEdad;
    char mayorSex;
    int mayorLeg;



    mayorEdad = edad[0];

    for(i=0; i < ELEM; i++)
        {

            acumulador = edad[i] + acumulador;
            promedio = acumulador / ELEM;

            if(edad[i] > mayorEdad)
                {
                    edad[i] = mayorEdad;
                    sexo[i] = mayorSex;
                    legajo[i] = mayorLeg;
                }

            if(edad[i] == 40 && sexo[i] == 'f')
                {
                    contador++;
                }

        }
    printf("%.2f \n", promedio);

    printf("%c \n", mayorSex);

    printf("Cantidad de mujeres que nacieron en 1978: %d", contador);



    return 0;
}
