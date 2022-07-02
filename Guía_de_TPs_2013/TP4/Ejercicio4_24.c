/* Escribir una función que permita validar fechas recibidas como parámetro desde
el programa invocante, mediante un puntero a caracter. Se consideran fechas
aquellas comprendidas entre 01/01/1900 y 31/12/2100. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 11

int validarFecha(const char *fecha);

int main()
{
    char fecha[N];

    printf("Ingrese una fecha en formato dd/mm/aaaa:\n");
    fflush(stdin);
    fgets(fecha, N, stdin);

    if(validarFecha(fecha) == 1)
        printf("Fecha válida\n");
    else
        printf("Fecha inválida\n");

    return 0;
}

//Tercer intento (memoria dinámica)
int validarFecha(const char *fecha)
{
    char *fecha_cortada = (char*) calloc(N, sizeof(char));
    char barra[2] = "/";
    int aux = 1;

    if (fecha_cortada != NULL)
    {
        strcpy(fecha_cortada, fecha);

        //Día
        fecha_cortada = strtok(fecha_cortada, barra);
        if (atoi(fecha_cortada) < 1 || atoi(fecha_cortada) > 31)
            aux = 0;

        //Mes
        fecha_cortada = strtok(NULL, barra);
        if (atoi(fecha_cortada) < 1 || atoi(fecha_cortada) > 12)
            aux = 0;

        //Año
        fecha_cortada = strtok(NULL, barra);
        if (atoi(fecha_cortada) < 1900 || atoi(fecha_cortada) > 2100)
            aux = 0;

        free(fecha_cortada);
    }
    return aux;
}

/*Segundo intento (vector)
int validarFecha(const char *fecha)
{
    char *fecha_cortada;
    char barra[2] = "/";

    strcpy(fecha_cortada, fecha);

    //Día
    fecha_cortada = strtok(fecha_cortada, barra);
    if (atoi(fecha_cortada) < 1 || atoi(fecha_cortada) > 31)
        return 0;

    //Mes
    fecha_cortada = strtok(NULL, barra);
    if (atoi(fecha_cortada) < 1 || atoi(fecha_cortada) > 12)
        return 0;

    //Año
    fecha_cortada = strtok(NULL, barra);
    if (atoi(fecha_cortada) < 1900 || atoi(fecha_cortada) > 2100)
        return 0;

    return 1;
} */


/*Primer intento (Agrega un puntero más)
int validarFecha(const char *fecha)
{
    char fecha_cortada[N];
    char barra[2] = "/";
    char *token;

    strcpy(fecha_cortada, fecha);

    //Día
    token = strtok(fecha_cortada, barra);
    if (atoi(token) < 0 || atoi(token) > 31)
        return 0;

    //Mes
    token = strtok(NULL, barra);
    if (atoi(token) < 0 || atoi(token) > 12)
        return 0;

    //Año
    token = strtok(NULL, barra);
    if (atoi(token) < 1900 || atoi(token) > 2100)
        return 0;

    return 1;
} */