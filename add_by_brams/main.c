#include "./libft//libft.h"
#include "get_next_line.h"


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	(void)argc;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
//		ft_putnbr(strcmp("1234567890abcde", line));
//		ft_putchar('\n');
//		ft_putnbr(strcmp("fghijklmnopqrst", line));
//		ft_putchar('\n');
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (0);
}
