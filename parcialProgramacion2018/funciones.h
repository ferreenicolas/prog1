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

void inicializarProductos(eProducto [], int );

void hardCode(eProveedor proveedores[]);

void alta(eProducto [], int );

int buscarProducto(eProducto [] , int  , int );

int buscarLibre(eProducto [] , int );

void mostrarProducto(eProducto );

void modificaProducto(eProducto [], int );

int menuModifica();

void bajaProducto(eProducto [], int );

void informar(eProducto [], int );

int subMenuListar();

void listarUno(eProducto [], int );

void listarDos(eProducto [], int );

void listarTres(eProducto [], int );

void listarCuatro(eProducto [], int );

void listarCinco(eProducto [], int );

void listarSeis(eProducto [], int , eProveedor [], int );

void listarSiete(eProducto [], int , eProveedor [], int );

void listarOcho(eProducto [], int , eProveedor [], int );

void listarNueve(eProducto [], int , eProveedor [], int);

void listarDiez(eProducto [], int , eProveedor [], int);

void listarOnce(eProducto [], int , eProveedor [], int);

void listarDoce(eProducto [], int , eProveedor [], int);



#endif // FUNCIONES_H_INCLUDED

