/* Escribir un programa que permita al usuario generar una lista de automóviles,
los muestre ordenados según el número de dominio, permita modificar
cualquiera de los atributos de un automóvil, ofrezca la posibilidad de agregar un
nuevo automóvil a la lista, de eliminar un automóvil a la lista, permita
determinar cuál es el automóvil de mayor potencia presente en la lista. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Ejercicio7_10.h"

#define N 30

void listarAutos(struct Automovil *lista, int cant);
int eliminarAuto(struct Automovil *lista, int cant, int dominio);
void modificarAuto(struct Automovil *lista, int cant, int dominio);
void mayorPotencia(struct Automovil *lista, int cant);

int main()
{
    int flag = 1;
    int op = 0;
    int cantAutos = 0;
    int aux = 0;
    struct Automovil listaAutos[N];

    while (flag == 1)
    {
        printf("\nSeleccione una opción:\n");
        printf("\t1 - Listar autos\n");
        printf("\t2 - Agregar auto\n");
        printf("\t3 - Modificar auto\n");
        printf("\t4 - Eliminar auto\n");
        printf("\t5 - Auto de mayor potencia\n");
        printf("\t6 - Finalizar ejecución\n");

        fflush(stdin);
        scanf("%d", &op);

        while (op < 1 || op > 6)
        {
            printf("Seleccione una opción válida (1-5):\n");
            fflush(stdin);
            scanf("%d", &op);
        }

        switch (op)
        {
        case 1:
            listarAutos(listaAutos, cantAutos);
            break;
        case 2:
            listaAutos[cantAutos] = crearAuto();
            printf("\nAuto agregado:\n");
            mostrarAuto(listaAutos[cantAutos]);
            cantAutos++;
            break;
        case 3:
            printf("Ingrese el número de dominio del auto a modificar:\n");
            fflush(stdin);
            scanf("%d", &aux);

            modificarAuto(listaAutos, cantAutos, aux);
            break;
        case 4:
            printf("Ingrese el número de dominio del auto a eliminar:\n");
            fflush(stdin);
            scanf("%d", &aux);

            if (eliminarAuto(listaAutos, cantAutos, aux))
            {
                printf("Operación realizada con éxito\n");
                cantAutos--;
            }
            else
                printf("No se encontró el dominio indicado\n");
            break;
        case 5:
            mayorPotencia(listaAutos, cantAutos);
            break;
        case 6:
            flag = 0;
            break;
        default:
            printf("ERROR: Opción inválida\n");
        }
    }

    return 0;
}

/*Crea una nueva lista para ordenar (de menor a mayor) los autos e imprimir esta nueva lista*/
void listarAutos(struct Automovil *lista, int cant)
{
    struct Automovil *listaOrdenada = (struct Automovil*) malloc(cant * sizeof(struct Automovil));
    struct Automovil aux;

    if (listaOrdenada != NULL)
    {
        // Copia la lista
        for (int i = 0; i < cant; i++)
        {
            listaOrdenada[i] = lista[i];
        }
        // Ordena la nueva lista
        for (int i = 0; i < cant; i++)
        {
            for (int j = 0; j < cant - 1; j++)
            {
                if (listaOrdenada[j].numeroDominio > listaOrdenada[j + 1].numeroDominio)
                {
                    aux = listaOrdenada[j];
                    listaOrdenada[j] = listaOrdenada[j + 1];
                    listaOrdenada[j + 1] = aux;
                }
            }
        }
        // Realiza la impresión
        for (int i = 0; i < cant; i++)
        {
            mostrarAuto(listaOrdenada[i]);
            printf("\n");
        }

        free(listaOrdenada); // Libero la memoria
    }
    else
        printf("Error en la impresión\n");
}

int eliminarAuto(struct Automovil *lista, int cant, int dominio)
{
    int flag = 0;

    for (int i = 0; i < cant - flag; i++) // Si lo encuentra => el flag es 1 => recorre hasta el anteúltimo
    {
        if (lista[i].numeroDominio == dominio) // Si lo encuentra sobreescribe desplazando todos los autos
        {
            lista[i] = lista[i + 1];
            flag = 1;
        }
    }

    return flag;
}

void modificarAuto(struct Automovil *lista, int cant, int dominio)
{
    struct Automovil *aux = &lista[0];
    int flag = 0;
    int op = 0;

    //Primero busca el auto a modificar
    for (int i = 0; i < cant && flag == 0; i++)
    {
        if (lista[i].numeroDominio == dominio) 
        {
            aux = &lista[i];
            flag = 1;
        }
    }
    //Si existe lo modifica
    if (flag == 1)
    {
        printf("\nSeleccione el atributo a modificar:\n");
        printf("\t1 - Número Dominio\n");
        printf("\t2 - Número Motor\n");
        printf("\t3 - Marca\n");
        printf("\t4 - Modelo\n");
        printf("\t5 - Tamaño Motor\n");
        printf("\t6 - Color\n");

        fflush(stdin);
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                printf("Ingrese el nuevo número de dominio:\n");
                fflush(stdin);
                scanf("%d", &op);

                if (op < 0)
                    printf("El dominio no puede ser menor que cero\n");
                else
                {
                    aux -> numeroDominio = op;
                    printf("Operación realizada con éxito\n");
                }
                break;
            case 2:
                printf("Ingrese el nuevo número de motor:\n");
                fflush(stdin);
                scanf("%d", &op);

                if (op < 0)
                    printf("El nº de motor no puede ser menor que cero\n");
                else
                {
                    aux -> numeroMotor = op;
                    printf("Operación realizada con éxito\n");
                }
                break;
            case 3:
            {
                char *marca = (char*) calloc(N,sizeof(char));

                if (marca != NULL)
                {
                    printf("Ingrese la nueva marca:\n");
                    fflush(stdin);
                    setbuf(stdin, NULL);
                    fgets(marca, N, stdin);
                    marca[strlen(marca)-1] = '\0';  //Elimina el salto de línea
                    
                    strcpy(aux ->marca, marca);

                    printf("Operación realizada con éxito\n");
                    free(marca);
                }
                else
                    printf("Error modificando el atributo\n");
                
                break;
            }
            case 4:
            {
                char *modelo = (char*) calloc(N,sizeof(char));

                if (modelo != NULL)
                {
                    printf("Ingrese el nueva modelo:\n");
                    fflush(stdin);
                    setbuf(stdin, NULL);
                    fgets(modelo, N, stdin);
                    modelo[strlen(modelo)-1] = '\0';  //Elimina el salto de línea
                    
                    strcpy(aux ->modelo, modelo);

                    printf("Operación realizada con éxito\n");
                    free(modelo);
                }
                else
                    printf("Error modificando el atributo\n");
                
                break;
            }
            case 5:
                printf("Ingrese el nuevo tamaño de motor:\n");
                fflush(stdin);
                scanf("%d", &op);

                if (op < 0)
                    printf("El tamaño de motor no puede ser menor que cero\n");
                else
                {
                    aux -> tamanoMotor = op;
                    printf("Operación realizada con éxito\n");
                }
                break;
            case 6:
            {
                char *color = (char*) calloc(N,sizeof(char));

                if (color != NULL)
                {
                    printf("Ingrese el nuevo color:\n");
                    fflush(stdin);
                    setbuf(stdin, NULL);
                    fgets(color, N, stdin);
                    color[strlen(color)-1] = '\0';  //Elimina el salto de línea
                    
                    strcpy(aux ->color, color);

                    printf("Operación realizada con éxito\n");
                    free(color);
                }
                else
                    printf("Error modificando el atributo\n");
                
                break;
            }
            default:
                printf("Opción inválida\n");
                break;
        }
    }
    else
        printf("No se encontró el auto\n");
}

void mayorPotencia(struct Automovil *lista, int cant)
{
    struct Automovil mayor = lista[0];

    //Busca el auto de mayor potencia
    for (int i = 0; i < cant; i++)
    {
        if (lista[i].tamanoMotor > mayor.tamanoMotor)
            mayor = lista[i];
    }

    mostrarAuto(mayor);
}