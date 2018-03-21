#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[41];
    char localidad [41];
    printf("nombre: ");
    fflush(stdin);
    scanf("%s", nombre);
        fflush(stdin);
    printf("localidad: ");
        fflush(stdin);
    scanf("%s", localidad);
        fflush(stdin);
    printf("usted se llama %s y vive en %s",nombre, localidad);

    return 0;
}
