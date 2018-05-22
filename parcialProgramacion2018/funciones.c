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

    printf("1 - Alta producto.\n");
    printf("2 - Modificacion producto.\n");
    printf("3 - Baja producto.\n");
    printf("4 - Informar.\n");
    printf("5 - Listar.\n");
    printf("6 - Salir.\n");

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

    eProveedor nuevoProveedor;

    nuevoProveedor.codigoProveedor = 1;
    strcpy(nuevoProveedor.descripcion, "Arcor");
    nuevoProveedor.estado = 1;
    proveedores[0] = nuevoProveedor;


    nuevoProveedor.codigoProveedor = 2;
    strcpy(nuevoProveedor.descripcion, "Nestle");
    nuevoProveedor.estado = 1;
    proveedores[1] = nuevoProveedor;

    nuevoProveedor.codigoProveedor = 3;
    strcpy(nuevoProveedor.descripcion, "Serenisima");
    nuevoProveedor.estado = 1;
    proveedores[2] = nuevoProveedor;

    nuevoProveedor.codigoProveedor = 4;
    strcpy(nuevoProveedor.descripcion, "Sancor");
    nuevoProveedor.estado = 1;
    proveedores[3] = nuevoProveedor;

    nuevoProveedor.codigoProveedor = 5;
    strcpy(nuevoProveedor.descripcion, "Coca Cola");
    nuevoProveedor.estado = 1;
    proveedores[4] = nuevoProveedor;

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
                    printf("1-Arcor.\n2-Nestle.\n3-Serenisima.\n4-Sancor.\n5-Cocacola.\n");
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

void modificaProducto(eProducto prod[], int tam)
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
        }else{
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
    printf("4-Salir\n");
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
    float total = 0;
    float promedio;
    float cantidad =0;
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


    printf("A-Total||Promedio importes||Cantidad de productos que no superan el promedio.\n\n");

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


    printf("A-Total\tPromedio importes\tCantidad de productos que no superan el promedio.\n\n");

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
    printf("Cantidad <= 10.\tCantidad > 10.\n");
    printf("%d\t\t%d\t\t\n", cantidadMenos10, cantidadMas10);


}


int subMenuListar()
{
    int opcion;

    printf("1- Listado descripcion y productos ordenados.\n");
    printf("2- Todos los productos que en cantidad son menor o igual a 10.\n");
    printf("3- Todos los productos cantidad mayor a 10.\n");
    printf("4- Todos los productos que superan el promedio de los importes.\n");
    printf("5- Todos los productos que NO superan el promedio de los importes.\n");
    printf("6- Todos los proveedores cuya cantidad de producto es igual o menor a 10.\n");
    printf("7- Todos los productos provistos por cada proveedor.\n");
    printf("8- Todos los productos provistos por un proveedor determinado.\n");
    printf("9- El proveedor que provee mas productos, mostrando los productos.\n");
    printf("10- El proveedor que provee menos productos, mostrando los productos.\n");
    printf("11- El proveedor que provee el producto mas caro, mostrando el producto.\n");
    printf("12- El proveedor que provee el producto mas barato, mostrando el producto.\n");
    printf("13- Salir.\n");

    printf("Elija la accion que desea realizar: ");
    scanf("%d", &opcion);
    system("cls");
    return opcion;

}

void listarUno(eProducto prod[], int tam)
{
int i,j;
eProducto eAux;
printf("Listado descripcion y productos ordenados.\n");
for(i=0; i<tam-1; i++)
    {

      for(j=i+1; j<tam;j++)
        {
            if(prod[i].estado == 1 && prod[j].estado ==1)
                {
                if(prod[i].importe < prod[j].importe)
                {

                    eAux = prod[i];
                    prod[i] = prod[j];
                    prod[j]= eAux;

                }
                else
                    {
                        if(prod[i].importe == prod[j].importe)
                            {
                                if(strcmp(prod[i].descripcion, prod[j].descripcion )> 0)
                                {
                                    eAux= prod[i];
                                    prod[i]= prod[j];
                                    prod[j]= eAux;
                                }
                            }

                    }
                }

        }
    }


    printf("Producto\t\tImporte\n\n");

    for(i=0; i<tam; i++)
        {
            if(prod[i].estado == 1)
            {
                printf("%s\t\t\t%d\n", prod[i].descripcion, prod[i].importe);
            }
        }
        printf("\n\n");
}

void listarDos(eProducto prod[], int tam)
{
    int i;


    printf("Todos los productos que en cantidad son menor o igual a 10.\n\n");
    printf("Producto\t\tCodigo\t\tCantidad\n\n");
    for(i=0; i<tam;i++)
    {
        if(prod[i].estado == 1 && prod[i].cantidad <11)
            {

                printf("%s\t\t\t%d\t\t%d\n\n", prod[i].descripcion, prod[i].codigoProducto, prod[i].cantidad );

            }

    }
    printf("\n\n");
}

void listarTres(eProducto prod[], int tam)
{
    int i;


    printf("Todos los productos que en cantidad son mayor a 10.\n\n");
    printf("Producto\t\tCodigo\t\tCantidad\n\n");
    for(i=0; i<tam;i++)
    {
        if(prod[i].estado == 1 && prod[i].cantidad > 10)
            {

                printf("%s\t\t\t%d\t\t%d\n\n", prod[i].descripcion, prod[i].codigoProducto, prod[i].cantidad);

            }

    }
    printf("\n\n");
}

void listarCuatro(eProducto prod[], int tam)
{
    float cantidad =0;
    float total = 0;
    float promedio;
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
        printf("Todos los productos que superan el promedio de los importes.\n");
        printf("Producto\t\tCodigo\t\tImporte\n\n");
        printf("Promedio:%.2f \n\n", promedio);
        for(i=0;i<tam;i++)
            {
                if(prod[i].estado==1 && prod[i].importe > promedio)
                    {
                        printf("%s\t\t\t%d\t\t%d\n\n", prod[i].descripcion, prod[i].codigoProducto, prod[i].importe);
                    }
            }



}


void listarCinco(eProducto prod[], int tam)
{
    float cantidad =0;
    float total = 0;
    float promedio;
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
        printf("Todos los productos que NO superan el promedio de los importes.\n");
        printf("Producto\t\tCodigo\t\tImporte\n\n");
        printf("Promedio:%.2f \n\n", promedio);
        for(i=0;i<tam;i++)
            {
                if(prod[i].estado==1 && prod[i].importe < promedio)
                    {
                        printf("%s\t\t\t%d\t\t%d\n\n", prod[i].descripcion, prod[i].codigoProducto, prod[i].importe);
                    }

            }



}

void listarSeis(eProducto prod[], int tam, eProveedor prov[], int tam2)
{

    int i;
    int j;



   /*
    for(i=0; i < tam; i++)
        {
             if(prod[i].estado == 1)
            {

                printf("desc:%s\t\t\tcodigoprod: %d\t\tcant%d\t\timpor%d\t\testad%d\t\tidprov%d\n\n", prod[i].descripcion, prod[i].codigoProducto, prod[i].cantidad,prod[i].importe, prod[i].estado, prod[i].idProv);

            }

        }
        system("pause");
            for(i=0; i < tam; i++)
        {
             if(prov[i].estado == 1)
            {

                printf("desc:%s\t\testad%d\t\tidprov%d\n\n", prov[i].descripcion, prov[i].estado, prov[i].codigoProveedor);

            }

        }
         system("pause");
    */

    for(i=0; i <tam; i++)
        {
            if(prod[i].estado == 1 && prod[i].cantidad < 11)
                {
                    for(j=0; j <tam2; j++)
                    {
                        if( prod[i].idProv == prov[j].codigoProveedor)
                        {

                                printf("%s\t\t%s\t\t%d\n\n", prod[i].descripcion, prov[j].descripcion, prod[i].codigoProducto);
                                break;

                        }

                     }


                    }




        }





}



void listarSiete(eProducto prod[], int tam, eProveedor prov[], int tam2)
{
    printf("\nTodos los productos provistos por cada proveedor.\n");

    int i,j;






        for(i=0; i <tam; i++)
        {
            if(prod[i].estado == 1)
                {
                    for(j=0; j <tam2; j++)
                    {
                        if( prod[i].idProv == prov[j].codigoProveedor)
                        {

                                printf("%s\t\t%s\t\t%d\n\n", prov[j].descripcion, prod[i].descripcion, prod[i].codigoProducto);
                                break;

                        }

                     }


                    }




        }
}

void listarOcho(eProducto prod[], int tam, eProveedor prov[], int tam2)
{
    printf("\nTodos los productos provistos por un proveedor determinado.\n");

    int i,j,opcion;



    printf("1- Arcor.\n");
    printf("2- Nestle.\n");
    printf("3- Serenisima.\n");
    printf("4- Sancor.\n");
    printf("5- Coca-Cola.\n");

    printf("Seleccione de que proveedor desea mostrar los productos.\n");
    scanf("%d", &opcion);


        for(i=0; i <tam; i++)
        {
            if(prod[i].estado == 1)
                {
                    for(j=0; j <tam2; j++)
                    {
                        if(opcion == prov[j].codigoProveedor){
                                        if( prod[i].idProv == prov[j].codigoProveedor)
                        {

                                printf("%s\t\t%s\t\t%d\n\n", prov[j].descripcion, prod[i].descripcion, prod[i].codigoProducto);
                                break;

                        }


                        }


                     }


                    }




        }
}


void listarNueve(eProducto prod[], int tam, eProveedor prov[], int tam2)
{
    printf("\nEl proveedor que provee mas productos, mostrando los productos.\n");

    int i,j;
    eProveedor aux;
    int contador1 = 0;
    int contador2 = 0;
    int contador3 = 0;
    int contador4 = 0;
    int contador5 = 0;
    int flag=0;






        for(i=0; i <tam; i++)
        {
            if(prod[i].estado == 1)
                {
                    for(j=0; j <tam2; j++)
                    {
                        if( prod[i].idProv == prov[j].codigoProveedor)
                        {
                            if(prov[j].codigoProveedor == 1){
                                contador1++;
                                break;
                            }else
                            {
                                if(prov[j].codigoProveedor == 2){
                                contador2++;
                                break;
                            }else
                            {
                                if(prov[j].codigoProveedor == 3){
                                contador3++;
                                break;
                            }else
                            {
                                if(prov[j].codigoProveedor == 4){
                                contador4++;
                                break;
                            }else{
                                contador5++;
                                break;
                            }
                            }
                            }
                            }

                        }

                     }


                 }




        }

        if(contador1 > contador2 && contador1 > contador3 && contador1 > contador4 && contador1 > contador5)
        {
            flag=1;

        }else
        {
            if(contador2 > contador3 && contador2 > contador4 && contador2 > contador5)
        {
            flag=2;

        }else
        {
            if(contador3 > contador4 && contador3 > contador5)
        {
            flag=3;

        }else
        {
            if(contador4 > contador5)
        {
            flag=4;

        }else
        {
            flag=5;
        }
        }
        }
        }



        if(flag==1)
        {
            printf("El proveedor con mas productos es: %s\n", prov[0].descripcion);
        }else
        {
            if(flag==2)
            {
            printf("El proveedor con mas productos es: %s\n", prov[1].descripcion);
            }else
            {
                if(flag==3)
                {
                printf("El proveedor con mas productos es: %s\n", prov[2].descripcion);
                }else
                {
                    if(flag==1)
                    {
                    printf("El proveedor con mas productos es: %s\n", prov[3].descripcion);
                    }else
                    {
                        printf("El proveedor con mas productos es: %s\n", prov[4].descripcion);
                    }
                }
            }
        }







        for(i=0; i <tam; i++)
        {
            if(prod[i].estado == 1)
                {
                    for(j=0; j <tam2; j++)
                    {
                        if(prod[i].idProv == prov[j].codigoProveedor)
                        {
                            if(flag==1)
                                {
                                    if(prov[j].codigoProveedor == 1){


                                        printf("%s\t\t%d\n\n",prod[i].descripcion, prod[i].codigoProducto);
                                    }
                                }else
                                {
                                    if(flag==2)
                                {
                                    if(prov[j].codigoProveedor == 2){


                                        printf("%s\t\t%d\n\n",prod[i].descripcion, prod[i].codigoProducto);
                                    }
                                }else
                                {
                                     if(flag==3)
                                {
                                    if(prov[j].codigoProveedor == 3){


                                        printf("%s\t\t%d\n\n",prod[i].descripcion, prod[i].codigoProducto);
                                    }
                                }else
                                {
                                    if(flag==4)
                                {
                                    if(prov[j].codigoProveedor == 4){


                                        printf("%s\t\t%d\n\n",prod[i].descripcion, prod[i].codigoProducto);
                                    }
                                }
                                else
                                    {

                                    if(prov[j].codigoProveedor == 5){


                                        printf("%s\t\t%d\n\n",prod[i].descripcion, prod[i].codigoProducto);
                                    }

                                    }
                                }

                                }

                                }



                        }

                     }
                }
        }


}

void listarDiez(eProducto prod[], int tam, eProveedor prov[], int tam2)
{
    printf("\nEl proveedor que provee menos productos, mostrando los productos.\n");

    int i,j;
    eProveedor aux;
    int contador1 = 0;
    int contador2 = 0;
    int contador3 = 0;
    int contador4 = 0;
    int contador5 = 0;
    int flag=0;






        for(i=0; i <tam; i++)
        {
            if(prod[i].estado == 1)
                {
                    for(j=0; j <tam2; j++)
                    {
                        if( prod[i].idProv == prov[j].codigoProveedor)
                        {
                            if(prov[j].codigoProveedor == 1){
                                contador1++;
                                break;
                            }else
                            {
                                if(prov[j].codigoProveedor == 2){
                                contador2++;
                                break;
                            }else
                            {
                                if(prov[j].codigoProveedor == 3){
                                contador3++;
                                break;
                            }else
                            {
                                if(prov[j].codigoProveedor == 4){
                                contador4++;
                                break;
                            }else{
                                contador5++;
                                break;
                            }
                            }
                            }
                            }

                        }

                     }


                 }




        }

        if(contador1 < contador2 && contador1 < contador3 && contador1 < contador4 && contador1 < contador5)
        {
            flag=1;

        }else
        {
            if(contador2 < contador3 && contador2 < contador4 && contador2 < contador5)
        {
            flag=2;

        }else
        {
            if(contador3 < contador4 && contador3 < contador5)
        {
            flag=3;

        }else
        {
            if(contador4 < contador5)
        {
            flag=4;

        }else
        {
            flag=5;
        }
        }
        }
        }



        if(flag==1)
        {
            printf("El proveedor con menos productos es: %s\n", prov[0].descripcion);
        }else
        {
            if(flag==2)
            {
            printf("El proveedor con menos productos es: %s\n", prov[1].descripcion);
            }else
            {
                if(flag==3)
                {
                printf("El proveedor con menos productos es: %s\n", prov[2].descripcion);
                }else
                {
                    if(flag==1)
                    {
                    printf("El proveedor con menos productos es: %s\n", prov[3].descripcion);
                    }else
                    {
                        printf("El proveedor con menos productos es: %s\n", prov[4].descripcion);
                    }
                }
            }
        }







        for(i=0; i <tam; i++)
        {
            if(prod[i].estado == 1)
                {
                    for(j=0; j <tam2; j++)
                    {
                        if(prod[i].idProv == prov[j].codigoProveedor)
                        {
                            if(flag==1)
                                {
                                    if(prov[j].codigoProveedor == 1){


                                        printf("%s\t\t%d\n\n",prod[i].descripcion, prod[i].codigoProducto);
                                    }
                                }else
                                {
                                    if(flag==2)
                                {
                                    if(prov[j].codigoProveedor == 2){


                                        printf("%s\t\t%d\n\n",prod[i].descripcion, prod[i].codigoProducto);
                                    }
                                }else
                                {
                                     if(flag==3)
                                {
                                    if(prov[j].codigoProveedor == 3){


                                        printf("%s\t\t%d\n\n",prod[i].descripcion, prod[i].codigoProducto);
                                    }
                                }else
                                {
                                    if(flag==4)
                                {
                                    if(prov[j].codigoProveedor == 4){


                                        printf("%s\t\t%d\n\n",prod[i].descripcion, prod[i].codigoProducto);
                                    }
                                }
                                else
                                    {

                                    if(prov[j].codigoProveedor == 5){


                                        printf("%s\t\t%d\n\n",prod[i].descripcion, prod[i].codigoProducto);
                                    }

                                    }
                                }

                                }

                                }



                        }

                     }
                }
        }


}

void listarOnce(eProducto prod[], int tam, eProveedor prov[], int tam2)
{
    int i,j;
    int mayor;
    eProducto auxMay;
    eProveedor auxMayo;


    for(i=0;i <tam; i++)
    {
        for(j=0;j<tam2;j++)
                    {
        if(prod[i].estado == 1)
            {
                if(prod[i].idProv == prov[j].codigoProveedor)
                    {
                        if(i==0)
                {
                    mayor = prod[i].importe;
                    auxMay = prod[i];
                    auxMayo = prov[j];
                }else
                {
                    if(prod[i].importe > mayor)
                            {
                                    mayor = prod[i].importe;
                                    auxMay = prod[i];
                                    auxMayo = prov[j];
                                    break;
                            }

                }

                    }

            }


            }


    }

    printf("\nEl proveedor cuyo producto es el mas caro es: %s\n", auxMayo.descripcion);
    printf("%s\t%d\n", auxMay.descripcion,auxMay.importe);

}


void listarDoce(eProducto prod[], int tam, eProveedor prov[], int tam2)
{
    int i,j;
    int menor;
    eProducto auxMen;
    eProveedor auxMeno;




    for(i=0;i <tam; i++)
    {
        for(j=0;j<tam2;j++)
                    {
        if(prod[i].estado == 1)
            {
                if(prod[i].idProv == prov[j].codigoProveedor)
                    {
                        if(i==0)
                {
                    menor = prod[i].importe;
                }else
                {
                    if(prod[i].importe < menor)
                            {
                                    menor = prod[i].importe;
                                    auxMen = prod[i];
                                    auxMeno = prov[j];
                                    break;
                            }

                }

                    }

            }


            }


    }

    printf("\nEl proveedor cuyo producto es el mas caro es: %s\n", auxMeno.descripcion);
    printf("%s\t%d\n", auxMen.descripcion,auxMen.importe);

}






