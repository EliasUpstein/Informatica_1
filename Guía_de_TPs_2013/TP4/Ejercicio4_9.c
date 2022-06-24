/* Escribir una función que dados dos punteros a caracteres y un número "n" entero
recibidos como parámetros, compare lexicográficamente los primeros "n"
caracteres a partir de cada puntero, devolviendo un valor positivo, cero o
negativo, según corresponda. (Función strncmp() de la biblioteca <string.h>).
El prototipo de la función pedida es:
int my_strncmp (const char *s1, const char *s2, int n); */

#include <stdio.h>
#include <string.h>

#define N 20
#define M 20

int my_strncmp(const char *s1, const char *s2, int n);

int main()
{
    char s[N];
    char t[M];
    int n = 0;

    printf("Ingrese la primer secuencia:\n");
    fflush(stdin);
    fgets(s, N, stdin);

    printf("Ingrese la segunda secuencia:\n");
    fflush(stdin);
    fgets(t, M, stdin);

    printf("Ingrese la cantidad de caracteres a comparar:\n");
    fflush(stdin);
    scanf("%d", &n);

    while (n > strlen(t)-1 || n > strlen(s)-1)     //Si se quieren comparar más caracteres que los que se tienen
    {
        printf("Cantidad inválida. Ingrese un valor menor a la cantidad de caracteres\n");
        fflush(stdin);
        scanf("%d", &n);
    }
    
    switch(my_strncmp(t,s,n))
    {
        case 0:
            printf("Las cadenas son iguales\n");
            break;
        case 1:
            printf("La primer cadena es mayor\n");
            break;
        case -1:
            printf("La segunda cadena es mayor\n");
            break;
        default:
            printf("Error\n");
            break;
    }
    return 0;
}

int my_strncmp(const char *s1, const char *s2, int n)
{
    //Compara hasta n
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])       //Si la cadena es distinta
        {
            if (s1[i] > s2[i])    //Si la primera es mayor
                return 1;
            else                //Si la segunda es mayor
                return -1;
        }
    }
    return 0;                       //Si llega a este punto no se cumplieron las excepciones (son iguales)
}
