#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    for(;;)
    {
        letra=getc(stdin);
        printf("%c",letra);
        if (letra=='s')
        break;
    }
    return 0;
}
