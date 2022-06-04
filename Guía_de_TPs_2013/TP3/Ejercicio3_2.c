/* Escriba una función que reciba dos argumentos enteros x e y, y devuelva xy. */

int potencia (int x, int y)
{
    int aux = x;

    for (int i = 0; i < y; i++)
    {    aux = aux * x;           }

    return aux;
}