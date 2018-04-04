#include <stdio.h>
#include <stdlib.h>
#define cant 5

int main()
{
    int vector[cant];
    int i;
    for(i=0; i< cant; i++)
        {
        printf("Ingrese: ");
        scanf("%d", &vector[i]);
        }

    for(i=0; i<cant;i++)
        {
        printf("%d\n", vector[i]);
        }
    return 0;
}
