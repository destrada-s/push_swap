/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario42 <usuario42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:33:25 by destrada          #+#    #+#             */
/*   Updated: 2022/12/01 09:23:16 by usuario42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_switch_cont(va_list arguments_cont, char c, int *cont)
{
	if (c == 'c')
	{
		va_arg(arguments_cont, int);
		*cont += 1;
	}
	else if (c == 's')
		*cont += ft_printlen(va_arg(arguments_cont, char *));
	else if (c == 'p')
	{
		*cont += 2;
		*cont += ft_ptr_len(va_arg(arguments_cont, unsigned long int));
	}
	else if (c == 'd' || c == 'i')
		*cont += ft_nbrlen(va_arg(arguments_cont, int));
	else if (c == 'u')
		*cont += ft_unsigned_nbrlen(va_arg(arguments_cont, unsigned int));
	else if (c == 'x')
		*cont += ft_nbrhex_len(va_arg(arguments_cont, unsigned int));
	else if (c == 'X')
		*cont += ft_nbrhex_len(va_arg(arguments_cont, unsigned int));
	else if (c == '%')
		*cont += 1;
}

static int	ft_switch(va_list arguments, char c)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(arguments, int), 1);
	else if (c == 's')
		ft_printstr(va_arg(arguments, char *));
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_put_ptr(va_arg(arguments, unsigned long long), "0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(arguments, int), 1);
	else if (c == 'u')
		ft_put_unsigned_nbr_fd(va_arg(arguments, unsigned int), 1);
	else if (c == 'x')
		ft_puthex(va_arg(arguments, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_puthex(va_arg(arguments, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return (1);
}

int	ft_printf(char const *format, ...)
{
	va_list	arguments;
	va_list	arguments_cont;
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	va_start(arguments, format);
	va_copy(arguments_cont, arguments);
	while (format[i])
	{
		if (format[i] == '%')
		{	
			ft_switch_cont(arguments_cont, format[i + 1], &cont);
			i += ft_switch(arguments, format[i + 1]);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			cont++;
		}
		i++;
	}
	return (va_end(arguments), va_end(arguments_cont), cont);
}
/*switch chooses the type of variable and prints the output on terminal*/
/*switch_cont counts the amount of words of each variable*/
/*ft_printf prints the string with the variable parameters using
	va_list to get the differents parameters*/