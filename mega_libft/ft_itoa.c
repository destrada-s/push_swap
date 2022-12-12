/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:28:18 by destrada          #+#    #+#             */
/*   Updated: 2022/11/15 10:34:48 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_nbrlen(long nbr)
{
	int		i;

	i = 0;
	if (nbr == 0)
		i++;
	if (nbr < 0)
		nbr *= -1;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static int	ft_powerten(int len)
{
	int	poweroften;

	len--;
	poweroften = 1;
	while (len > 0)
	{
		poweroften *= 10;
		len--;
	}
	return (poweroften);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		numlen;
	int		i;
	int		negative;
	long	nb;

	nb = n;
	numlen = ft_itoa_nbrlen(nb);
	negative = (n < 0);
	str = (char *)ft_calloc(numlen + negative + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (numlen > 0)
	{
		if (nb < 0)
		{
			nb *= -1;
			str[i++] = '-';
		}
		str[i++] = ((nb) / ft_powerten(numlen)) + 48;
		nb %= ft_powerten(numlen);
		numlen--;
	}
	return (str);
}
