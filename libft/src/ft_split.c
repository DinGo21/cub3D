/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:32:41 by disantam          #+#    #+#             */
/*   Updated: 2024/01/17 11:52:55 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
		}
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
		}
	}
	return (count);
}

static char	**ft_split_free(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	*ft_split_word(const char *s, char c, int *start)
{	
	int		i;
	int		j;
	char	*word;

	i = *start;
	j = 0;
	while (s[i + j] != '\0' && s[i + j] != c)
	{
		j++;
	}
	word = malloc(sizeof(char) * (j + 1));
	if (!word)
	{
		return (NULL);
	}
	j = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		word[j++] = s[i++];
	}
	word[j] = '\0';
	*start = i;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**split;

	split = malloc(sizeof(char *) * (ft_split_count(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			split[count] = ft_split_word(s, c, &i);
			if (!split[count])
			{
				return (ft_split_free(split, count));
			}
			count++;
		}
	}
	split[count] = NULL;
	return (split);
}
