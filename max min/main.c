#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void main(void)
{
    int i;
    int suma = 0;
    int max = 0;
    int min = 0;
    float promedio;
    for(i=0; i<10;i++)
    {
        int aux;
        scanf("%d",&aux);
        suma=suma+aux;
      if(i == 0)
        {
           max = aux;
           min = aux;
        }
        else
            {
            if(aux > max)
                {
                    max = aux;
                }
            else
                {
                    if(aux < min)
                        {
                            min = aux;
                        }
                }
            }
            promedio = (float) suma / 10; // de manera momentanea vuelvo la suma e i como flotantes y lo guardo en la variable float
    }
    printf("la suma es:%d\n",suma);
    printf("El maximo es:%d\n",max);
    printf("El minimo es:%d\n",min);
    printf("El promedio es:%.2f\n",promedio);
}
