/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 09:58:36 by kahantar          #+#    #+#             */
/*   Updated: 2017/01/23 12:07:16 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	(*del)((*alst)->content, (*alst)->content_size);
	(*del)((*alst)->next, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
