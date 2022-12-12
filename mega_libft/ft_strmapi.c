/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:38:03 by destrada          #+#    #+#             */
/*   Updated: 2022/10/04 11:55:40 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ftstr;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	ftstr = (char *)ft_calloc(slen + 1, sizeof(char));
	if (!ftstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ftstr[i] = f(i, s[i]);
		i++;
	}
	return (ftstr);
}
