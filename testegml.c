#include <stdio.h>
#include <fcntl.h>
#include "includes/gnl.h"

int main(int ac, char **av)
{
	char *line = NULL;
	int fd;

	fd = open(av[1], O_RDONLY);
	for (int i = 0; i < 6; i++)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (ac);
}