#include <stdio.h>
#include <stdlib.h>

void mostrarCadena(char* punteroCadena);

struct alumno
{
char nombre[20];
int edad;
};

int main()
{
    char cad[]={"hola carlos baute"};

    struct alumno auxiliarAlumno;
    struct alumno *punteroAlumno;
    punteroAlumno = &auxiliarAlumno;

    printf("Ingrese nombre: \n");

    gets((*punteroAlumno).nombre);

    printf("Ingrese edad: \n");
    scanf("%d", &(*punteroAlumno).edad);

    printf("Nombre: %s\nEdad: %d\n", (*punteroAlumno).nombre, (*punteroAlumno).edad);


    //mostrarCadena(cad);
    return 0;
}

void mostrarCadena(char* punteroCadena)
{
    while(*punteroCadena != '\0')
        {
            printf("%c", *punteroCadena);
            punteroCadena++;
        }
}
