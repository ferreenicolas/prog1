#include <stdio.h>
#include <stdlib.h>

int main()
{
   /*
    int numero;
    printf("Ingrese numero: ");
    scanf("%d", &numero);

    printf("El numero ingresado es %d", numero);
    */
    int numero;
    char letra;

    printf("Ingrese numero: ");
    scanf("%d", &numero);

    printf("Ingrese letra: ");
    fflush((stdin));
    scanf("%c", &letra);

    printf("El numero ingresado es: %d y la letra ingresada fue: %c", numero, letra);



    return 0;
}
