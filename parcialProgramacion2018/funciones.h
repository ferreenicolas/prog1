#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
   char descripcion[50];
   int codigoProveedor;
   int estado;

}eProveedor;

typedef struct
{
   char descripcion[50];
   int estado;
   int codigoProducto;
   int importe;
   int cantidad;
   int idProv;

}eProducto;

int menu();

void inicializarProductos(eProducto prod[], int tam);

void hardCode(eProveedor proveedores[]);

void alta(eProducto prod[], int tam);

int buscarProducto(eProducto prod[] , int tam , int codigoProducto);

int buscarLibre(eProducto prod[] , int tam);

void mostrarProducto(eProducto prod);

void modificaProducto(eProducto prod[], int tam, eProveedor prov[], int tam2);

int menuModifica();

void bajaProducto(eProducto prod[], int tam);

void informar(eProducto prod[], int tam);

void listar(eProducto prod[], int tam, eProveedor prov[], int tam2);

#endif // FUNCIONES_H_INCLUDED

