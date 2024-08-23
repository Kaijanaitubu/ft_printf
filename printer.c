/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmogami <kmogami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:22:48 by tubu              #+#    #+#             */
/*   Updated: 2024/08/23 18:22:42 by kmogami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

ssize_t	printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

ssize_t	printstr(char *str)
{
	ssize_t	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
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
		num_str = itoa_base((long long)num, BASE16, 1);
	if (format == 'X')
		num_str = itoa_base((long long)num, BASE16_U, 1);
	print_len += printstr(num_str);
	free(num_str);
	return (print_len);
}

ssize_t	printptr(unsigned long long ptr)
{
	char	*ptr_str;
	ssize_t	print_len;

	if (!ptr)
		return (printstr("(nil)"));
	print_len = 0;
	print_len += printstr("0x");
	ptr_str = itoa_base((long long)ptr, BASE16, 1);
	print_len += printstr(ptr_str);
	free(ptr_str);
	return (print_len);
}
