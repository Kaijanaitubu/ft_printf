/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmogami <kmogami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:50:11 by kmogami           #+#    #+#             */
/*   Updated: 2024/05/06 01:09:41 by kmogami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		len;
	char	num[13];

	len = 1;
	while (!(n / power(10, len - 1) < 10 && n / power(10, len - 1) > -10))
		len++;
	i = 0;
	if (n < 0)
		num[i++] = '-';
	while (len-- > 0)
		num[i++] = abs(n / power(10, len) % 10) + '0';
	num[i] = '\0';
	write(fd, num, i);
}
