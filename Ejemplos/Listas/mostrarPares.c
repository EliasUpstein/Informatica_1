#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 101

typedef struct{
    //Declaracion
    int nro; //trabajamos con numeros enteros
}Item;

typedef struct Elemento{
    Item dato;
    struct Elemento *siguiente;
}Nodo;

Nodo *crearLista(){
    Nodo *cabeza=NULL;
    return cabeza;
}

Nodo *crearNodo(Item x){
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
        printf("%d  ",actual->dato.nro);
    printf("\n\n");
}
int contarNroElementosLista(Nodo *cabeza){
    Nodo *actual;
    int cantElementos=0;
    for(actual=cabeza;actual!=NULL;actual=actual->siguiente)
        cantElementos++;
    return cantElementos;
}

void imprimirParesLista(Nodo *cabeza){ 
    Nodo *actual;
    printf("Los elementos pares son:\n");
    for(actual=cabeza;actual!=NULL;actual=actual->siguiente)
        if(actual->dato.nro%2==0) printf("%d ",actual->dato.nro);
    printf("\n\n");
}

int main(){
    Nodo *cab=crearLista(); //definimos una lista vacia
    int i,n,N;
    printf("Ingrese la cantidad de elementos: "); scanf ("%d",&N);
    Item x;
    srand(time(NULL));
    for (i=0;i<N;i++){ //insertamos elementos a la lista
        
        n=rand()%MAX; //MAX es una constante (101)x.nro=i;
        x.nro=n;
        inserInicio(&cab,x);
    }
    printf("Se tienen %d elemtos en la lista.\n",contarNroElementosLista(cab));
    imprimirLista(cab);
    imprimirParesLista(cab);

    return 0;
}
