/* Escriba un programa que imprima, byte a byte, los bytes que constituyen una
variable long. Utilice Uniones para su implementación.
NOTA: Para apreciar mejor el resultado de este programa, se recomienda trabajar con formato hexadecimal */

union byteToByteLong
{
    long dato;
    char data[8];
};

#include <stdio.h>

int main()
{
    union byteToByteLong myUnion;

    printf("Ingrese un entero largo:\n");
    fflush(stdin);
    scanf("%d", &myUnion.dato);

    printf("Datos:\n");
    
    for (int i = 0; i < sizeof(myUnion.dato); i++)
    {
        printf("Byte %d: %x\n", i, myUnion.data[i]);
    }
    
    return 0;
}
