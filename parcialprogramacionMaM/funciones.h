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

}eProducto;

typedef struct
{
   int estado;
   int codigoProducto;
   int codigoProveedor;

}eId;

void inicializarProveedores(eProveedor prov[] , int tam);

void inicializarProducto(eProducto prod[] , int tam);

int obtenerEspacioLibreProveedor(eProveedor prov[], int tam);

int obtenerEspacioLibreProducto(eProducto prod[], int tam);

void altaProveedor(eProveedor prov[], int tam, eId provid);

void altaProducto(eProducto prod[], int tam, eId id);





#endif // FUNCIONES_H_INCLUDED
