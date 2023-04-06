#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    char *line;

    fd = open("42_with_nl.txt", O_RDONLY); // Abrir el archivo de texto en modo lectura
    if (fd < 0)
        return 0;
    while ((line = get_next_line(fd)) != NULL) // Leer el archivo línea por línea
    {
        printf("%s", line); // Imprimir cada línea leída
        free(line); // Liberar la memoria asignada a cada línea leída
    }
    close(fd); // Cerrar el archivo de texto
    return 0;
}