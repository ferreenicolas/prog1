#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;
    printf("Edad: ");
    scanf("%d", &edad);
    while(edad < 0 || edad > 100)
        {
         printf("Edad incorrecta: ");
         scanf("%d", &edad);
        }
    do
        {
        printf("edad");
        scanf("%d"; &edad);
        }
        while(edad < 0 || edad > 100);

    return 0;
}
