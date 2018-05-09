#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char letra = 's';

    eProducto productos[5];
    eProveedor proveedores[5];

    inicializarProductos(productos , 5);

    do
    {
        switch(menu())
        {
        case 1:

            alta(productos,5);

            system("pause");
            break;
        case 2:
            modificaProducto(productos, 5, proveedores, 5);

            system("pause");
            break;
        case 3:
            bajaProducto(productos,5);

            system("pause");
            break;
        case 4:
            informar(productos,5);

            system("pause");
            break;
        case 5:
            listar()
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
