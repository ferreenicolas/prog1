#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "input.h"

int main()
{
    char letra = 's';
    int flag=0;
    int opcionListar;
    eProducto productos[5];
    eProveedor proveedores[5];

    inicializarProductos(productos , 5);
    hardCode(proveedores);

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
                    modificaProducto(productos, 5);

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
                   do

                {
                    switch(opcionListar = subMenuListar())
                    {
                        case 1:
                            listarUno(productos, 5);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            listarDos(productos, 5);
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            listarTres(productos, 5);
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            listarCuatro(productos, 5);
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            listarCinco(productos, 5);
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            listarSeis(productos, 5, proveedores, 5);
                            system("pause");
                            system("cls");
                            break;
                        case 7:
                            listarSiete(productos, 5, proveedores, 5);
                            system("pause");
                            system("cls");
                            break;
                        case 8:
                            listarOcho(productos, 5, proveedores, 5);
                            system("pause");
                            system("cls");
                            break;
                        case 9:
                            listarNueve(productos, 5, proveedores, 5);
                            system("pause");
                            system("cls");
                            break;
                        case 10:
                            listarDiez(productos, 5, proveedores, 5);
                            system("pause");
                            system("cls");
                            break;
                        case 11:
                            listarOnce(productos, 5, proveedores, 5);
                            system("pause");
                            system("cls");
                            break;
                        case 12:
                            listarDoce(productos, 5, proveedores, 5);
                            system("pause");
                            system("cls");
                        case 13:
                            opcionListar = 6;
                            break;
                        default:
                            printf("Ingrese una opcion valida.");
                            break;
                    }
                }
                while(opcionListar != 6);
                break;
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
            menu();
        }
    }
    while(letra == 's');
    return 0;
}
