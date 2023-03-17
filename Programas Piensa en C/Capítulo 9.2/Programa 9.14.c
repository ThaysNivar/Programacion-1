#include <stdio.h>
#include <ctype.h>

/*Letras minusculas y mayusculas.
El programa, al recibir como dato un archivo formado por cadenas de caracteres,
determian el numero de letras min�sculas y may�sculas que hay en el archivo. */

void minymay(FILE *);      /*Prototipo de funci�n. */
/*Observa que esta funci�n va a recibir un archivo como parametro. */

void main(void)
{
char p;
FILE *ar;
if ((ar = fopen("arc5.txt", "r")) != NULL)
{
    minymay(ar);
    /*Se llama a la funci�n minymay. Se pasa el archivo ar como parametro. */
    fclose(ar);
}
else
    printf("No se puedo abrir el archivo");
}

void minymay(FILE *arc)
/*Esta funci�n cuenta el numero de minusculas y mayusculas que hay en el
archivo arc. */
{
int min = 0, may = 0;
char p;
while (!feof(arc))
{
    p = fgetc(arc);     /*Se utiliza la funcion fgetc() para leer caracteres del archivo. */
    if (islower(p))
        min++;
    else
        if (isupper(p))
            may++;
}
printf("\nNumero de minusculas: %d", min);
printf("\nNumero de mayusculas: %d", may);
}
