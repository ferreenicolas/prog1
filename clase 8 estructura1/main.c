#include <stdio.h>
#include <stdlib.h>

typedef struct
{
char nombre[20];
int legajo;
float sueldo;
char sexo;
}eEmpleado;

void mostrarEmpleado(eEmpleado emp);

int main()
{
    eEmpleado unEmpleado;
    eEmpleado dosEmpleado;



    //unEmpleado.legajo = 001;

    printf("Ingrese legajo: ");
    scanf("%d", &unEmpleado.legajo);

    //strcpy(unEmpleado.nombre, "Juan");

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(unEmpleado.nombre);


    //unEmpleado.sexo='m';

    printf("Ingrese el sexo(f o m): ");
    fflush(stdin);
    scanf("%c", &unEmpleado.sexo);

    //unEmpleado.sueldo=50000.50;
    printf("Ingrese el sueldo: ");
    scanf("%f", &unEmpleado.sueldo);

    unEmpleado.sexo= toupper(unEmpleado.sexo);

    mostrarEmpleado(unEmpleado);
    dosEmpleado = unEmpleado;
    mostrarEmpleado(dosEmpleado);

    return 0;
}

void mostrarEmpleado(eEmpleado emp)
{
    printf("Nombre: %s\n", emp.nombre);
    printf("Legajo: %d\n", emp.legajo);
    printf("Sexo: %c\n", emp.sexo);
    printf("Sueldo: %.2f\n", emp.sueldo);
}
