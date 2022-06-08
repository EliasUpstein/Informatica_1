/* Escriba una función que imprima, byte a byte, los bytes que constituyen una
variable long cuya dirección recibe como argumento.
NOTA: Para apreciar mejor el resultado de este programa, se recomienda trabajar con formato hexadecimal */

#include <stdio.h>
#include <stdlib.h>

void bytetobyte(long *var);

int main()
{
    long var = 0;

    printf("Ingrese un entero largo:\n");
    fflush(stdin);
    scanf("%ld", &var);

    bytetobyte(&var);

    system("pause");
    return 0;
}

//Función que imprime en hexadecimal byte a byte el contenido de un long recibido
//Se desplaza en memoria utilizando como referencia un char (variable de un byte)
void bytetobyte(long *var)
{
    char *c =(char *) var;//Creo un puntero a char para "medir" un byte y lo inicializo en la dirección del long
                          //Se castea el puntero para evitar warning's (puntero a char = puntero a long)
    for (int i = 0; i < sizeof(long); i++)  //Para cada byte del long recorrido
        printf("El byte %d contiene: %x\n",(i+1), *(c+i));  
        //Imprime el contenido del "i" byte del long (referenciado y desplazado por char)
}