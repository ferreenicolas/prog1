#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int legajo;
    float sueldo;
    char sexo;
}eEmpleado;

void mostrarEmpleado(eEmpleado);
void mostrarEmpleados(eEmpleado[], int);
void ordenarEmpleado(eEmpleado[], int);

int main()
{
    eEmpleado plantel[] = {{"Juan", 1111, 1000.75, 'm'},{"Ana", 2222, 20000, 'f'},{"Luis", 3333, 30000, 'm'}};

    ordenarEmpleado(plantel, 3);

    mostrarEmpleados(plantel, 3);
    return 0;
}


void mostrarEmpleado(eEmpleado emp)
{
    printf("Nombre: %s\n", emp.nombre);
    printf("Legajo: %d\n", emp.legajo);
    printf("Sexo: %c\n", emp.sexo);
    printf("Sueldo: %.2f\n", emp.sueldo);
}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
        {
            mostrarEmpleado(vec[i]);
        }
}

void ordenarEmpleado(eEmpleado vec[], int tam)
{
    int i;
    int j;
    eEmpleado aux;

    for(i=0; i< tam-1;i++)
        {
            for (j=0; j< i+1;j++)
                {
                    if(strcmp(vec[i].nombre, vec[j].nombre) > 0)
                        {
                         aux= vec[i];
                         vec[i] = vec[j];
                         vec[j] = aux;
                        }
                }
        }
}
