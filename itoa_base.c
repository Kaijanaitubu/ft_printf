/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tubu <tubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:07:11 by tubu              #+#    #+#             */
/*   Updated: 2024/08/23 14:17:33 by tubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	numlen(unsigned long long num, size_t base_len)
{
	size_t	num_len;

	if (num == 0)
		return (1);
	num_len = 0;
	while (num != 0)
	{
		num = num / base_len;
		num_len++;
	}
	return (num_len);
}

char	*str_prep(size_t num_len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (num_len + 1));
	if (!str)
		return (0);
	str[0] = '0';
	str[num_len] = '\0';
	return (str);
}

char	*itoa_base(long long num, char *base, int unsign)
{
	char				*str;
	size_t				base_len;
	size_t				num_len;
	unsigned long long	tmp_num;

	if (unsign)
		tmp_num = (unsigned long long)num;
	else if (num < 0)
		tmp_num = -(unsigned long long)num;
	else
		tmp_num = (unsigned long long)num;
	base_len = ft_strlen(base);
	num_len = numlen(tmp_num, base_len) + (num < 0 && !unsign);
	str = str_prep(num_len);
	while (tmp_num != 0)
	{
		str[num_len - 1] = base[tmp_num % base_len];
		tmp_num = tmp_num / base_len;
		num_len--;
	}
	if (num < 0 && !unsign)
		str[0] = '-';
	return (str);
}

/* #include <limits.h>

int main(void)
{
    char *result;
    char *base10 = "0123456789";
    char *base16 = "0123456789ABCDEF";

    printf("--- Testing with base 10 ---\n");
    result = itoa_base(INT_MAX, base10, 0);
    printf("INT_MAX: %s\n", result);
    free(result);

    result = itoa_base(LLONG_MAX, base10, 0);
    printf("LLONG_MAX: %s\n", result);
    free(result);

    result = itoa_base(-123456789, base10, 0);
    printf("-123456789: %s\n", result);
    free(result);

    printf("--- Testing with base 16 ---\n");
    result = itoa_base(INT_MAX, base16, 0);
    printf("INT_MAX: %s\n", result);
    free(result);

    result = itoa_base(LLONG_MAX, base16, 0);
    printf("LLONG_MAX: %s\n", result);
    free(result);

    result = itoa_base(-123456789, base16, 0);
    printf("-123456789: %s\n", result);
    free(result);

    printf("--- Testing with unsigned conversion ---\n");
    result = itoa_base(INT_MAX, base10, 1);
    printf("Unsigned INT_MAX: %s\n", result);
    free(result);

    result = itoa_base(LLONG_MAX, base10, 1);
    printf("Unsigned LLONG_MAX: %s\n", result);
    free(result);

    result = itoa_base(-1, base10, 1);
    printf("Unsigned -1: %s\n", result);
    free(result);

    return 0;
}
 */