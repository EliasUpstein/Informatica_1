/* Escribir un programa que cargue un vector de estructuras de tipo:
struct datos {
long legajo;
char apellido[31];
char nombre[31];
};
El ingreso de datos se hará en base a una función con el siguiente prototipo:
void carga(struct datos *);
Los datos se ingresan en un vector utilizando la función carga. La condición de
fin es legajo = 0. Escriba para esto otra función, que reciba la estructura y
devuelva 1 (uno) si se cumple la condición de fin, o un 0 (cero) en caso
contrario. El prototipo es:
int fin(struct dato)
Una vez generado el vector, se deberá ordenarlo en forma creciente por apellido.
Para ello, debe también utilizar una función para la cual Ud. debe proponer el
prototipo. Finalmente, el vector ordenado debe ser guardado, registro por
registro, en el archivo binario legajos.dbf, en el directorio raíz de una disquetera.
Al utilizar las funciones propuestas, Ud. notará que, al ingresar legajo=0 para
salir del programa, la función carga() lo fuerza a ingresar un apellido y nombre
que luego serán descartados. Sugiera una forma de solucionar esto, sin modificar
el prototipo de la función carga(). */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct datos {
    long legajo;
    char apellido[31];
    char nombre[31];
};

void carga(struct datos *);
int fin(struct datos);

int main(void)
{
    struct datos vec[MAX];
    int i=0;

    do
    {
        carga(vec+i);
        //carga(&vec[i]);
        i++;
    } while (!(fin(vec[i])) && i != MAX);
    
    ordenar(vec, i);
    guardar(vec, i);

    return 0;
}

void carga(struct datos * a)
{

}

int fin(struct datos a)
{

}