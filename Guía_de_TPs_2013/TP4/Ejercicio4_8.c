/* Escribir una función que reciba dos punteros a char como argumentos, realice
una comparación lexicográfica de las secuencias de bytes finalizadas en '/0'
apuntadas por cada uno, y retorne valores positivos, cero y negativos, según
corresponda. (Función strcmp () de la biblioteca <string.h>).
El prototipo de la función pedida es:
int my_strcmp (const char *t, const char *s) ; */

#include <stdio.h>
#include <string.h>

#define N 20
#define M 20

int my_strcmp(const char *t, const char *s);

int main()
{
    char s[N];
    char t[M];
    int cmp = 0;

    printf("Ingrese la primer secuencia:\n");
    fflush(stdin);
    fgets(s, N, stdin);

    printf("Ingrese la segunda secuencia:\n");
    fflush(stdin);
    fgets(t, M, stdin);

    // switch(my_strcmp(t,s))
    // {
    //     case 0:
    //         printf("Las cadenas son iguales\n");
    //         break;
    //     case 1:
    //         printf("La primer cadena es mayor\n");
    //         break;
    //     case -1:
    //         printf("La segunda cadena es mayor\n");
    //         break;
    //     default:
    //         printf("Error\n");
    //         break;
    // }

    cmp = my_strcmp(t,s);

    if (cmp == 0)
        printf("Las cadenas son iguales\n");
    else if (cmp > 0)
        printf("La primer cadena es mayor\n");
    else
        printf("La segunda cadena es mayor\n");

    return 0;
}

//versión 2
int my_strcmp(const char *t,const char *s)
{
    int res = 0;
    for (int i = 0; res != 0 && i < strlen(t) && i < strlen(s); i++)
        res = (int) t[i] - s[i];

    return res;
}

// int my_strcmp(const char *t, const char *s)
// {
//     //(Si las cadenas tienen distinto largo se da cuenta abajo: basura != caracter)
//     for (int i = 0; i < strlen(t); i++)
//     {
//         if (t[i] != s[i])       //Si la cadena es distinta
//         {
//             if (t[i] > s[i])    //Si la primera es mayor
//                 return 1;
//             else                //Si la segunda es mayor
//                 return -1;
//         }
//     }
//     return 0;                       //Si llega a este punto no se cumplieron las excepciones (son iguales)
// }
