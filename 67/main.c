#include <stdio.h>
#include <stdlib.h>
#define ELEM 20
   /*
    Cargar un vector de 20 elementos. Una vez terminada la carga y por medio de un menú de opciones realizar lo siguiente
    : a- Ingresar un número y mostrar en qué posición dentro del vector se encuentra b- Ingresar la posición del vector y mostrar el número que se encuentra en esa posición
     Si la posición es incorrecta o el número no se encuentra se debe mostrar un mensaje de error.
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
            printf("a- Ingrese un numero(0-19) se mostrara en que posicion del vector está ubicado.\n");
            printf("b- Ingrese una posicion del vector y se mostrará el numero que se ubica ahí.\n");
            printf("c- Salir.\n");

            scanf("%c",&opcion);

            switch(opcion)
            {
                case 'a':
                    printf("a- Ingrese un numero(0-19) se mostrara en que posicion del vector está ubicado.\n");
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
