#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENTOS 5
int main()
{
    int i,j;
    char nombre[ELEMENTOS][50] = {"Juan","Carlos","Ana","Ernesto","Mario"};
    char apellido[ELEMENTOS][50]= {"Gomez","Fernandez","Paz","Perez","Lopez"};
    int edad[ELEMENTOS]={20,30,50,10,21};
    char auxiliar[50];
    int aux;
    for(i=0;i< ELEMENTOS-1;i++)
    {
    for(j=i+1;j<ELEMENTOS;j++)
    {
    if(strcmp(nombre[i],nombre[j])>0)
    {
    strcpy(auxiliar,nombre[i]);
    strcpy(nombre[i],nombre[j]);
    strcpy(nombre[j], auxiliar);

    strcpy(auxiliar,apellido[i]);
    strcpy(apellido[i],apellido[j]);
    strcpy(apellido[j], auxiliar);

    aux=edad[i];
    edad[i]=edad[j];
    edad[j]=aux;

    //para cada dato tengo que repetir las tres lineas para que me mueva el nombre con el apellido y el otro dato que le agregue
    }
    }
}
printf("\n\nLista ordenada por nombres");
for(i=0;i<ELEMENTOS;i++)
{
printf("\nNombre: %s - Apellido: %s - Edad %d",nombre[i],apellido[i],edad[i]);
}
return 0;
}
