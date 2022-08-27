/* Escriba una función que reciba dos valores enteros (dividendo y divisor) y que
devuelva cociente y resto a través de una estructura */

struct crdivision
{
    int cociente, resto;
};

struct crdivision division (int x, int y)
{
    struct crdivision cociente_resto;

    cociente_resto.cociente = x/y;
    cociente_resto.resto = x % y;

    return(cociente_resto);
}

// #include <stdio.h>

// int main(void)
// {
//     struct crdivision cociente_resto;
//     cociente_resto = division(5,2);
//     printf("Cociente: %d\n", cociente_resto.cociente);
//     printf("Resto: %d\n", cociente_resto.resto);
//     return 0;
// }