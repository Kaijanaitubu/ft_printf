/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmogami <kmogami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:50:32 by kmogami           #+#    #+#             */
/*   Updated: 2024/05/06 01:35:26 by kmogami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	if (words == 0 && s[i - 1] == c)
		words++;
	return (words);
}

static char	**ft_alloc_split(size_t words)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = NULL;
	return (split);
}

void	*ft_free_all_split_alloc(char **split)
{
	int	i;

	if (split)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
	return (NULL);
}

char	**spliter(const char *s, const char c, char **split)
{
	size_t	start;
	size_t	i;
	size_t	words;

	start = 0;
	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			split[words] = ft_substr(s, start, i - start);
		else
			break ;
		if (!split[words])
			return (ft_free_all_split_alloc(split));
		words++;
	}
	split[words] = NULL;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = ft_alloc_split(words);
	if (!split)
		return (NULL);
	split = spliter(s, c, split);
	if (!split)
		return (NULL);
	return (split);
}
