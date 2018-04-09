

void ordenar(int vec[], int tam)
{

  int i=0, j,aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(vec[i]>vec[j])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }
}

void mostrarvector(int vec[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
        {
            printf("%d ", vec[i]);
        }
}


