#include <stdio.h>
#include <stdlib.h>
void ordenar(int[],int,int);
void mostrarvector(int[],int);
int main()
{
    int x[]= {34, 14, 23, 12, 7};
    ordenar(x,5,1);
    mostrarvector(x,5);

    return 0;
}
void ordenar(int vec[],int tam,int criterio){
 int aux;
 for(int i=0;i<tam-1;i++)
 {
    for(int j=i+1;j<tam;j++)
    {
        if(vec[i]>vec[j]&& criterio==0)
        {
            aux = vec[i];
            vec[i]=vec[j];
            vec[j]=aux;
        }
        if(vec[i]<vec[j]&& criterio==1)
        {
            aux = vec[i];
            vec[i]=vec[j];
            vec[j]=aux;
        }
    }
 }
}
void mostrarvector(int vec[], int tam){
for(int i=0;i< tam;i++){
    printf("%d ", vec[i]);
}
printf("\n\n");
}
