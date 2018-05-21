#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main()
{
    int* aux;
    int* vec;
    int i;
    //vec = (int*) malloc(5 * sizeof(int));

    vec = (int*) malloc(TAM * sizeof(int));

    if(vec == NULL){
        printf("no hay memoria\n");
        system("pause");
        exit(1);
    }

    for(i=0;i<TAM;i++){
        printf("Ingrese el numero: ");
        scanf("%d", vec+i);
    }

    printf("\nLos numeros ingresados: ");

    for(i=0;i<TAM;i++){

        printf("%d || ", *(vec+i));
    }


    printf("\n");

    aux = (int*) realloc(vec, (TAM +5) * sizeof(int));

    if(aux== NULL){
        printf("\nNo se consiguio memoria.\n");
        system("pause");
        exit(1);
    }
    else{
            vec= aux;
        for(i=5;i< (TAM +5); i++){
            printf("Ingrese el numero: ");
            scanf("%d", vec+i);

        }

        printf("\nLos numeros ingresados: ");

        for(i=0;i<(TAM+5);i++){

        printf("%d || ", *(vec+i));
    }
    }






    free(vec);

    return 0;
}
