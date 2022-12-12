/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario42 <usuario42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:21:16 by destrada          #+#    #+#             */
/*   Updated: 2022/10/03 16:33:24 by usuario42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	strlen;

	strlen = ft_strlen(s1) + 1;
	str = ft_calloc(strlen, sizeof(char));
	if (str == 0)
		return (NULL);
	ft_strlcpy(str, s1, strlen);
	return (str);
}
/* REMEMBER TO PROTECT YOUR MALLOCS */