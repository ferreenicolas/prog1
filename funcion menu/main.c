#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
// listar todos los empleados
int main()
{
    char letra = 's';
    eEmpleado gente[50];
    //eSector sectores[]={{1,"RRHH",0},{2,"SISTEMAS",0},{3,"DESPOSITO",0}}; // solamente lo puedo hacer cuando lo declaro;

    inicializarEmpleados(gente , 50);

    do
    {
        switch(menu())
        {
        case 1:

            alta(gente , 50);

            system("pause");
            break;
        case 2:
            bajaEmpleado(gente, 50);

            system("pause");
            break;
        case 3:
            system("pause");
            break;
        case 4:
            listar(gente,50);

            system("pause");
            break;
        case 5:
            system("pause");
            break;
        case 6:
            letra = 'n';
            break;
        default:
            printf("\nERROR, ingrese una opcion valida.\n\n");
            system("pause");
        }
    }
    while(letra == 's');
    return 0;
}
