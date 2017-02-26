
#include "./libft//libft.h"
#include "get_next_line.h"


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		n;

	n = argc;
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
