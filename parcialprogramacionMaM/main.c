#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int opcion;
    char seguir = 's';

    eProveedor proveedores[3];
    eProducto productos[3];
    eId ids;

    inicializarProveedores(proveedores,3);
    inicializarProducto(productos,3);

while(seguir == 's')
    {
    printf("1-ALTA PROVEEDOR.\n");
    printf("2-ALTA PRODUCTO.\n");
    printf("3-MODIFICAR PRODUCTO.\n");
    printf("4-BAJA PRODUCTO.\n");
    printf("5-INFORMAR.\n");
    printf("6-LISTAR.\n");
    printf("7-SALIR.\n");
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        altaProveedor(proveedores,3,ids);
        break;
    case 2:
        //altaProducto(productos,3);
        break;
    case 7:
        seguir = 'n';
        break;
    }



    }



    return 0;
}
