#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#define	MAX	5
int ingresa(int,int,int **);
int lee(int,int,int **);
void lista(int,int,int **);
void main(void)
	{
		int	co=0,fi=0,el,i,*da[MAX];
		for(i=0;i<MAX;i++)
			da[i]=NULL;
		do
			{
				clrscr();
				printf("1 - Ingresa datos\n");
				printf("2 - Lee datos\n");
				printf("3 - Lista datos\n");
				printf("4 - Salir\n\n");
				printf("Ingrese una opcion ( 1 - 4 ) : ");
				scanf("%d",&el);
				switch(el)
					{
							case	1:	co=ingresa(co,fi,da);
												break;
							case	2:	fi=lee(co,fi,da);
												break;
							case	3:	lista(co,fi,da);
												break;
							case	4:	exit(0);
					}
			}
		while(el!=4);
	}
int ingresa(int pr,int ul,int **d)
	{
		char k;
		do
			{
				pr++;
				if(pr>MAX)
						{
							clrscr();
							printf("\n\nCola llena");
							printf("\n\nPresione una tecla para continuar\n");
							getch();
							return(pr-1);
						}
					else
						{
							d[pr-1]=(int *)malloc(sizeof(int));
							if(d[pr-1]==NULL)
									{
										clrscr();
										printf("\n\nNo hay memoria disponible\n");
										printf("\n\nPresione una tecla para continuar\n");
										getch();
									}
								else
									{
										printf("\n\nIngrese el dato : ");
										scanf("%d",d[pr-1]);
									}
						}
				printf("\nOtro dato ( S / N )? ");
				k=toupper(getche());
			}
		while(k=='S');
		return(pr);
	}
int lee(int pr,int ul,int **d)
	{
		char k;
		do
			{
				if(pr==ul)
						{
							clrscr();
							printf("\n\nCola vacia");
							printf("\n\nPresione una tecla para continuar\n");
							getch();
							return(ul);
						}
					else
						{
							if(d[ul]==NULL)
									{
										printf("No hay dato\n");
										printf("\n\nPresione una tecla para continuar\n");
										getch();
									}
								else
									{
										printf("\n\nEl dato es : %d\n",*d[ul]);
										free(d[ul]);
										ul++;
									}
						}
				printf("\nOtro dato ( S / N )? ");
				k=toupper(getche());
			}
		while(k=='S');
		return(ul);
	}
void lista(int pr,int ul,int **d)
	{
		int i;
		clrscr();
		for(i=ul;(i<pr)&&(i<MAX);i++)
			printf("%d\t\n",*d[i]);
		printf("\nPresione una tecla para continuar");
		getch();
	}