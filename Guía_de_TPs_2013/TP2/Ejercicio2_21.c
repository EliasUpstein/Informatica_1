/* Se tienen un sensor de temperatura, que registran 10 temperaturas distintas
cada uno. Esas temperaturas se ingresan por teclado. Se pide determinar e
informar por pantalla:
a) Temperatura promedio.
b) Máxima temperatura registrada.
c) Mínima temperatura registrada.
d) Cantidad de veces que la temperatura se encontró entre los 20 y los 45 ºC. */

#include <stdio.h>

int main()
{
    float t = 0;
    float tmax = 0;
    float tmin = 0;
    float tpro = 0;
    int cant = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Ingrese temperatura %d\n", i+1);
        fflush(stdin);
        scanf("%f", &t);

        tpro = tpro + t;

        if (i == 0)     //Me aseguro de tomar valores ingresados
        {
            tmin = t;
            tmax = t;
        }
        else if (t > tmax)
            tmax = t;
        else if(t < tmin)
            tmin = t;
        
        if (t >= 20 && t <= 45)
            cant++;
    }
    
    tpro = tpro / 10;

    printf("La temperatura promedio fue de %fºC\n", tpro);
    printf("La máxima temperatura registrada fue de %fºC\n", tmax);
    printf("La mínima temperatura registrada fue de %fºC\n", tmin);
    printf("La temperatura se encontró entre los 20ºC y los 45ºC %d veces\n", cant);

    return 0;
}