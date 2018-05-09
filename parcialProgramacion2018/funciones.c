#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "input.h"
/** \brief lista un menu
 *
 * \return retorna la opcion seleccionada
 *
 */

int menu()
{
    int opcion;

    system("cls");

    printf("1 - ALTA PRODUCTO.\n");
    printf("2 - MODIFICACION PRODUCTO.\n");
    printf("3 - BAJA PRODUCTO.\n");
    printf("4 - INFORMAR.\n");
    printf("5 - LISTAR.\n");
    printf("6 - SALIR.\n");

    printf("\nElija lo que quiere hacer: ");
    scanf("%d" , &opcion);

    return opcion;
}
/** \brief inicializaliza el vector de productos en 0
 *
 * \param vector de prodcutos
 * \param tamaño del mismo
 * \return void
 *
 */

void inicializarProductos(eProducto prod[] , int tam)
{
    int i;

    for(i=0 ; i < tam ; i++)
    {
        prod[i].estado = 0;
    }
}
int buscarLibre(eProducto prod[] , int tam)
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
/** \brief hardcodea las descripciones y los codigos
 *
 * \param vetor de proveedor
 * \return void
 *
 */

void hardCode(eProveedor proveedores[]){

    proveedores[0].codigoProveedor = 1;
    strcpy(proveedores[0].descripcion, "ARCOR");
    proveedores[0].estado = 1;

    proveedores[1].codigoProveedor = 2;
    strcpy(proveedores[1].descripcion, "NESTLE");
    proveedores[1].estado =1;

    proveedores[2].codigoProveedor = 3;
    strcpy(proveedores[2].descripcion, "SERENISIMA");
    proveedores[2].estado = 1;

    proveedores[3].codigoProveedor = 4;
    strcpy(proveedores[3].descripcion, "SANCOR");
    proveedores[3].estado = 1;

    proveedores[4].codigoProveedor = 5;
    strcpy(proveedores[4].descripcion, "COCACOLA");
    proveedores[4].estado = 1;

}
/** \brief compruebo si existe el codigo en el array de producto
 *
 * \param vector de producto
 * \param tamaño del mismo
 * \param el codigo que tomo para comprobar
 * \return el indice donde se ubica
 *
 */

int buscarProducto(eProducto prod[] , int tam , int codigoProducto)
{
    int i;
    int codigoProductoEstado = -1;

    for(i=0 ; i < tam ; i++)
    {
        if(codigoProducto == prod[i].codigoProducto)
        {
            codigoProductoEstado = i;
            break;
        }
    }
    return codigoProductoEstado;
}
/** \brief alta de productos
 *
 * \param vector de producto
 * \param tamaño del mismo
 * \return void
 *
 */

void alta(eProducto prod[], int tam)
{
    int i;
    int indice;
    int codigoProd;
    eProducto nuevoProducto;




    system("cls");
    printf("Alta producto.\n");

    indice = buscarLibre(prod, tam);

    if(indice == -1)
        {
            printf("\n El sistema está completo.\n");
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
                while(nuevoProducto.importe < 0)
                    {
                        scanf("%d", &nuevoProducto.importe);
                    }

                printf("Cantidad: ");
                scanf("%d", &nuevoProducto.cantidad);
                while(nuevoProducto.cantidad < 0)
                    {
                        scanf("%d", &nuevoProducto.cantidad);
                    }

            prod[indice] = nuevoProducto;

            for(i=0;i<tam;i++)
                {
                if(prod[i].estado == 1)
                    {

                        nuevoProducto.codigoProducto = i+1;
                    }
                }

            printf("El codigo del producto es: %d\n", nuevoProducto.codigoProducto);
            system("pause");

            prod[indice] = nuevoProducto;

            system("cls");

                    printf("Proveedor: \n");

                    do{
                    printf("1-ARCOR.\n2-NESTLE.\n3-SERENISIMA.\n4-SANCOR.\n5-COCACOLA.\n");
                    scanf("%d", &nuevoProducto.idProv);
                    }while(nuevoProducto.idProv > 5);


                    prod[indice] = nuevoProducto;



                    }
}


/** \brief muestra un elemento de la estructura al completo
 *
 * \param toma el valor de producto de la estructura
 * \return void
 *
 */

void mostrarProducto(eProducto prod)
{
    printf("%d\t%s\t%d\t%d\n", prod.codigoProducto, prod.descripcion, prod.importe, prod.cantidad);
}
/** \brief modifica un valor que elija el usuario y lo guarda una vez mas
 *
 * \param array de producto
 * \param tamaño del array de producto
 * \param array de proveedor
 * \param tamaño del mismo
 * \return void
 *
 */

void modificaProducto(eProducto prod[], int tam, eProveedor prov[], int tam2)
{

    eProducto nuevoDatoProd;
    int codigoProd;
    int esta;
    char confirma;
    int salir = 0;
    int i, j;

    system("cls");
    printf("---Modifica Prod---\n\n");

   printf("Ingrese codigo del producto: ");
        scanf("%d", &codigoProd);

        esta = buscarProducto(prod, tam, codigoProd);

        if(esta == -1)
        {
            printf("\nEl codigo del producto %d no se encuentra en el sistema\n\n", codigoProd);

        }
        else{

                mostrarProducto(prod[esta]);

        do{
            printf("\nConfirma modificacion? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            do{
                switch(menuModifica()){
                    case 1:
                        printf("Ingrese la nueva descripcion: ");
                        fflush(stdin);
                        gets(nuevoDatoProd.descripcion);
                        while(strlen(nuevoDatoProd.descripcion)>49)
                {
                    printf("Descripcion muy larga. Reingrese.\n");
                    gets(nuevoDatoProd.descripcion);
                }
                        strcpy(prod[esta].descripcion , nuevoDatoProd.descripcion);
                        break;
                    case 2:
                        printf("Ingrese el nuevo importe: ");
                        scanf("%d" , &nuevoDatoProd.importe);
                        while(nuevoDatoProd.importe < 0)
                    {
                        scanf("%d", &nuevoDatoProd.importe);
                    }
                        prod[esta].importe = nuevoDatoProd.importe;
                        break;
                    case 3:
                        printf("Ingrese la nueva cantidad: ");
                        scanf("%d" , &nuevoDatoProd.cantidad);
                        while(nuevoDatoProd.cantidad < 0)
                    {
                        scanf("%d", &nuevoDatoProd.cantidad);
                    }
                        prod[esta].cantidad = nuevoDatoProd.cantidad;
                        break;
                    case 4:
                          salir = 1;
                    break;
                }

            }while(salir != 1);
            printf("\nSe ha realizado la modificacion\n\n");
        }
        else{
            printf("\nSe ha cancelado la modificacion\n\n");
        }

        }
}
/** \brief lista un submenu para la modificacion
 *
 * \param
 * \return entero que es la opcion que se eligio
 *
 */

int menuModifica()
{
    int opcion;

    system("cls");
    printf("---Modificar Producto---\n\n");
    printf("1-Descripcion\n");
    printf("2-Importe\n");
    printf("3-Cantidad\n");
    printf("4-Proveedor\n");
    printf("5-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
/** \brief realiza una baja logica de un producto
 *
 * \param array de producto
 * \param tamaño del mismo
 * \return void
 *
 */

void bajaProducto(eProducto prod[], int tam)
{
int codigoProd;
int esta;
char confirma;

system("cls");
printf("---Baja Producto---\n\n");

   printf("Ingrese codigo del producto: ");
        scanf("%d", &codigoProd);

        esta = buscarProducto(prod, tam, codigoProd);

        if(esta == -1)
        {
            printf("\nEl codigo %d no se encuentra en el sistema\n\n", codigoProd);

        }
        else{

                mostrarProducto(prod[esta]);

        do{
            printf("\nConfirma baja? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            prod[esta].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else{
            printf("\nSe ha cancelado la baja\n\n");
        }

        }
}
/** \brief informa los datos pedidos en el parcial
 *
 * \param array de producto
 * \param tamaño del mismo
 * \return void
 *
 */

void informar(eProducto prod[], int tam)
{
    int total = 0;
    float promedio;
    int cantidad =0;
    int cantidadMasProm = 0;
    int cantidadMenosProm = 0;
    int cantidadMas10=0;
    int cantidadMenos10=0;
    int i;


    for(i=0;i<tam;i++)
        {
              if(prod[i].estado == 1)
                {
                    total = total + prod[i].importe;
                    cantidad++;
                }
        }
        promedio = total / cantidad;

        for(i=0;i<tam;i++)
        {
              if(prod[i].estado == 1 && prod[i].importe> promedio)
                {
                    cantidadMasProm++;
                }
        }


    printf("A-TOTAL||PROMEDIO IMPORTES||CANTIDAD DE PRODUCTOS QUE NO SUPERAN EL PROMEDIO.\n\n");

    printf("%d\t\t%.2f\t\t%d\n", total, promedio, cantidadMasProm);

    for(i=0;i<tam;i++)
        {
              if(prod[i].estado == 1)
                {
                    total = total + prod[i].importe;
                    cantidad++;
                }
        }
        promedio = total / cantidad;

        for(i=0;i<tam;i++)
        {
              if(prod[i].estado == 1 && prod[i].importe< promedio)
                {
                    cantidadMenosProm++;
                }
        }


    printf("A-TOTAL\tPROMEDIO IMPORTES\tCANTIDAD DE PRODUCTOS QUE NO SUPERAN EL PROMEDIO.\n\n");

    printf("%d\t\t%.2f\t\t%d\n", total, promedio, cantidadMenosProm);

    for(i=0; i < tam; i++)
        {
            if(prod[i].estado == 1 && prod[i].cantidad <= 10)
                {
                    cantidadMenos10++;
                }
            else
                {
                    if(prod[i].estado == 1 &&prod[i].cantidad >10)
                        {
                            cantidadMas10++;
                        }
                }
        }
    printf("CANTIDAD <= 10.\tCANTIDAD > 10.\n");
    printf("%d\t\t%d\t\t\n", cantidadMenos10, cantidadMas10);


}



void listar(eProducto prod[], int tam, eProveedor prov[], int tam2)
{
int i,j;
eProducto aux;

for(i=0; i<tam-1; i++)
    {

      for(j=i+1; j<tam;j++)
        {

            if(prod[i].importe < prod[j].importe)
                {

                    aux = prod[i];
                    prod[i] = prod[j];
                    prod[j]= aux;

                }
                else
                    {
                        if(prod[i].importe == prod[j].importe)
                            {
                            if(strcmp(prod[i].descripcion, prod[j].descripcion )< 0)
                           {
                            aux= prod[j];
                            prod[j]= prod[j];
                            prod[i]= aux;
                           }
                            }

                    }
        }
    }

    for(i=0; i<tam-1; i++)
        {
          for(j=0; j<tam; j++)
                {
                    if(prod[i].estado == 1 && prod[i].idProv == prov[j].codigoProveedor)
                    {
                        printf("Producto:%s\nImporte:%d\nCantidad:%d\nProveedor:%s\n", prod[i].descripcion, prod[i].importe,prod[i].cantidad,prov[j].descripcion);
                    }


                }


        }
}
