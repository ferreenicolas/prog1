#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void inicializarProveedores(eProveedor prov[] , int tam)
{
    int i;

    for(i=0 ; i < tam ; i++)
    {
        prov[i].estado = 0;
    }
}

void inicializarProducto(eProducto prod[] , int tam)
{
    int i;

    for(i=0 ; i < tam ; i++)
    {
        prod[i].estado = 0;
    }
}



int obtenerEspacioLibreProveedor(eProveedor prov[], int tam)
{
    int i;
    int indiceVacio = -1;

    for(i=0 ; i < tam ; i++)
    {
        if(prov[i].estado == 0)
        {
            indiceVacio = i;
            break;
        }
    }

    return indiceVacio;
}

int obtenerEspacioLibreProducto(eProducto prod[], int tam)
{
    int i;
    int indiceVacio = -1;

    for(i=0 ; i < tam ; i++)
    {
        if(prod[i].estado == 0)
        {
            indiceVacio = i;
            break;
        }
    }

    return indiceVacio;
}

void altaProveedor(eProducto prod[], int tam, eId provid)
{
    int i;
    int indice;

    eId nuevoId;
    eProveedor nuevoProveedor;

    printf("--Ingrese un proveedor--\n");

    indice = obtenerEspacioLibreProveedor(prov, tam);

    if(indice == -1)
    {
        printf("\n¡SISTEMA COMPLETO!\n");
        system("pause");
    }
    else
        {

            nuevoProveedor.estado = 1;

            printf("Descripcion: ");
            fflush(stdin);
            gets(nuevoProveedor.descripcion);

            while(strlen(nuevoProveedor.descripcion)>49)
                {
                    printf("Descripcion muy larga. Reingrese.\n");
                    gets(nuevoProveedor.descripcion);
                }

            prov[indice] = nuevoProveedor;

            for(i=0;i<3;i++)
                {
                if(prov[i].estado == 1)
                    {

                        nuevoProveedor.codigoProveedor = i+1;
                    }
                }

            printf("El codigo del proveedor es: %d\n", nuevoProveedor.codigoProveedor);
            system("pause");

            prov[indice] = nuevoProveedor;
            provid[indice].codigoProveedor = nuevoProveedor.codigoProveedor;



            system("cls");
        }



        for(i=0;i<3;i++)
            {

                        printf("%d\n", provid[i].codigoProveedor);
                        system("pause");

            }



}

void altaProducto(eProducto prod[], int tam, eId[], int tam2)
{
    int i;
    int indice;


    eProducto nuevoProducto;

    printf("--Ingrese un producto--\n");

    indice = obtenerEspacioLibreProducto(prod, tam);

    if(indice == -1)
    {
        printf("\n¡SISTEMA COMPLETO!\n");
        system("pause");
    }
    else
        {

            nuevoProducto.estado = 1;

            printf("Descripcion: ");
            fflush(stdin);
            gets(nuevoProducto.descripcion);

            while(strlen(nuevoProducto.descripcion)>49)
                {
                    printf("Descripcion muy larga. Reingrese.\n");
                    gets(nuevoProducto.descripcion);
                }

            printf("Importe: ");
            scanf("%d", &nuevoProducto.importe);

            printf("Cantidad: ");
            scanf("%d", &nuevoProducto.cantidad);

            prod[indice] = nuevoProducto;

            for(i=0;i<3;i++)
                {
                if(prod[i].estado == 1)
                    {

                        nuevoProducto.codigoProducto = i+1;
                    }
                }

            printf("El codigo del producto es: %d\n", nuevoProducto.codigoProducto);
            system("pause");

            printf("Ingrese el codigo del proveedor al que corresponde: ");
            //scanf("%d", )
            prod[indice] = nuevoProducto;

            system("cls");
        }


}
