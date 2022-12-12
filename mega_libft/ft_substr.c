/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario42 <usuario42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:15:43 by destrada          #+#    #+#             */
/*   Updated: 2022/10/03 16:33:56 by usuario42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		substr = (char *)ft_calloc(1, sizeof(char));
		return (substr);
	}
	if (start + len >= ft_strlen(s))
		substr = (char *)ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
	else
		substr = (char *)ft_calloc(len + 1, sizeof(char));
	if (substr == 0)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	return (substr);
}
