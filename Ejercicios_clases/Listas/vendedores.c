/* Realizar un programa que maneje el ingreso de vendedores, debe poder agregarse un vendedor y luego ventas de ese vendedor.
se debera poder lista las ventas durante el mes, y al final del mes se debe generar un cierre del mes informando,
total de ventas y comisiones a pagar(10%) . */

#include <stdio_ext.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define com 0.1

struct vendedores ingresar(void);
struct vendedores* buscar(struct vendedores **ppio);
struct vendedores* ins_final(struct vendedores **ppio);
void listar(struct vendedores *p);
void carga(struct vendedores *posicion);
 
struct vendedores
{      
    char nombre[30];
    float monto;
    int contador;
    float comision;
    struct vendedores *siguiente;
};

int main(void)
{
    struct vendedores *inicio =NULL;
    struct vendedores *posicion;
    int flag=2;
    do
    {  
        while(flag!=1 && flag!=0)
        {
            printf("\nDesea ingresar alguna venta de algun vendedor? (si=1, no=0): ");
            setbuf(stdin,NULL);
            scanf("%d",&flag);
        }
        
        if(flag)
        {
            posicion = buscar(&inicio);
            if(posicion == NULL)
                carga(ins_final(&inicio));
            else
                carga(posicion);

            flag=2;
        }
        else
            listar(inicio);

    }while(flag);
    
    return 0;
}

struct vendedores* buscar(struct vendedores **ppio)
{
    struct vendedores *p=*ppio;
    char n[30];
    system("clear");

    //Verifico si la lista está vacia. Si está vacía, salgo de la funcion
    if(*ppio==NULL)
    {
        printf("\nLista VACIA");
        printf("\n\nPresione enter p/ seguir");
        __fpurge(stdin);
        getchar();
        return(*ppio);
    }
    __fpurge(stdin);
    setbuf(stdin, NULL);
    fflush(stdin);
    printf("\nIngrese el nombre del vendedor: ");
    fgets(n,30,stdin);

    //Barro la lista hasta encontrar al vendedor
    for (p=*ppio; p != NULL; p=p->siguiente)
    {
        if(strcmp(n,p->nombre) == 0)
            return(p);
    }
    
    return(NULL);
}

struct vendedores* ins_final(struct vendedores **ppio)
{
    struct vendedores *p, *item;

    //Pido memoria dinamica para un vendedor
    if(!(item=(struct vendedores *)malloc(sizeof(struct vendedores))))
        return(NULL);

    //Cargo datos el vendedor
    *item = ingresar();

    //Como el vendedor será el último, lo hago apuntar a NULL
    item->siguiente=NULL;

    //Si la lista esta vacia (es el 1er vendedor que llega)
    if(!*ppio)
    {
        *ppio=item; //Engancho el vendedor
        return(item);
    }

    //A partir del 2do vendedor, barro con p hasta ubicar el último vendedor
    for(p=*ppio; p->siguiente != NULL; p=p->siguiente);

    p->siguiente=item;   //Engancho el vendedor
    return(item);
}

struct vendedores ingresar(void)
{
    struct vendedores datos;
    char aux[100];
    do
    {
        printf("Ingrese nombre (max. 30 caracteres): ");
        __fpurge(stdin);
        fgets(aux,100,stdin);
    }while(strlen(aux)>30);
    strcpy(datos.nombre, aux);
    datos.contador = 0;
    datos.monto = 0;

    return(datos);
}

void carga(struct vendedores *posicion)
{
    float dinero;
    printf("Ingrese el monto de la venta realizada: $");
    setbuf(stdin,NULL);
    scanf("%f", &dinero);
    posicion->contador ++;
    posicion->monto = posicion->monto + dinero;
    posicion->comision = posicion->monto * com;
    posicion->siguiente = NULL;
}

void listar(struct vendedores *p)
{
    system("clear");
    if(!p)
        printf("LISTA VACIA");
    else
    {
        //Barro desde el 1er vendedor hasta el Último
        //El 1er campo de for está vacio porque p ya apunta al 1er vendedor
        for(;p;p=p->siguiente)
        {
            printf("\n\nVendedor:\nNombre: %sCantidad de ventas: %d\nMonto total vendido: $%0.2f\nComision del vendedor: $%0.2f\n",p->nombre,p->contador,p->monto,p->comision);
        }
    }
    printf("\n\nPresione enter p/ seguir");
    __fpurge(stdin);
    getchar();
}