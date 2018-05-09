#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "input.h"

int main()
{
    char letra = 's';
    int flag=0;
    eProducto productos[5];
    eProveedor proveedores[5];

    inicializarProductos(productos , 5);

    do
    {
        switch(menu())
        {
        case 1:
            alta(productos,5);
            flag = 1;
            system("pause");
            break;
        case 2:
            if(flag == 1)
                {
                    modificaProducto(productos, 5, proveedores, 5);

                }else
                {
                    printf("Debe ingresar un producto antes.\n");
                }


            system("pause");
            break;
        case 3:
            if(flag ==1)
                {
                    bajaProducto(productos,5);

                }else
                {
                    printf("Debe ingresar un producto antes.\n");
                }

            system("pause");
            break;
        case 4:
            if(flag ==1)
                {
                   informar(productos,5);

                }else
                {
                    printf("Debe ingresar un producto antes.\n");
                }

            system("pause");
            break;
        case 5:
             if(flag ==1)
                {
                   listar(productos, 5, proveedores ,5);
                }else
                {
                    printf("Debe ingresar un producto antes.\n");
                }
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
