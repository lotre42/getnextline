/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 09:57:30 by kahantar          #+#    #+#             */
/*   Updated: 2017/02/18 11:07:40 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"
#include "./LIB/libft.h"

char	*ft_cuprest(char **rest)
{
	int		i;
	int		j;
	char	*str;
	char	*reste;

	reste = ft_strdup(*rest);
	i = 0;
	j = 0;
	while (reste[i] != '\n')
		i++;
	str = (char*)malloc(sizeof(char) * i + 1);
	i = -1;
	while (reste[++i] != '\n')
		str[i] = reste[i];
	while (reste[i] != '\0')
	{
		i++;
		reste[j] = reste[i];
		j++;
	}
	reste[j] = '\0';
	*rest = ft_strdup(reste);
	return (str);
}

char	*ft_cpyline(char *line, int size)
{
	char	*phrase;

	phrase = ft_strnew(size);
	ft_strncpy(phrase, line, size);
	return (phrase);
}

char	*ft_cpybuf(const int fd, int *j)
{
	int		res;
	char	buf[BUF_SIZE + 1];
	int		erreur;
	char	*line;
	int		i;

	erreur = 0;
	i = 0;
	while (erreur == 0 && (res = read(fd, buf, BUF_SIZE)))
	{
		buf[res] = '\0';
		if (i == 0)
			line = ft_strdup(buf);
		else
			line = ft_strjoin(line, buf);
		i = 0;
		while (line[i] != '\0' && erreur == 0)
		{
			if (line[i] == '\n')
				erreur = 1;
			i++;
		}
	}
	*j = i - 1;
	return (line);
}

void	ft_phrase(char **line, int fd, char **rest, int j)
{
	char		*linebuf;
	char		*phrase;

	linebuf = ft_cpybuf(fd, &j);
	phrase = ft_cpyline(linebuf, j);
	if ((*rest))
		phrase = ft_strjoin(*rest, phrase);
	*line = ft_strdup(phrase);
	j++;
	*rest = ft_strsub(linebuf, j, (ft_strlen(linebuf) - j));
}

int		get_next_line(const int fd, char **line)
{
	static char	*rest;
	int			j;

	j = 0;
	if ((rest))
	{
		if (!(ft_strchr(rest, '\n')))
			ft_phrase(line, fd, &rest, j);
		else
			*line = ft_strdup((ft_cuprest(&rest)));
	}
	else
		ft_phrase(line, fd, &rest, j);
	return (1);
}
