/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:36:55 by kahantar          #+#    #+#             */
/*   Updated: 2017/02/24 21:38:31 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"

char	*ft_strleeks(char **phrase, char **s)
{
	char	*str;

	str = ft_strjoin(*phrase, *s);
	ft_strdel(s);
	ft_strdel(phrase);
	return (str);
}

char	*ft_cuprest(char *phrase)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (phrase[i] != '\n')
		i++;
	str = (char*)malloc(sizeof(char) * ft_strlen(phrase));
	while (phrase[i] != '\0')
	{
		i++;
		str[j] = phrase[i];
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_cupphrase(char *phrase)
{
	int		i;
	char	*str;

	i = 0;
	while (phrase[i] != '\n')
		i++;
	str = (char*)malloc(sizeof(char) * i + 1);
	i = -1;
	while (phrase[++i] != '\n')
		str[i] = phrase[i];
	str[i] = '\0';
	return (str);
}

char	*ft_cpybuf(char *buf1, int fd, int *res)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*phrase;
	char	*s;

	s = NULL;
	phrase = ft_strdup(buf1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		s = ft_strnew(ret);
		ft_strncpy(s, buf, ret);
		phrase = ft_strleeks(&phrase, &s);
		if ((ft_strchr(phrase, '\n')))
			break ;
	}
	*res = ret;
	return (phrase);
}

int		get_next_line(const int fd, char **line)
{
	int			res;
	char		buf[BUFF_SIZE + 1];
	static char	*rest;
	char		*phrase;
	char		*t;

	t = NULL;
	if (BUFF_SIZE < 0)
		return (-1);
	res = read(fd, buf, BUFF_SIZE);
	if (res == -1 || fd == -1)
		return (-1);
	if (res == 0 && (rest == NULL || !ft_strlen(rest)))
		return (0);
	buf[res] = '\0';
	phrase = ft_cpybuf(buf, fd, &res);
	if ((rest))
	{
		if ((phrase))
			phrase = ft_strleeks(&rest, &phrase);
		else
			phrase = ft_strdup(rest);
	}
	t = ft_strdup(phrase);
	if ((ft_strchr(phrase, '\n')))
	{
		rest = ft_cuprest(phrase);
		phrase = ft_cupphrase(t);
	}
	else
		rest = NULL;
	*line = ft_strdup(phrase);
	ft_strdel(&phrase);
	ft_strdel(&t);
	return (1);
}
