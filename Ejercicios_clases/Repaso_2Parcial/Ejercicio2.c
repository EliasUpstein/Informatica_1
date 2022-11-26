/* Crear una función que reciba un listado de strings separados por comas y devuelva una estructura con un puntero
a un vector de punteros a string y un entero indicando la cantidad de string (archivos) que tiene el vector.
El vector (creado por esta función) debe contener un puntero a cada string de la cadena. 
Para la realización de esta función puede utilizar strtok(). */

#include <string.h>
#include <stdlib.h>

struct DataFiles
{
    char *archivos[1024];
    int cant;
};

struct DataFiles separacion(char* csv)
{
    struct DataFiles data;
    int count = 0;

    //formato: ARCHIVOS=arch01.txt,arch02.txt,... (del item 1)

    strtok(csv, "=");   //Escribe en el '=' el '0'
    data.archivos[0] = &(csv[strlen(csv)+1]);   //Desplaza el primer puntero hasta la primer letra a 

    //A partir de acá trabajo con el substring recortado (solo los nombres de archivos)
    data.archivos[0] = strtok(data.archivos, ",");

    for (int i = 1; i < 1024; i++)
    {
        data.archivos[i] = strtok(NULL, ",");

        if (data.archivos[i] == NULL)
            break;

        count++;
    }

    data.cant = count+1;        //Suma uno porque no cuenta el del final

    return data;
}
