/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:45:21 by everolla          #+#    #+#             */
/*   Updated: 2024/04/07 20:29:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putnbr(int nb, int d)
{
	char		c;
	static int	i;

	if (!d)
		i = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		i += write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb < 10)
	{
		c = nb + '0';
	}
	else
	{
		c = nb % 10 + '0';
		ft_putnbr(nb / 10, 1);
	}
	i += write(1, &c, 1);
	return (i);
}

int	ft_putnbr_u(unsigned int nb)
{
	static int	count;

	count = 0;
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 0)
	{
		if (nb > 9)
		{
			ft_putnbr_u(nb / 10);
			count += ft_putchar((nb % 10) + '0');
		}
		if (nb <= 9)
			count += ft_putchar(nb + '0');
	}
	return (count);
}

int	ft_putnbrptr(unsigned long long nb)
{
	const char	basex[16] = "0123456789abcdef";
	int			r;
	int			count;

	count = 0;
	if (nb < 16)
		count += write(1, &basex[nb], 1);
	if (nb >= 16)
	{
		r = nb % 16;
		nb = nb / 16;
		count += ft_putnbrptr(nb);
		count += write(1, &basex[r], 1);
	}
	return (count);
}

int	ft_putnbrhex(unsigned int nb, char x)
{
	const char	basex[16] = "0123456789abcdef";
	const char	base_[16] = "0123456789ABCDEF";
	int			r;
	int			count;

	count = 0;
	if (nb < 16 && (x > 65 && x < 91))
		count += write(1, &base_[nb], 1);
	if (nb < 16 && (x > 96 && x < 123))
		count += write(1, &basex[nb], 1);
	if (nb >= 16)
	{
		r = nb % 16;
		nb = nb / 16;
		count += ft_putnbrhex(nb, x);
		if (x > 65 && x < 91)
			count += write(1, &base_[r], 1);
		if (x > 96 && x < 123)
			count += write(1, &basex[r], 1);
	}
	return (count);
}
