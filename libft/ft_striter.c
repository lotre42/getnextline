/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:10:28 by kahantar          #+#    #+#             */
/*   Updated: 2017/01/17 11:10:30 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int i;

	i = 0;
	if (s != NULL && f != NULL)
		while (s[i] != '\0')
		{
			f(&s[i]);
			i++;
		}
}
