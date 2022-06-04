/* Escribir una función que calcule el factorial de un número natural pasado como
parámetro, en forma iterativa. Realizar todas las validaciones que considere
necesarias. */

int fact(int n)
{
    int res = 1;

    for (int i = n; i > 0; i--)
    {   res = res * i;        }

    if (n == 0)
        res = 1;
    
    return res;
}