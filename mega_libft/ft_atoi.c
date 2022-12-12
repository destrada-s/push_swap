/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:55:46 by destrada          #+#    #+#             */
/*   Updated: 2022/12/07 09:16:11 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spaces_sign(const char *str, int *pt_i)
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

int	ft_atoi(const char *str)
{
	int	i;
	int	*pt_i;
	int	sign;
	int	result;

	result = 0;
	i = 0;
	pt_i = &i;
	sign = ft_spaces_sign(str, pt_i);
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = result * 10;
		result = result + (str[i] - 48);
		i++;
	}
	return (sign * result);
}
