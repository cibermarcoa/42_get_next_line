#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 256

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t read_value;
    printf("%s\n", buffer);
    read_value = read(fd, buffer, BUFFER_SIZE);
    printf("%ld\n", read_value);
    printf("%s\n", buffer);
    read_value = read(fd, buffer, BUFFER_SIZE);
    printf("%ld\n", read_value);
    printf("%s\n", buffer);
    read_value = read(fd, buffer, BUFFER_SIZE);
    printf("%ld\n", read_value);

    if (read_value == -1) {
        perror("read");
        return 1;
    }

    close(fd);

    return 0;
}