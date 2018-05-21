#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pNum;
    pNum= (int*) malloc(sizeof(int));

    if(pNum == NULL)
        {
            printf("no hay memoria.\n");
            exit(1);
        }
        printf("ingrese numero: ");
        scanf("%d", pNum);
        //*pNum= 5;
        printf("%d\n", *pNum);

    free(pNum);

    printf("%d\n", *pNum);
    system("pause");

    return 0;
}
