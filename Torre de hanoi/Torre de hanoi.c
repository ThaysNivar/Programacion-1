/*
 5x07-Torres_de_Hanoi_parte_2
 24/01/2012

 Escribe un programa (se recomienda que sea recursivo) que d� soluci�n al problema de las torres de Hanoi.
 El enunciado es el siguiente: Se dispone de una torre formada por varios discos de diferentes di�metros denominada torre O (origen),
 donde cada disco es de di�metro inferior a todos los que est�n por debajo. Se dispone de otras dos torres para dejar discos, una denominada torre A (auxiliar) y otra torre D (destino).
 El problema consiste en pasar todos los discos de la torre O a la torre D respetando dos normas muy simples:

 Los discos se pasan de una torre a otra de uno en uno.
 Nunca un disco de mayor di�metro puede estar sobre otro de menor di�metro.
 Se preguntar� al inicio del programa por el tama�o de la torre O (entendiendo que tendr� el n�mero de discos indicados, con alg�n l�mite preestablecido).
 Las torres A y D estar�n inicialmente vac�as.
 Se debe ofrecer la soluci�n que da el programa a este problema paso a paso, mostrando el resultado de una forma gr�fica. El inicio podr�a ser algo as�:



    *
   ***
  *****
 *******
*********
    ===========        ==========        ==========
 O                A                D


 Formula para calcular movimientos m�nimos necesarios:
 m = 2^n -1

 http://www.rodoval.com/heureka/hanoi/
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//Aqu� se incluye la librer�a est�ndar de C que provee funciones para entrada y salida de datos.


void imprime( int *tab, int fil, int col, int ultNum ) /*Esta seccion define la funcion imprime, que se utiliza para imprimir el estado actual de las torres.*/
{
    /*
    Precondici�n:
    *tab    Puntero a una matriz de tipo entero.
    fil        Entero que indica el numero de filas de la matriz.
    col        Entero que indica el numero de columnas de la matriz.
    disc    Par�metro de tipo entero que indica el numero de discos usados.
    ultNum    Entero que indica el numero que esta usando el disco mas grande.
    */

    int f, c;
    int i, esp;

    for( c=col-1; c >= 0; c-- )
    {
        for( f=0; f < fil; f++ )
        {
            esp = ( ultNum - tab[col*f+c] )/2;
// Espacios a la izquierda
            for( i=0; i < esp; i++ )
                printf( " " );
// Imprime los comodines
            for( i=0; i < tab[col*f+c]; i++ )
                printf( "*" );
// Espacios a la derecha
            for( i=0; i < esp; i++ )
                printf( " " );

            printf( "\t" );
        };

        printf( "\n" );
    };

};

void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest )/* define la funci�n mueveDisco, que se utiliza para mover un disco de una torre a otra.*/
{
    /*
    Precondici�n:
    *tab    Puntero a una matriz de tipo entero.
    fil        Entero que indica el numero de filas de la matriz.
    col        Entero que indica el numero de columnas de la matriz.
    disc    Par�metro de tipo entero que indica el numero de discos usados.
    ultNum    Entero que indica el numero que esta usando el disco mas grande.
    filOrig    Entero que indica el numero de fila de la matriz en la cual hay que coger el numero/disco
    filDest    Entero que indica el numero de fila de la matriz en la cual hay que dejar el numero/disco.
    Poscondici�n:
    Se mueve el disco y se llama a la funci�n que imprime el tablero.
    */
    int cO=col-1, cD=col-1;

// Se busca el disco que se encuentre mas arriba y por lo tanto el mas peque�o de la fila de origen.
    while( cO >= 0  &&  tab[col*filOrig+cO] == 0 )
    {
        cO--;
    };
    if( cO < 0 )
        cO = 0;

// Ahora se calcula cual es la posici�n libre mas arriba de la fila de destino
    while( cD >= 0  &&  tab[col*filDest+cD] == 0 )
    {
        cD--;
    };

// Se mueve el disco de la fila de origen a la de destino:
    tab[col*filDest+cD+1] = tab[col*filOrig+cO];
    tab[col*filOrig+cO] = 0;


// Se imprime el tablero:
    imprime( tab, fil, col, ultNum );
};

void delay(int tiempo)
{
  //sleep(tiempo);

    int c, d;
    while(tiempo >= 0)
    {
        for (c = 1; c <= 10000; c++)
            for (d = 1; d <= 10000; d++)
            {}
        tiempo--;
    }
}

void hanoi( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D ) /*define la funcion hanoi, que es la funcion principal que implementa el algoritmo recursivo de las Torres de Hanoi.*/
{
    /*
    Precondici�n:
     *tab    Puntero a una matriz de tipo entero.
     fil        Entero que indica el numero de filas de la matriz.
     col        Entero que indica el numero de columnas de la matriz.
     disc    Par�metro de tipo entero que indica el numero de discos usados.
     ultNum    Entero que indica el numero que esta usando el disco mas grande.
     O,A,D    Tres enteros que indican la fila desde donde se ha de coger el disco y a donde se ha de traspasar. La primera vez que se llama a hanoi tienen los valores de: 0 ,1 y 2 respectivamente.
    Poscondici�n:
     Se llama recursivamente a hanoi hasta resolver el tablero.
    */
    if( disc==1 )
    {
// Se borra la pantalla, se imprime la tabla y se hace una pausa que varia dependiendo del numero de discos:
        system("cls");
      //system("clear");
        mueveDisco( tab, fil, col, ultNum, O, D );
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);
    }
    else
    {
        hanoi( tab, fil, col, disc-1, ultNum, O, D, A );

        system("cls");
        //system("clear");
        mueveDisco( tab, fil, col, ultNum, O, D );
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);
        hanoi( tab, fil, col, disc-1, ultNum, A, O, D );
    };

};

int main()
/*este es el punto de entrada del programa.*/
{
    int fil=3, col, *tablero = NULL;
    int f, c, disc=1, ultNum;
    /*Esta seccion define algunas variables utilizadas en el programa, como el numero de filas, columnas, el numero de discos, y el tama�o del tablero.*/
    printf( "Indique el numero de discos: " );
    scanf( "%i", &col );
    /*solicita al usuario que ingrese el numero de discos que desea utilizar.*/

   tablero = (int *)malloc( sizeof(int)*fil*col );

// Resetea las torres poniendo "los discos" en una de ellas y 0 en el resto.
    for( f=0; f < fil; f++ )
        for( c=col-1; c >= 0; c-- )
            if( f==0 )
            {
                tablero[col*f+c] = disc;
                disc+=2;
            }
            else
                tablero[col*f+c] = 0;
                /*inicia el tablero de las torres con los discos.*/
    ultNum = disc;
    /*establece el numero total de discos en el tablero.*/

// Se imprime el tablero antes de iniciar ning�n movimiento:
    //system("cls");
    system("clear");
    imprime( tablero, fil, col, ultNum );
    delay(6);
    /*Esta seccion limpia la pantalla, imprime el tablero inicial y hace una pausa antes de comenzar a resolver las Torres de Hanoi.*/

// Se llama a hanoi para comenzar "la partida":
    hanoi( tablero, fil, col, col, ultNum, 0, 1, 2 );
    /*Esta seccion llama a la funcion hanoi para resolver el problema de las Torres de Hanoi con los parametros correspondientes.*/
};
