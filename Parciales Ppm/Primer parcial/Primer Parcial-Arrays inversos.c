#include <stdio.h>
#include <conio.h>

int main()
{
    int cant, i;
    printf("Introduzca el tama'no del arreglo: ");
    scanf("%i", &cant);
    int ar1[cant], ar2[cant], SumInv[cant];
    printf("\nEscriba los numeros del primer arreglo: ");
    for (i = 0; i < cant; i++)
    {
        scanf("%i", &ar1[i]);
    }
    printf("\nEscriba los numeros del segundo arreglo: ");
    for (i = 0; i < cant; i++)
    {
        scanf("%i", &ar2[i]);
    }
    printf("\n\nLa sumatoria inversa de los dos arrays es: //");
    for (i = 0; i < cant; i++)
    {
        SumInv[i] = ar1[i] + ar2[cant - (i+1)];
        printf("%i, ", SumInv[i]);
    }
    printf("\\");

    return 0;
}

