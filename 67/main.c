#include <stdio.h>
#include <stdlib.h>
#define ELEM 20
   /*
    Cargar un vector de 20 elementos. Una vez terminada la carga y por medio de un men� de opciones realizar lo siguiente
    : a- Ingresar un n�mero y mostrar en qu� posici�n dentro del vector se encuentra b- Ingresar la posici�n del vector y mostrar el n�mero que se encuentra en esa posici�n
     Si la posici�n es incorrecta o el n�mero no se encuentra se debe mostrar un mensaje de error.
   */
int main()
{
    int vec[ELEM] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int i;
    int numeroIng;
    int pos;
    char opcion;
    char seguir = 's';

    while(seguir == 's')
        {
            system("cls");
            printf("a- Ingrese un numero(0-19) se mostrara en que posicion del vector est� ubicado.\n");
            printf("b- Ingrese una posicion del vector y se mostrar� el numero que se ubica ah�.\n");
            printf("c- Salir.\n");

            scanf("%c",&opcion);

            switch(opcion)
            {
                case 'a':
                    printf("a- Ingrese un numero(0-19) se mostrara en que posicion del vector est� ubicado.\n");
                    scanf("%d", &numeroIng);
                    for(i=0; i <ELEM; i++)
                    {
                        if(numeroIng = vec[i])
                            {
                               i= pos;
                               printf("La posicion donde se encuentra el numero %d es: %d\n", numeroIng, pos);
                            }
                            else
                                {
                                    printf("El numero ingresado no se encuentra en el vector.");
                                }
                    }


                case 'b':
                case 'c':
                    printf("c- Salir.\n");
                    seguir = 'n';
                    break;



            }

        }






    return 0;
}
