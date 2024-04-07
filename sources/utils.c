/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 20:33:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	close_pacman(t_game *game)
{
	int	len;

	len = 32;
	game->map.player = mlx_xpm_file_to_image(game->mlx, "/Users/user/Desktop/MY CODE/Projects/C/Pacman/img/player_closed.xpm",
			&len, &len);
	game->was_coin = 0;
}

void	check_shape(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (ft_strlen(game->map.map[i]) != game->map.cols)
		{
			ft_printf(" %s", "\n **INVALID MAP SHAPE** \n\n");
			ft_exit(game);
		}
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	get_count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	long	nb;

	nb = (long) n;
	size = (int) get_count(nb);
	res = (char *) malloc (size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (nb == 0)
		res[0] = 48;
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		res[--size] = 48 + (nb % 10);
		nb /= 10;
	}
	return (res);
}
