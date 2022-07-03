#include <stdio.h>
#include <string.h>
#define N 300

int main(int argc,char *argv[],char *envp[]) 
{
    int i=0;
    char contenido[N];
    char *direccion;

    while(envp[i]!=NULL) {
        printf("%s\n", envp[i]);
        i++;
    }
    for(i=0;envp[i]!=NULL;i++)
    {
        if(strstr(envp[i],"LOGNAME")!=NULL)
        {
            strcpy(contenido,envp[i]);
            direccion = strtok(contenido,"=");
            direccion = strtok(NULL,"=");
        }
    }
    printf("%s\n",direccion);
    return 0;
}