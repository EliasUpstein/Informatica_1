#include<stdio.h>
#include<string.h>
struct nodo
{
    char nombre[10];
    int edad;
    struct nodo * psig;
};

int main()
{
    struct nodo n1;                 //creo una variable del tipo struct nodo llamado n1
    struct nodo * pINI=0;           //creo un puntero vacio del tipo struct nodo llamado pINI
    struct nodo * paux=0;           //creo un puntero vacio del tipo struct nodo llamado paux
      //cargo datos en nodo
    strcpy(n1.nombre,"diego");      //nombre="diego" usando strcpy
    n1.edad=111;
    n1.psig=0;                      //cargo n1.psig con NULL
    
    pINI=&n1;                       //guardo la direccion de n1 en pINI o sea el inicio de la lista
    paux=pINI;                      //apunto tambien paux al inicio de la lista
    
    while(paux!=0)                  //mientras no llegue al final imprimimos los campos de la lista en este caso
    {                               //hay solo un registro
        printf("nombre: %s edad: %d \n", (*paux).nombre  , (*paux).edad );
        paux=(*paux).psig;
    }
	return 0; //Faltaba el return en este codigo
}
