
#include "get.h"

void	test(int fd)
{
	int res;
	char	buf[BUF_SIZE + 1];
	size_t i;
	char	*str;

	i = 0;
	while ((res = read(fd, buf, BUF_SIZE)))
		i++;
	ft_putnbr(i);
	ft_strnew(i);
	ft_strncpy(str, buf, i);
}

int		main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	test(fd);
	return (0);
}