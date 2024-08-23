/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmogami <kmogami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:31:55 by tubu              #+#    #+#             */
/*   Updated: 2024/08/23 18:24:39 by kmogami          ###   ########.fr       */
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
	else if (format == 'p')
		out_len += printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		out_len += printnum(va_arg(args, int), format);
	else if (format == 'x' || format == 'X' || format == 'u')
		out_len += printnum(va_arg(args, unsigned int), format);
	else if (format == '%')
		out_len += printchar('%');
	return (out_len);
}

int	ft_printf(const char *str, ...)
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
	return ((int)out_len);
}

// #include <stdio.h>

// void test_printf()
// {
//     int original_len, custom_len;

//     printf("\n--- Testing \"A\" as %%c ---\n");
//     original_len = printf("Original: [%c]\n", 'A');
//     custom_len = ft_printf("Custom:   [%c]\n", 'A');
//     printf("Lengths: original = %d, custom = 
//%d\n", original_len, custom_len);

//     printf("\n--- Testing \"Hello, World!\" as %%s ---\n");
//     original_len = printf("Original: [%s]\n", "Hello, World!");
//     custom_len = ft_printf("Custom:   [%s]\n", "Hello, World!");
//     printf("Lengths: original = %d, custom = 
//%d\n", original_len, custom_len);

// 	printf("\n--- Testing \"Hello, %%World!\" as %%s ---\n");
//     original_len = printf("Original: [%s]\n", "Hello,% World!");
//     custom_len = ft_printf("Custom:   [%s]\n", "Hello,% World!");
//     printf("Lengths: original = %d, custom = 
//%d\n", original_len, custom_len);

//     printf("\n--- Testing Pointer Address %%p ---\n");
//     int *p = malloc(sizeof(int));
//     original_len = printf("Original: [%p]\n", p);
//     custom_len = ft_printf("Custom:   [%p]\n", p);
//     printf("Lengths: original = %d, custom = 
//%d\n", original_len, custom_len);
//     free(p);

//     printf("\n--- Testing 12345 as %%d and -12345 %%i ---\n");
//     original_len = printf("Original: [%d] [%i]\n", 12345, -12345);
//     custom_len = ft_printf("Custom:   [%d] [%i]\n", 12345, -12345);
//     printf("Lengths: original = %d, custom = 
//%d\n", original_len, custom_len);

//     printf("\n--- Testing 4294967295u as %%u ---\n");
//     original_len = printf("Original: [%u]\n", 4294967295u);
//     custom_len = ft_printf("Custom:   
//[%u]\n", 4294967295u);
//     printf("Lengths: original = %d, custom = 
//%d\n", original_len, custom_len);

//     printf("\n--- Testing 255 as %%x and 255 as %%X ---\n");
//     original_len = printf("Original: [%x] [%X]\n", 255, 255);
//     custom_len = ft_printf("Custom:   
//[%x] [%X]\n", 255, 255);
//     printf("Lengths: original = %d, custom = 
//%d\n", original_len, custom_len);

//     printf("\n--- Testing %%%% ---\n");
//     original_len = printf("Original: [%%]\n");
//     custom_len = ft_printf("Custom:   [%%]\n");
//     printf("Lengths: original = %d, custom = 
//%d\n", original_len, custom_len);
// }

// int main()
// {
//     test_printf();
//     return 0;
// }
