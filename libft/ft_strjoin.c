/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmogami <kmogami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:51:05 by kmogami           #+#    #+#             */
/*   Updated: 2024/04/19 13:33:03 by kmogami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	cat = (char *)malloc((len1 + len2 + 1));
	if (!cat)
		return (NULL);
	ft_strlcpy(cat, s1, len1 + 1);
	ft_strlcpy(cat + len1, s2, len2 + 1);
	return (cat);
}
