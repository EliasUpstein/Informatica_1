/* Definir una estructura de datos que represente una fecha y el conjunto de
funciones de manipulación de una fecha siguiente:
a) crearFecha: función que devuelve una fecha inicializada en alguna fecha
particular,
b) mostrarFecha: función que imprime una fecha que recibe,
c) copiarFecha: función que recibe una fecha y devuelve la misma en otra
variable,
d) sigDia: función que aumenta una fecha en un día,
e) diaAnt: función que disminuye una fecha en un día.*/

#include <stdio.h>

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Fecha crearFecha()
{
    struct Fecha nueva;

    nueva.dia = 1;
    nueva.mes = 1;
    nueva.anio = 2000;

    return nueva;
}

void mostrarFecha(struct Fecha estructura)
{
    printf("%d/%d/%d\n", estructura.dia, estructura.mes, estructura.anio);
}

// Asumo recibe también el puntero a la estructura
struct Fecha copiarFecha(struct Fecha estructura)
{
    struct Fecha nueva;

    nueva.dia = estructura.dia;
    nueva.mes = estructura.mes;
    nueva.anio = estructura.anio;

    return nueva;
}

// Suma validación según mes
void sigDia(struct Fecha *estructura)
{
    // Meses con 31 días
    if (estructura->mes == 1 || estructura->mes == 3 || estructura->mes == 5 || estructura->mes == 7 || estructura->mes == 8 || estructura->mes == 10 || estructura->mes == 12)
    {
        if (estructura->dia < 31)
            estructura->dia++;
        else // Si el día ya es el 31
        {
            estructura->dia = 1;      // Inicia el nuevo mes
            if (estructura->mes < 12) // Valida que el mes no sea Diciembre sino inicia nuevo año
                estructura->mes++;
            else
            {
                estructura->mes = 1;
                estructura->anio++;
            }
        }
    }
    else if (estructura->mes == 4 || estructura->mes == 6 || estructura->mes == 9 || estructura->mes == 11)
    {
        if (estructura->dia < 30)
            estructura->dia++;
        else // Si el día ya es el 30
        {
            estructura->dia = 1; // Inicia el nuevo mes
            estructura->mes++;
        }
    }
    else // Mes 2 (Febrero)
    {
        // Se calcula si el año es bisiesto
        if ((estructura->anio % 400 == 0) || (estructura->anio % 4 == 0 && estructura->anio % 100 != 0))
        {
            if (estructura->dia < 29)
                estructura->dia++;
            else // Si el día ya es el 29
            {
                estructura->dia = 1; // Inicia el nuevo mes
                estructura->mes++;
            }
        }
        else
        {
            if (estructura->dia < 28)
                estructura->dia++;
            else // Si el día ya es el 28
            {
                estructura->dia = 1; // Inicia el nuevo mes
                estructura->mes++;
            }
        }
    }
}

// Suma validación según mes
void diaAnt(struct Fecha *estructura)
{
    // Meses con 31 días
    if (estructura->mes == 1 || estructura->mes == 3 || estructura->mes == 5 || estructura->mes == 7 || estructura->mes == 8 || estructura->mes == 10 || estructura->mes == 12)
    {
        if (estructura->dia > 1)
            estructura->dia--;
        else // Si el día ya es el 1
        {
            if (estructura->mes == 3) // Hay que volver a Febrero
            {
                // Se calcula si el año es bisiesto
                if ((estructura->anio % 400 == 0) || (estructura->anio % 4 == 0 && estructura->anio % 100 != 0))
                {
                    estructura->dia = 29;
                    estructura->mes--;
                }
                else
                {
                    estructura->dia = 28;
                    estructura->mes--;
                }
            }
            else if (estructura->mes == 1) // Hay que volver a Diciembre
            {
                estructura->dia = 31;
                estructura->mes = 12;
                estructura->anio--;
            }
            else        //Cualquier otro caso
            {
                estructura->dia = 30;
                estructura->mes--;
            }
        }
    }
    else if (estructura->mes == 4 || estructura->mes == 6 || estructura->mes == 9 || estructura->mes == 11)
    {
        if (estructura->dia > 1)
            estructura->dia--;
        else // Si el día ya es el 1
        {
            estructura->dia = 31; // Vuelve al mes anterior
            estructura->mes--;
        }
    }
}