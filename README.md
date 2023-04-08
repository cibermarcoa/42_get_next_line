# get_next_line

![License](https://img.shields.io/badge/License-MIT-yellow.svg)
![42](https://img.shields.io/badge/42-get_next_line-blueviolet)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/cibermarcoa/42_get_next_line)
![GitHub repo file count](https://img.shields.io/github/directory-file-count/cibermarcoa/42_get_next_line)
![GitHub last commit](https://img.shields.io/github/last-commit/cibermarcoa/42_get_next_line)

## Description
This repository contains my solution for the Get Next Line project at 42. The goal of this project is to create a function that reads a file descriptor line by line.

The implementation of get_next_line in this repository is designed to be correct, efficient, and to comply with the project requirements and constraints. The function reads from a file descriptor using the read system call, and buffers the input until a newline character is encountered or the end of file is reached. Once a complete line has been read, the function returns it to the calling program, along with a status code indicating whether the end of file has been reached or an error has occurred.

To support the reading of large files, the function dynamically allocates memory for the buffer used to read the file. The buffer is resized as needed to ensure that it can accommodate lines of any length. Additionally, the function avoids memory leaks by freeing any allocated memory before returning from the function.

## Usage
The get_next_line function takes two arguments: the file descriptor from which to read and a pointer to a string that will store the line that has been read.

Here is a `main.c` example of how to use the get_next_line function:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;

	fd = open("file_to_read.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

```

To compile and use the project:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c 
```

Once compiled:
```bash
./a.out file_to_read.txt
```

## Result

- NOT GRADE YET
- Bonus: Yes

## Contributing

If you find a bug or have an idea for a new feature, feel free to open an issue or a pull request on this repository. Contributions are always welcome!

## License

This project is licensed under the MIT License - see the LICENSE file for details.
