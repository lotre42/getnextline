
#include "./LIB/libft.h"
#include "get.h"


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	return (0);
}
