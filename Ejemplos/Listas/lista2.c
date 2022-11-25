#include<stdio.h>
#include<string.h>
struct nodo
{
    char nombre[10];                //creo esqueleto del nodo
    int edad;
    struct nodo * psig;
};

int main()
{
    struct nodo n1;                 //creo un nodo
    struct nodo n2;                 //creo otro nodo
    struct nodo n3;                 //creo otro nodo
    struct nodo * pINI=0;           //la lista esta vacia
    struct nodo * paux=0;           //creo un puntero paux tambien apuntando a NULL 
    
    //cargo datos en nodo 1
    strcpy(n1.nombre,"diego ");      //nombre="diego"
    n1.edad=18;
    n1.psig=0;                      //NULL
    
    //cargo datos en nodo 2
    strcpy(n2.nombre,"manuel");     //nombre="manuel"
    n2.edad=20;
    n2.psig=0;//NULL
    
    //cargo datos en nodo 3
    strcpy(n3.nombre,"jorge ");       //nombre="jorge"
    n3.edad=23;
    n3.psig=0;//NULL
    
    //creo la lista enlazando los nodos
    pINI=&n1;
    n1.psig=&n2;
    n2.psig=&n3;
    
    paux=pINI;                      //apunto paux al inicio de la lista
    
    //recorro la lista y la muestro
    while(paux!=0)
    {
        printf("nombre: %s edad: %d \n", (*paux).nombre  , (*paux).edad );
        paux=(*paux).psig;
    }
    return 0; //Faltaba el return
}
