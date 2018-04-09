#include <stdio.h>
#include <stdlib.h>


void ordenar(int[], int, int); // tipo de dato q devuelve ordenar (tipo de dato del vector, tipo del dato del tamaño);
void mostrarvector(int vec[], int tam);

int main()
{
    int x[]={34,14,23,12,7};

    ordenar(x,5,1); // llamada (nombre de la variable, tamaño de la variable)

    mostrarvector(x,5);

    return 0;
}

void ordenar(int vec[], int tam, int crit) // ordenarmiento por burbuja.
{

  int i=0, j,aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(crit == 0)
                {
                if(vec[i]>vec[j])
                    {
                        aux=vec[i];
                        vec[i]=vec[j];
                        vec[j]=aux;
                    }
                }
                else
                {
                    if(vec[i]<vec[j])
                    {
                        aux=vec[i];
                        vec[i]=vec[j];
                        vec[j]=aux;
                    }

                }
        }
    }
}

void mostrarvector(int vec[],int tam) //mostrar dato a dato de un vector.
{
    int i;
    for(i=0;i<tam;i++)
        {
            printf("%d ", vec[i]);
        }
}




