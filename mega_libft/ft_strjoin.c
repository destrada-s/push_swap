/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:37:48 by destrada          #+#    #+#             */
/*   Updated: 2022/10/20 17:31:39 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	lenjoin;
	size_t	i;
	size_t	j;

	lenjoin = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char *)malloc(lenjoin + 1 * sizeof(char));
	if (!strjoin)
		return (0);
	i = 0;
	while ((i < ft_strlen(s1)) && (s1[i] != '\0'))
	{
			strjoin[i] = s1[i];
			i++;
	}
	j = 0;
	while (s2[j] != '\0' && (i + j) < lenjoin)
	{
	strjoin[i + j] = s2[j];
	j++;
	}
	strjoin[i + j] = '\0';
	return (strjoin);
}

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		lenjoin;

	lenjoin = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char *)ft_calloc(lenjoin + 1, sizeof(char));
	if (!strjoin)
		return (0);
	ft_strlcpy(strjoin, s1, lenjoin + 1);
	ft_strlcat(strjoin, s2, lenjoin + 1);
	return (strjoin);
}
*/