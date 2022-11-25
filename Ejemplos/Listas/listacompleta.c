// Manejo de lista simple
// Todas las operaciones
// Agosto 2010 - rev 2013 - rev. 2 2015 - rev. 3 2022

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

struct nodo
{
    char nombre[21];
    struct nodo *next;
};

void menu(void);                        //Menu de opciones
int ins_final(struct nodo **);          //Inserta nodo al final de la lista
int ins_ppio(struct nodo **);           //Inserta nodo al comienzo de la lista
int borrar(struct nodo **);             //Borra un nodo
void minimo(struct nodo **);            //Busca el menor elemento
void maximo(struct nodo *);             //Busca el mayor elemento
void ordenar(struct nodo **);           //Ordena la lista
void listar(struct nodo *);             //Imprime la lista
void cant_nodos(struct nodo *);         //Cuenta los nodos
void liberar_memoria(struct nodo **);   //Elimina toda la lista y libera memoria
struct nodo ingresar(void);             //Ingreso de datos por teclado

int main(void)
{
    struct nodo *inicio=NULL;
    int opcion;

    do	{
            menu();
            printf("\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 0: liberar_memoria(&inicio); exit(0); break;
                case 1: ins_final(&inicio); break;
                case 2: ins_ppio(&inicio); break;
                case 3: borrar(&inicio); break;
                case 4: cant_nodos(inicio); break;
                case 5: ordenar(&inicio); break;
                case 6: minimo(&inicio); break;
                case 7: maximo(inicio); break;
                case 8: liberar_memoria(&inicio); break;
                case 9: listar(inicio); break;
                default: printf("Seleccion no Valida\nCERRANDO SESION\n");exit(0);//Faltaba un deafult por si el usuario selecciona un  umero menor a 0 o mayor a 9, se romperia el codigo
            }
        }
    while(opcion!=0);

    return 0;
}

int ins_final(struct nodo **ppio)
{
    struct nodo *p, *item;

    //Pido memoria dinamica para un nodo
    if(!(item=(struct nodo *)malloc(sizeof(struct nodo))))
        return(1);

    //Cargo datos al nodo
    *item = ingresar();

    //Como el nodo será el último, lo hago apuntar a NULL
    item->next=NULL;

    //Si la lista esta vacia (es el 1er nodo que llega)
    if(!*ppio)
    {
        *ppio=item; //Engancho el nodo
        return(0);
    }

    //A partir del 2do nodo, barro con p hasta ubicar el último nodo
    for(p=*ppio; p->next; p=p->next);

    p->next=item;   //Engancho el nodo
    return(0);
}

int ins_ppio(struct nodo **ppio)
{
    struct nodo *item;

    //Pido memoria dinamica para un nodo
    if(!(item=(struct nodo *)malloc(sizeof(struct nodo))))
        return(1);

    //Cargo datos al nodo
    *item = ingresar();

    item->next=*ppio; //Como el nodo sera el 1ro, lo engancho a partir del comienzo
    *ppio=item;       //Engancho el  nodo con el nodo siguiente
    return(0);
}

int borrar(struct nodo **ppio)
{
    struct nodo *p, *aux;
    char n[21];
    system("clear");

    //Verifico si la lista está vacia. Si está vacía, salgo de la funcion
    if(*ppio==NULL)
    {
        printf("\nLista VACIA");
        printf("\n\nPresione enter p/ seguir");
        __fpurge(stdin);
        getchar();
        return(0);
    }
    __fpurge(stdin);
    printf("\nIngrese el nombre a borrar\t");
    fgets(n,21,stdin);
    printf("%p",p);
    //Barro la lista hasta encontrar el nodo a borrar.
    for(p=*ppio; strcmp(n,p->nombre) && p->next; p=p->next)
    {printf("%p",p);}
    //Si el nodo a borrar es el primero
    if(p==*ppio)
    {
        *ppio=p->next;     //desengancho el nodo
        free(p);           //libero el nodo desenganchado
        printf("\nElemento %s borrado", n);
        printf("\n\nPresione enter p/ seguir");
        __fpurge(stdin);
        getchar();
        return(0);
    }

    //Si llego al final de la lista y no encontro el nodo a borrar
    if(p->next==NULL && strcmp(n,p->nombre))
    {
        printf("\nEl nombre no esta en la lista");
        printf("\n\nPresione enter p/ seguir");
        __fpurge(stdin);
        getchar();
        return(0);
    }

    //Entonces hay un elemento a borrar (puede ser cualquiera del 2do al ultimo)
    else
    {
        //Nuevo barrido, para ubicar el nodo ANTERIOR al que quiero borrar
        for(aux=*ppio; aux->next!=p; aux=aux->next);
        aux->next=p->next;     //Desengancho el nodo
        free(p);               //Libero el nodo desenganchado
        printf("\nElemento %s borrado", n);
        printf("\n\nPresione enter p/ seguir");
        __fpurge(stdin);
        getchar();
        return(0);
    }
}

void listar(struct nodo *p)
{
    system("clear");
    if(!p)
        printf("LISTA VACIA");
    else
    {

        //Barro desde el 1er nodo hasta el Último
        //El 1er campo de for está vacio porque p ya apunta al 1er nodo
        for(;p;p=p->next)
        {
            printf("%s\n",p->nombre);
        }
    }
    printf("\n\nPresione enter p/ seguir");
    __fpurge(stdin);
    getchar();
}

void cant_nodos(struct nodo *p)
{
    int i;
    system("clear");

    for(i=0;p;i++,p=p->next);

    printf("Cantidad de Elementos: %d", i);
    printf("\n\nPresione enter p/ seguir");
    __fpurge(stdin);
    getchar();
}

void ordenar(struct nodo **ppio)
{
    struct nodo *p, *max, *aux=NULL;

    if(*ppio==NULL)
    {
        printf("\nLista VACIA");
        printf("\n\nPresione enter p/ seguir");
        __fpurge(stdin);
        getchar();
        return;
    }

    p=*ppio;
    while(*ppio)
    {
        max=p;
        while(p)
        {
            if((strcmp(max->nombre, p->nombre))<0)
                max=p;
            p=p->next;
        }

            if(*ppio==max)          //Si el maximo es el 1ro de la l&ista
            {
                *ppio=max->next;    //desenganche del maximo
                max->next=aux;      //inserto maximo al comienzo de aux
                aux=max;
            }

            else
            {                   //Si el maximo no es el 1ro de la lista
                p=*ppio;
                while(p->next!=max) //"Barro" hasta ubicar el max.
                    p=p->next;
                p->next=max->next;	//desenganche del maximo
                max->next=aux;      //inserto maximo al comienzo de aux
                aux=max;
            }
        p=*ppio;
    }
    *ppio=aux;
    printf("\nLista ORDENADA");
    printf("\n\nPresione enter p/ seguir");
    __fpurge(stdin);
    getchar();
}

void minimo(struct nodo **ppio)  //Recibe puntero a puntero a inicio
{
    struct nodo *p, *min;
    if(*ppio==NULL)
    {
        printf("\nLista VACIA");
        printf("\n\nPresione enter p/ seguir");
        __fpurge(stdin);
        getchar();
        return;
    }
    p=*ppio;
    min=p;
    while(p)
    {
        if((strcmp(min->nombre, p->nombre))>0)
            min=p;
        p=p->next;
    }
    printf("\nEl menor es: %s", min->nombre);
    printf("\n\nPresione enter p/ seguir");
    __fpurge(stdin);
    getchar();
}

void maximo(struct nodo *ppio)     //Recibe puntero a inicio
{
    struct nodo *p, *max;
    if(ppio==NULL)
    {
        printf("\nLista VACIA");
        printf("\n\nPresione enter p/ seguir");
        __fpurge(stdin);
        getchar();
        return;
    }
    p=ppio;
    max=p;
    while(p)
    {
        if((strcmp(max->nombre, p->nombre))<0)
            max=p;
        p=p->next;
    }
    printf("\nEl mayor es: %s", max->nombre);
    printf("\n\nPresione enter p/ seguir");
    __fpurge(stdin);
    getchar();
}

void liberar_memoria(struct nodo **ppio)
{
    struct nodo* p;
    for(p=*ppio; p; p=*ppio)
    {
        *ppio=p->next;
        free(p);
    }
}

void menu(void)
{
    system("clear");
    printf("1.- Agregar al final\n");
    printf("2.- Agregar al principio\n");
    printf("3.- Borrar Elementos\n");
    printf("4.- Cantidad de Elementos\n");
    printf("5.- Ordenar\n");
    printf("6.- Buscar Minimo\n");
    printf("7.- Buscar Maximo\n");
    printf("8.- Vaciar lista\n");
    printf("9.- Listar\n");
    printf("0.- Salir\n");
}

struct nodo ingresar(void)
{
    struct nodo datos;
    char aux[100];
    do
    {
        printf("Ingrese nombre: (max. 20 caracteres)\t");
        __fpurge(stdin);
        fgets(aux,100,stdin);
    }while(strlen(aux)>20);
    strcpy(datos.nombre, aux);

    return(datos);
}