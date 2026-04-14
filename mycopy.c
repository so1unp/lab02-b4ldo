/*
 * Copia un archivo en otro.
 */

#include <stdlib.h>     // exit()
#include <stdio.h>      // printf()
#include <fcntl.h>      // open()
#include <unistd.h>     // close()

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <archivo_origen> <archivo_destino>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_leidos, bytes_escritos;
    int fd_origen, fd_destino;
    char buffer[BUFFER_SIZE];
    char modo = argv[1][0];

    if(modo == 's') {
        fd_origen = open(argv[2], O_RDONLY);
        if(fd_origen == -1) {
            perror("Error al abrir el archivo de origen");
            exit(EXIT_FAILURE);
        }

        fd_destino = open(argv[3], O_WRONLY | O_TRUNC);
        if(fd_destino == -1) {
            perror("Error al abrir el archivo de destino");
            exit(EXIT_FAILURE);
        }

        // Lee del archivo de origen y escribe en el archivo de destino
        while((bytes_leidos = read(fd_origen, buffer, BUFFER_SIZE)) > 0) {
            bytes_escritos = write(fd_destino, buffer, (size_t) bytes_leidos);
            if(bytes_escritos != bytes_leidos) {
                perror("Error al escribir en el archivo de destino");
                exit(EXIT_FAILURE);
            }
        }

        if(bytes_leidos == -1) {
            perror("Error al leer el archivo de origen");
            exit(EXIT_FAILURE);
        }

        close(fd_origen);
        close(fd_destino);

    } else if (modo == 'f') {
        // implementar utilizando funciones de la biblioteca
    }
    // Termina la ejecución del proceso.
    exit(EXIT_SUCCESS);
}
