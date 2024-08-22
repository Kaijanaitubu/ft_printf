/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tubu <tubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:22:48 by tubu              #+#    #+#             */
/*   Updated: 2024/08/22 21:53:46 by tubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

ssize_t	printstr(char *str)
{
	ssize_t	i;
	ssize_t	out_len;

	i = 0;
	out_len = 0;
	while (str[i])
	{
		out_len += printchar(str[i]);
		i++;
	}
	return (out_len);
}
