/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_atoil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:55:46 by destrada          #+#    #+#             */
/*   Updated: 2022/12/07 13:07:21 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spaces_sign(char *str, int *pt_i)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}	
	*pt_i = i;
	return (sign);
}

// maybe i should control when only 1 zero 
void	ft_zero_left(char *str, int *pt_i)
{
	int	flag;

	flag = 1;
	while (str[*pt_i] != '\0' && str[*pt_i] == '0' && flag == 1)
	{
		if (str[*pt_i + 1] >= '1' && str[*pt_i + 1] <= '9')
			flag = 0;
		*pt_i = *pt_i + 1;
	}
}

long	ft_long_nbrlen(long nbr)
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

int	ft_check_atoil(char *str)
{
	int		i;
	int		*pt_i;
	long	sign;
	long	result;
	int		count;

	result = 0;
	count = 0;
	pt_i = &i;
	sign = ft_spaces_sign(str, pt_i);
	ft_zero_left(str, pt_i);
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = result * 10;
		result = result + (long)(str[i] - 48);
		i++;
		count++;
	}
	if (count > 10)
		return (0);
	result = sign * result;
	if ((result) > 2147483647 || (result) < -2147483648)
		return (0);
	return (1);
}
