/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_len_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:41:32 by destrada          #+#    #+#             */
/*   Updated: 2022/11/15 10:35:47 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int nbr)
{
	int		i;
	long	n;

	i = 0;
	n = nbr;
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_nbrhex_len(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_printlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (6);
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_ptr_len(unsigned long long n)
{
	int		i;

	i = 0;
	if (n == 0)
	i++;
	else
	{
		while (n != 0)
		{
		i++;
		n /= 16;
		}
	}
	return (i);
}

int	ft_unsigned_nbrlen(unsigned int nbr)
{
	int		i;
	long	n;

	i = 0;
	n = nbr;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
