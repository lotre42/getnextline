/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:17:01 by kahantar          #+#    #+#             */
/*   Updated: 2017/01/23 19:18:26 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	x;
	size_t	i;

	i = 0;
	x = 0;
	str = NULL;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if (start + len > i)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (x < len && s[start] != '\0')
	{
		str[x] = s[start];
		start++;
		x++;
	}
	str[x] = '\0';
	return (str);
}
