#include <stdio.h>
#include <stdlib.h>
#define cant 3

int main()
{
    int leg[cant];
    float sueldo[cant];
    int edad[cant];
    int i;
    for(i=0; i< cant; i++)
        {
         leg[i]= i+1;
         printf("Sueldo: ");
         scanf("%f", &sueldo[i]);
         printf("Edad: ");
         scanf("%d", &edad[i]);
        }
    printf("\nLegajo\tSueldo\tEdad");
    for(i=0; i < cant; i++)
        {
        printf("\n%d\t%.2f\t%d", leg[i], sueldo[i], edad[i]);
        }
// \nX\tX\tX;
//guardar en i para q reemplace por el dato del momento;
    return 0;
}
