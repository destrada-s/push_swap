/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:35:22 by destrada          #+#    #+#             */
/*   Updated: 2022/10/18 18:17:48 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_rec(int n, int fd)
{
	if (n > -10 && n < 10)
	{
		if (n < 0)
			ft_putchar_fd((-n + '0'), fd);
		else
			ft_putchar_fd((n + '0'), fd);
	}
	else
	{
		ft_putnbr_fd_rec((n / 10), fd);
		if (n < 0)
			ft_putchar_fd(-(n % 10) + '0', fd);
		else
			ft_putchar_fd((n % 10) + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	ft_putnbr_fd_rec(n, fd);
}
