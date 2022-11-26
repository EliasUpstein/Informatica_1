/* Crear un programa cliente que tome un nombre de archivo por argumentos del main. EL programa llamará a la 
función initSocketC() que no toma nada (pide la IP y puerto sola) y devuelve un socket ya abierto que se deberá
utilizar para escribir datos. Utilice la función del punto 1 para obtener los nombre de archivos y la función del
punto 3 para enviarlos utilizando el socket creado*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/typer.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

struct DataFiles
{
    char *archivos[1024];
    int cant;
};

int main(int argc, char** argv)
{
    if (argc < 2)
        printf("No se ha especificado el archivo\n");
    else
    {   
        int sockfd;
        char *contenido;
        struct DataFiles data;

        sockfd = initSocketC();
        contenido = load_filenames(argv[1]);
        data = separacion(contenido);
        TransferFilesData(sockfd, data.archivos, data.cant);
        
        close(sockfd);
    }
    return 0;
}