/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tubu <tubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:22:48 by tubu              #+#    #+#             */
/*   Updated: 2024/08/23 02:41:37 by tubu             ###   ########.fr       */
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

ssize_t	printnum(long long num, int format)
{
	char	*num_str;
	ssize_t	print_len;

	print_len = 0;
	if (format == 'd' || format == 'i')
		num_str = itoa_base((long long)num, BASE10, 0);
	if (format == 'u')
		num_str = itoa_base((long long)num, BASE10, 1);
	if (format == 'x')
		num_str = itoa_base((long long)num, BASE16, 0);
	if (format == 'X')
		num_str = itoa_base((long long)num, BASE16_U, 0);
	print_len += printstr(num_str);
	free(num_str);
	return (print_len);
}

ssize_t	printptr(unsigned long long ptr)
{
	char	*ptr_str;
	ssize_t	print_len;

	print_len = 0;
	print_len += printstr("0x");
	ptr_str = itoa_base((long long)ptr, BASE16, 1);
	print_len += printstr(ptr_str);
	free(ptr_str);
	return (print_len);
}
