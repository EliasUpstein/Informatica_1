/* Realizar funciones que puedan hacer las cuatro operaciones básicas en binario,
hexadecimal y octal. */


/*--------------------------Binario-----------------------*/
int sumaBinaria(int a, int b)
{
    int div;

    //Cálculo de la cantidad de bits para a
    div = a;
    int i;

    for (i = 10; div =! 0; i*10)
    {
        div = div / i;
    }

    //Cálculo de la cantidad de bits para b
    div = b;
    int j;

    for (j = 10; div =! 0; j*10)
    {
        div = div / j;
    }

    //Verificar qué dato es mayor (tiene más bits)
    int aux = (i>j)?(i):(j);

    //Cálculo de la suma
    for (int k = 0; k < aux; k++)
    {
        int carry = 0;
        
                
    }
    

    // i =cant de bits
    
    

    // unidad
    // decena
    // cen

    // return res;
}
int restabinaria(int a,int b)
{

}

int productobinario(int a, int b)
{

}

int divisiobinaria(int a, int b)
{
    
}

