/*
 * Imprime un saludo por la salida estándar.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("hola %s\n", argv[1]);
    exit(EXIT_SUCCESS);
}
