/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_prints_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:06:48 by destrada          #+#    #+#             */
/*   Updated: 2022/11/15 10:35:56 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	unsigned long	nb;

	nb = n;
	if (nb < 10)
	{
		ft_putchar_fd((nb + '0'), fd);
	}
	else
	{
		ft_put_unsigned_nbr_fd((nb / 10), fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
}

void	ft_puthex(unsigned int n, char *base)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, base);
		ft_putchar_fd(base[n % 16], 1);
	}
	else
		ft_putchar_fd(base[n], 1);
}

void	ft_printstr(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}

void	ft_put_ptr(unsigned long long n, char *base)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16, base);
		ft_putchar_fd(base[n % 16], 1);
	}
	else
		ft_putchar_fd(base[n], 1);
}
