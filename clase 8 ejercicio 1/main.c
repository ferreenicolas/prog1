#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char nombres[2][20];
    int vec[6];
    int i,k;
    //       fila   columna
    //nombres [1]    [0]
    for(i=0; i < 2; i++)
        {
            printf("ingrese nombre: ");
            fflush(stdin);
            //gets(nombres[i]);
            scanf("%[^\n]", nombres[i]);
            strlwr (nombres[i]);
            for(k=0; k<20;k++)
                {
                    if(nombres[i][k] == ' ')
                        {
                            nombres[i][k+1]= toupper(nombres[i][k+1]);
                        }
                }
            nombres[i][0]= toupper (nombres[i][0]);

        }
        for (i=0; i<2; i++)
            {
                printf("%s\n", nombres[i]);
            }


    return 0;
}
