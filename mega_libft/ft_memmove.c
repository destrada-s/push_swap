/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:25:16 by destrada          #+#    #+#             */
/*   Updated: 2022/10/05 12:07:30 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*tempsrc;
	char	*tempdst;

	tempdst = (char *)dst;
	i = 0;
	tempsrc = (char *)src;
	if (src || dst)
	{
		if (tempdst > tempsrc)
		{
			while (len-- > 0)
				tempdst[len] = tempsrc[len];
		}
		else
		{
			while (i < len)
			{
			tempdst[i] = tempsrc[i];
			i++;
			}
		}
	}
	return (dst);
}

/*to be able to overcome overlapping it takes into account
	the memory "values" of src and dst and copies it from 
	left to right//right to left making sure 
	it does not step overitself and copies the values correctly*/
/* condition checks if src, dst or both exists if it does then 
	it does the while if not only it will just return dst(= Null)
	because neither src or dst exist*/
