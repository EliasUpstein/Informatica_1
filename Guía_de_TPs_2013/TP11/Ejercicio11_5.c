/* Cuando es necesario enviar muchos parámetros por línea de comandos,
generalmente es más cómodo contenerlos en un archivo de configuración.
Realizar la siguiente función:
int read_parameters( char * filename, char ** );
La función recibe el nombre del archivo que contiene todos los parámetros (uno
por cada línea), y un char ** donde se cargará la dirección inicial del vector de
punteros (“argv”). El valor de retorno será la cantidad de parámetros leídos del
archivo (“argc”).
Al retornar de la función, el uso de esos parámetros (mediante argc y argv)
deberá poderse realizar de la misma forma que al leer los parámetros de línea de
comandos. */

