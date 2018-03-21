#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;
    int flag=0;
    do
        {
            if(flag == 0)
                {
                    printf("Edad: ");
                    flag = 1;
                }
                else
                    {
                        printf("Error, reingresar: ");
                    }
                scanf("%d", &edad);
        }
        while (edad < 0 || edad > 100);
    return 0;
}
