/* Definir un tipo de dato basado en estructuras que permita almacenar la
información de una tarjeta de crédito:
Nº de tarjeta, nombre del titular, fecha de expiración.*/

#define N 30

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct tarjeta
{
    int numero;
    char nombre[N];
    struct Fecha fecha;
};
