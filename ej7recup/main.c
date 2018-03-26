#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int nota;
    int edad;
    char sexo;
    float promedioNotas;
    int acumuladorNotas = 0;
    int notaBaj;
    char sexBaj;
    int contadorVarones18 = 0;
    int notaMin;
    char sexMin;
    int edadMin;


    for(int contador = 0; contador < 5; contador++)
    {
        printf("Ingrese sexo F o M: ");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo= tolower(sexo);
        while(sexo != 'f' && sexo != 'm')
        {
          printf("Ingrese sexo F o M: ");
          fflush(stdin);
          scanf("%c", &sexo);
          sexo= tolower(sexo);
        }
        printf("Ingrese la nota: ");
        scanf("%d", &nota);
        while(nota < 0 || nota > 10)
            {
                printf("Ingrese la nota");
                scanf("%d", &nota);
            }
        printf("Ingrese la edad: ");
        scanf("%d", &edad);

            while(edad < 0 || edad > 100)
                {
                    printf("Ingrese la edad: ");
                    scanf("%d", &edad);
                }
        //acumulador
        acumuladorNotas = acumuladorNotas + nota;
        promedioNotas = (float) acumuladorNotas / 5;
        //nota mas baja y sexo de la persona
        if(contador == 0)
            {
              notaBaj= nota;
              sexBaj = sexo;
            }
            else
                {
                if(nota < notaBaj)
                    {
                    nota = notaBaj;
                    sexo = sexBaj;
                    }
                }
         //cantidad varones mayores a 18.

         if(sexo == 'm' && edad > 18 && nota > 5)
            {
              contadorVarones18++;
            }

        // nota mas joven y sexo mas joven.

        if(contador == 0)
            {
             edadMin = edad;
             notaMin = nota;
             sexMin = sexo;
            }
            else
                {
                if (edad < edadMin)
                    {
                        edad = edadMin;
                        nota = notaMin;
                        sexo = sexMin;
                    }
                }



    }
    printf("El promedio de notas totales fue: %.2f\n", promedioNotas);
    printf("La nota mas baja fue: %d y el sexo de esa persona: %c\n", notaBaj, sexBaj);
    printf("Cantidad varones mayores a 18 y con nota igual o mayor a 6 son: %d\n", contadorVarones18);
    printf("La nota mas joven fue: %d y el sexo de esa persona: %c\n", notaMin, sexMin);


    return 0;
}
