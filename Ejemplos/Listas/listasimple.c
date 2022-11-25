#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    //Declaracion
    int nro; //trabajamos con numeros enteros
}Item;

typedef struct Elemento
{
    Item dato;
    struct Elemento *siguiente;
}Nodo;

Nodo *crearLista()
{
    Nodo *cabeza=NULL;
    return cabeza;
}

Nodo *crearNodo(Item x)
{
    Nodo *a;
    a=malloc(sizeof(Nodo));
    a->dato=x;
    a->siguiente=NULL;
    return a;
}    
    
void inserInicio(Nodo ** cabeza,Item entrada){
    Nodo *nuevo;
    nuevo =crearNodo(entrada);
    nuevo->siguiente = *cabeza;
    *cabeza=nuevo;
}    

void imprimirLista(Nodo *cabeza){
    Nodo *actual;
    printf("La lista es :\n");
    for(actual=cabeza;actual!=NULL;actual=actual->siguiente)
        printf("%d",actual->dato.nro);
    printf("\n\n");
}

Nodo *buscar(Nodo* cabeza,Item dato_buscado){ 
    Nodo *actual;
    for(actual=cabeza;actual!=NULL;actual=actual->siguiente)
        if(dato_buscado.nro==actual->dato.nro) return actual;
    return NULL;
}

int main()
{
    Nodo *cab = crearLista(); //definimos una lista vacia
    int i;
    Item x;
    for (i=0;i<10;i++)
    { //insertamos elementos a la lista
        x.nro=i;
        inserInicio(&cab,x);
    }
    imprimirLista(cab);

   //Buscaremos el elemento 7
    x.nro=7;
    Nodo *sal=buscar (cab,x);
    if(sal==NULL) printf("No se encontro el dato %d en la lista. \n",x.nro);
    else printf("El dato %d esta en la direccion: %p\n",x.nro,sal);

    //Buscaremos el elemento 11
    x.nro=11;
    sal=buscar (cab,x);
    if(sal==NULL) printf("No se encontro el dato %d en la lista. \n",x.nro);
    else printf("El dato %d esta en la direccion: %p\n",x.nro,sal);
    
    return 0;
}    
