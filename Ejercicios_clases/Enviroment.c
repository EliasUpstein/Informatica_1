#include <stdio.h>
#include <string.h>
#define N 300

int main(int argc,char *argv[],char *envp[]) 
{
    // int i=0;
    char contenido[N];
    char *direccion;

    // while(envp[i]!=NULL) {
    //     printf("%s\n", envp[i]);
    //     i++;
    // }
    //Imprime todos los strings de enviroment
    // for (int i = 0; envp[i]!=NULL; i++)
    //     printf("%s\n", envp[i]);
    
    for(int i = 0; envp[i] != NULL; i++)
    {
        printf("%s\n", envp[i]);                //Imprime todos los strings de enviroment

        //if(strstr(envp[i],"LOGNAME") != NULL) //Si el string contiene LOGNAME  (Linux)
        if(strstr(envp[i],"USERNAME") != NULL)  //Si el string contiene USERNAME (Windows)
        {
            strcpy(contenido,envp[i]);          //Copia el string en otra variable
            direccion = strtok(contenido,"=");  //Descarta la parte anterior al igual
            direccion = strtok(NULL,"=");       //Guarda la dirección de lo siguiente al resultado
        }
    }
    printf("\nBienvenido: %s\n",direccion);       //Imprime el string obtenido
    return 0;
}