/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:11:28 by everolla          #+#    #+#             */
/*   Updated: 2024/04/07 20:29:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_bigcheck(const char *str, int i, va_list argptr, int count)
{
	if (str[i] == 'c')
		count = ft_putchar(va_arg(argptr, int));
	if (str[i] == 's')
		count = ft_putstr(va_arg(argptr, char *));
	if (str[i] == 'p')
	{
		write(1, "0x", 2);
		count = ft_putptr(va_arg(argptr, unsigned long long)) + 2;
	}
	if (str[i] == 'd' || str[i] == 'i')
		count = ft_putnbr(va_arg(argptr, int), 0);
	if (str[i] == 'u')
		count = ft_putnbr_u(va_arg(argptr, unsigned int));
	if (str[i] == 'x')
		count = ft_putnbrhex(va_arg(argptr, unsigned int), 'x');
	if (str[i] == 'X')
		count = ft_putnbrhex(va_arg(argptr, unsigned int), 'X');
	if (str[i] == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	argptr;
	int		count;
	int		r;

	va_start(argptr, str);
	i = 0;
	r = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != '%' && str[i] != '\0')
			write(1, &str[i++], 1);
		if (str[i] == '%')
			r++;
		if (str[i] == '\0')
			break ;
		i++;
		count += ft_bigcheck(str, i, argptr, count);
		i++;
	}
	va_end(argptr);
	return (count + (i - (r * 2)));
}
