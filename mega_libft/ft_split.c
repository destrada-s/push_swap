/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:42:51 by destrada          #+#    #+#             */
/*   Updated: 2022/12/19 20:48:35 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *s, char c)
{
	size_t	i;
	int		cont;

	i = 0;
	cont = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			cont++;
		}	
		i++;
	}
	return (cont);
}

static int	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_free_split(char **split, int j)
{
	while (j >= 0)
	{
		free(split[j]);
		j--;
	}
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	int		wordlen;
	char	**strarray;
	int		i;
	int		j;

	wordcount = ft_wordcount(s, c);
	strarray = (char **)ft_calloc(wordcount + 1, sizeof(char *));
	if (!strarray)
		return (0);
	j = 0;
	i = 0;
	while (j < wordcount)
	{
		while (s[i] == c && s[i])
		i++;
		wordlen = ft_wordlen(&s[i], c);
		strarray[j] = ft_substr(&s[i], 0, wordlen);
		if (!strarray[j])
			return (ft_free_split(strarray, j));
		i = i + wordlen;
		j++;
	}
	return (strarray);
}
