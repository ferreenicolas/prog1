#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main()
{
    char letra = 's';
    eEmpleado gente[50];

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
