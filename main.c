#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s [filename]\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: failed to open file '%s'\n", argv[1]);
		return (1);
	}
    line = get_next_line(fd);
		//printf("%s\n", line);
	close(fd);
	return (0);
}
