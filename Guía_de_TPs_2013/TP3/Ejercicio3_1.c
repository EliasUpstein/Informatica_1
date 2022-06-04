/*Escribir una función que reciba dos números reales como argumento y devuelva
su MCD claculado mediante el algoritmo de Euclides.
Nota: En lenguaje moderno, el algoritmo se describe como sigue:
1. Dados dos segmentos AB y CD (con AB>CD), restamos CD de AB tantas veces como sea posible. Si no
hay residuo, entonces CD es la máxima medida común.
2. Si se obtiene un residuo EF, éste es menor que CD y podemos repetir el proceso: restamos EF tantas
veces como sea posible de CD. Si al final no queda un residuo, EF es la medida común. En caso
contrario obtenemos un nuevo residuo GH menor a EF.
3. El proceso se repite hasta que en algún momento no se obtiene residuo. Entonces el último residuo
obtenido es la mayor medida común. */

//Iñaki

int Fmcd(int n1, int n2);

int main () {
	int n1, n2, mcd;
	
	printf("Ingrese ambos números para calcular su MCD: \n");
	scanf("%i%i", &n1, &n2);
	
	mcd = Fmcd (n1,n2);
	printf("El MCD entre ambos números es: %i\n", mcd);
	
	return 0;
}

int Fmcd(int n1,int n2){
	
	float resto, mcd;
	
	resto = n1%n2;
	
	while (resto!=0){
		n1=n2;
		n2=resto;
		resto=n1%n2;
	}
	
	mcd = n2;
	
	return mcd;
}


/*
 algoritmo euclides
n1   n2     =     resto
150  39     3       33
39   33     1        6
33    6     5        3
6     3     2        0
 
 */ 
