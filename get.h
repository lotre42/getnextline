/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 10:48:12 by kahantar          #+#    #+#             */
/*   Updated: 2017/02/18 12:01:00 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_H
# define GET_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 10

int		get_next_line(const int fd, char **line);

#endif
