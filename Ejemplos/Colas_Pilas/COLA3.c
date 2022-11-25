#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#define	MAX	5
void ingresa(int *,int *,float *);
void lee(int *,int *,float *);
void lista(int *,int *,float *);
void main(void)
	{
		int	co=0,fi=0,el;
		float	da[MAX];
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
							case	1:	ingresa(&co,&fi,da);
												break;
							case	2:	lee(&co,&fi,da);
												break;
							case	3:	lista(&co,&fi,da);
												break;
							case	4:	exit(0);
					}
			}
		while(el!=4);
	}
void ingresa(int *pr,int *ul,float *d)
	{
		char k;
		do
			{
				(*pr)++;
				if(*pr>MAX)
						{
							clrscr();
							printf("\n\nCola llena");
							(*pr)--;
							printf("\nPresione una tecla para continuar");
							getch();
							return;
						}
					else
						{
							printf("\nIngrese el dato : ");
							scanf("%f",&d[*pr-1]);
						}
				printf("\nOtro dato ( S / N )? ");
				k=toupper(getche());
				printf("\n\n");
			}
		while(k=='S');
	}
void lee(int *pr,int *ul,float *d)
	{
		char k;
		do
			{
				if(*pr==*ul)
						{
							clrscr();
							printf("\n\nCola vacia");
							printf("\nPresione una tecla para continuar");
							getch();
							return;
						}
					else
						{
							printf("\nEl dato es : %f",d[*ul]);
							(*ul)++;
						}
				printf("\nOtro dato ( S / N )? ");
				k=toupper(getche());
				printf("\n\n");
			}
		while(k=='S');
	}
void lista(int *pr,int *ul,float *d)
	{
		int i;
		clrscr();
		printf("\n\n");
		if(*ul==*pr)
				{
					clrscr();
					printf("\n\nCola vacia");
					printf("\nPresione una tecla para continuar");
					getch();
					return;
				}
			else
				for(i=*ul;i<*pr;i++)
					printf("%f\t",d[i]);
		printf("\n\nPresione una tecla para continuar");
		getch();
	}
