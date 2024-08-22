/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmogami <kmogami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:46:51 by kmogami           #+#    #+#             */
/*   Updated: 2024/04/17 21:08:45 by kmogami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		result *= nb;
		power --;
	}
	return (result);
}

int	abs(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*num;

	len = 1;
	while (!(n / power(10, len - 1) < 10 && n / power(10, len - 1) > -10))
		len++;
	if (n < 0)
		num = (char *)malloc(len + 2);
	else
		num = (char *)malloc(len + 1);
	if (num == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
		num[i++] = '-';
	while (len-- > 0)
		num[i++] = abs(n / power(10, len) % 10) + '0';
	num[i] = '\0';
	return (num);
}
