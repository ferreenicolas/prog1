#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    printf("menu\n");
    printf("1 ravioles\n");
    printf("2 asado\n");
    printf("3 panchos\n");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
        printf("selecciono ravioles");
        break;
    case 2:
        printf("selecciono asado");
        break;
    case 3:
        printf("selecciono panchos");
        break;
    }
    return 0;
}
