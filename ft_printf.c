/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tubu <tubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:31:55 by tubu              #+#    #+#             */
/*   Updated: 2024/08/23 02:21:21 by tubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	formats(va_list args, const char format)
{
	ssize_t	out_len;

	out_len = 0;
	if (format == 'c')
		out_len += printchar(va_arg(args, int));
	else if (format == 's')
		out_len += printstr(va_arg(args, char *));
	// else if (format == 'p')
	// 	out_len += printptr();
	else if (format == 'd' || format == 'i')
		out_len += printnum(va_arg(args, int), format);
	else if (format == 'u')
		out_len += printnum(va_arg(args, unsigned int), format);
	else if (format == 'x' || format == 'X')
		out_len += printnum(va_arg(args, long long), format);
	else if (format == '%')
		out_len += printchar('%');
	return (out_len);
}

ssize_t	ft_printf(const char *str, ...)
{
	ssize_t		i;
	va_list		args;
	ssize_t		out_len;

	i = 0;
	out_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			out_len += formats(args, str[i + 1]);
			i++;
		}
		else
			out_len += printchar(str[i]);
		i++;
	}
	va_end(args);
	return (out_len);
}
