/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tubu <tubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:36:12 by tubu              #+#    #+#             */
/*   Updated: 2024/08/23 02:05:31 by tubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BASE16_U "0123456789ABCDEF"

ssize_t	ft_printf(const char *str, ...);
ssize_t	formats(va_list args, const char format);
ssize_t	printchar(int c);
ssize_t	printstr(char *str);
char	*itoa_base(long long num, char *base, int unsign);
size_t	numlen(unsigned long long num, size_t base_len);
size_t	ft_strlen(const char *s);

#endif
