#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char *line;
	int fd;
	int ret;
	int countline;

	countline = 1;
	if (ac == 1)
		fd = 0;
	if (ac >= 2)
		fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line))==1)
    {
		printf("line %d = %s - [%d]\n", countline, line, ret);
    	free(line);
		countline++;
    }
	printf("line %d = %s - [%d]\n", countline, line, ret);
	free(line);

	printf("\nTest de LEAKS\n");
	system("leaks a.out | grep leaked\n"); 
	return 0;
}
