#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
    int opcion;

    system("cls");

    printf("1 - ALTA.\n");
    printf("2 - BAJA.\n");
    printf("3 - MODIFICACION.\n");
    printf("4 - LISTAR.\n");
    printf("5 - ORDENAR.\n");
    printf("6 - SALIR.\n");

    printf("\nElija lo que quiere hacer: ");
    scanf("%d" , &opcion);

    return opcion;
}

void inicializarEmpleados(eEmpleado emp[] , int tam)
{
    int i;

    for(i=0 ; i < tam ; i++)
    {
        emp[i].isEmpty = 1;
    }
}


int buscarLibre(eEmpleado emp[] , int tam)
{
    int i;
    int indiceVacio = -1;

    for(i=0 ; i < tam ; i++)
    {
        if(emp[i].isEmpty == 1)
        {
            indiceVacio = i;
            break;
        }
    }

    return indiceVacio;
}


void alta(eEmpleado emp[], int tam)
{
    int i;
    int indice;
    int esta;
    int legajo;
    eEmpleado nuevoEmpleado;


    system("cls");
    printf("Alta empleado.\n");

    indice = buscarLibre(emp, tam);

    if(indice == -1)
        {
            printf("\n El sistema está completo. No se puede dar de alta a empleados nuevos.\n");
        }
        else
            {

                printf("Ingrese legajo: ");
                scanf("%d", &legajo);


                esta = buscarEmpleado(emp, tam, legajo);

            }
            if(esta!= -1)
                {
                    printf("\n El legajo %d ya esta dado de alta en el sistema.\n", legajo);
                    mostrarEmpleado(emp[esta]);

                }
                else
                    {
                    nuevoEmpleado.isEmpty = 0;
                    nuevoEmpleado.legajo = legajo;

                    printf("Nombre: ");
                    fflush(stdin);
                    gets(nuevoEmpleado.nombre);

                    printf("Sexo: ");
                    scanf("%c" , &nuevoEmpleado.sexo);
                    fflush(stdin);

                    printf("Salario: ");
                    scanf("%f", &nuevoEmpleado.sueldo);

                    printf("Dia: ");
                    scanf("%d", &nuevoEmpleado.fechaIngreso.dia);

                    printf("Mes: ");
                    scanf("%d", &nuevoEmpleado.fechaIngreso.mes);

                    printf("Año: ");
                    scanf("%d", &nuevoEmpleado.fechaIngreso.anio);

                    printf("Sector: \n");

                    do{
                    printf("1- RRHH. \n 2- SISTEMAS. \n 3- ADMINISTRACION. \n 4-COMPRAS.\n 5-DEPOSITO.\n");
                    scanf("%d", &nuevoEmpleado.idSector);
                    }while(nuevoEmpleado.idSector > 5);

                    /*switch(eSector.id)
                    {
                    case 1:
                        eSector.id = eEmpleado.idSector;
                        printf("1- Recursos Humanos.");
                    case 2:
                        eSector.id = eEmpleado.idSector;
                        printf("2- Sistemas.");
                    case 3:
                        eSector.id = eEmpleado.idSector;
                        printf("3- Administracion.");
                    case 4:
                        eSector.id = eEmpleado.idSector;
                        printf("4-Compras.");
                    case 5:
                        eSector.id = eEmpleado.idSector;
                        printf("5- Deposito.");

                    }*/

                    emp[indice] = nuevoEmpleado;


                    }



   /* for(i=0; i<tam; i++)
    {
        if(emp[i].isEmpty == 1)
        {
            printf("Legajo: ");
            scanf("%d", &emp[i].legajo);

            printf("Nombre: ");
            fflush(stdin);
            gets(emp[i].nombre);
            //scanf("%s", emp[i].nombre);

            printf("Sexo: ");
            scanf("%c" , &emp[i].sexo);
            fflush(stdin);

            printf("Salario: ");
            scanf("%f", &emp[i].sueldo);

            printf("Dia: ");
            scanf("%d", &emp[i].fechaIngreso.dia);

            printf("Mes: ");
            scanf("%d", &emp[i].fechaIngreso.mes);

            printf("Año: ");
            scanf("%d", &emp[i].fechaIngreso.anio);

            emp[i].isEmpty = 0;

            break;
        }
    }*/
}


void listar(eEmpleado emp[], int tam)
{
    int i;

    printf("Legajo:\tNombre:\tSexo:\t\t\tFechaIng:\tSalario:\n\n");

    for(i=0; i<tam; i++)
    {
        if(emp[i].isEmpty == 0)
        {
            printf("%d\t%s\t%c\t\t\t%d/%d/%d\t%.2f\n", emp[i].legajo, emp[i].nombre, emp[i].sexo, emp[i].fechaIngreso.dia, emp[i].fechaIngreso.mes, emp[i].fechaIngreso.anio, emp[i].sueldo);
        }
    }
}

//funcion que liste uno solo;

int buscarEmpleado(eEmpleado emp[] , int tam , int legajo)
{
    int i;
    //int legajoIngresado;
    int legajoEstado = -1;



  /*  printf("Ingrese un legajo a buscar: ");
    scanf("%d" , &legajoIngresado);*/

    for(i=0 ; i < tam ; i++)
    {
        if(legajo == emp[i].legajo)
        {
            legajoEstado = i;
            break;
        }
    }
    return legajoEstado;
}



void mostrarEmpleado(eEmpleado emp)
{
    printf("  %4d     %s     %c  %10.2f    %02d/%02d/%4d \n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio );
}
void bajaEmpleado(eEmpleado vec[], int tam){
int legajo;
int esta;
char confirma;

system("cls");
printf("---Baja Empleado---\n\n");

   printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if(esta == -1)
        {
            printf("\nEl legajo %d no se encuentra en el sistema\n\n", legajo);

        }
        else{

                mostrarEmpleado(vec[esta]);

        do{
            printf("\nConfirma baja? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            vec[esta].isEmpty = 1;
            printf("\nSe ha realizado la baja\n\n");
        }
        else{
            printf("\nSe ha cancelado la baja\n\n");
        }

        }
}
void hardCode(eSector sectores[]){

    sectores[0].id = 1;
    strcpy(sectores[0].descripcion, "RRHH");
    sectores[0].isEmpty = 0;

    sectores[1].id = 2;
    strcpy(sectores[1].descripcion, "Sistemas");
    sectores[1].isEmpty = 0;

    sectores[2].id = 3;
    strcpy(sectores[2].descripcion, "Administracion");
    sectores[2].isEmpty = 0;

    sectores[3].id = 4;
    strcpy(sectores[3].descripcion, "Compras");
    sectores[3].isEmpty = 0;

    sectores[4].id = 5;
    strcpy(sectores[4].descripcion, "Deposito");
    sectores[4].isEmpty = 0;

}
