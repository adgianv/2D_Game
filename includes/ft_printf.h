/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <andi-gia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2023/07/15 15:59:01 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_bigcheck(const char *str, int i, va_list argptr, int count);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int nb, int d);
int	ft_putnbrhex(unsigned int nb, char x);
int	ft_putptr(unsigned long long nb);
int	ft_putnbr_u(unsigned int nb);

#endif