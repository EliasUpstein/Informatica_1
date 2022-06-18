/* Extraer un substring
int substring(char st_salida[], char st_entrada[], int pos, int n)
Ejemplo:
substring(str,"Curso de informatica1", 10, 4);
Imprime "info" (MAL) */

#include <stdio.h>
#define N 20

int substring(char st_salida[], char st_entrada[], int pos, int n);

int main()
{
    char str[N];
    char strinput[N];
    int pos, cant;

    printf("Ingrese cadena:\n");
    fflush(stdin);
    fgets(strinput, N, stdin);

    printf("Ingrese posición del caracter:\n");
    fflush(stdin);
    scanf("%d", &pos);

    printf("Ingrese cantidad de caracteres a copiar:\n");
    fflush(stdin);
    scanf("%d", &cant);

    substring(str,strinput, pos, cant);

    printf("La cadena recortada es:\n");
    fputs(str, stdout);

    return 0;
}

int substring(char st_salida[], char st_entrada[], int pos, int n)
{
    int cont = 0;   //Devuelve la cantidad de caracteres que llegó a copiar
    int i;

    for (i = pos; i <= n; i++)
    {
        //Mientras la posición sea distinta al final del string lo guarda en salida
        if (st_entrada[i] != '\0')
        {
            st_salida[i- pos] = st_entrada[i];
            cont++;
        }
        else    //Si la posición es igual al final del string gruardo el \0
            st_salida[i- pos] = '\0';
    }

    //Si no llego a copiar hasta el final del string agarre el \0
    if (st_salida[i- pos] != '\0')
        st_salida[i- pos + 1] = '\0';
    
    
    // for (int i = 0; i <= n; i++)
    // {
    //     st_salida[i] = st_entrada[i + pos];
    // }

    return cont;
}