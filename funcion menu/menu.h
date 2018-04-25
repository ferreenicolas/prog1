#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//ESTRUCTURAS:
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int isEmpty;
    eFecha fechaIngreso;
    int idSector;
}eEmpleado;

typedef struct
{
int id;
char descripcion[51];
int isEmpty;
}eSector;

//FUNCIONES:
//GENERA MENU:
int menu();
//INICIALIZA INDICES EN 1 (PARA QUE ESTEN VACIOS)
void inicializarEmpleados(eEmpleado[] , int);

int buscarLibre(eEmpleado[] , int);

void alta(eEmpleado[], int);

void listar(eEmpleado[], int);

int buscarEmpleado(eEmpleado[] , int , int);

void mostrarEmpleado(eEmpleado);

int buscarEmpleados(eEmpleado emp[] , int tam , int legajo);

void bajaEmpleado(eEmpleado vec[], int tam);

void hardCode(eSector sectores[]);





#endif // FUNCIONES_H_INCLUDED
