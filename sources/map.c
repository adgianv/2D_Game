/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 19:41:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_valid_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
	{
		i++;
	}
	if (ft_strcmp(&str[i], ".ber") != 0)
	{
		ft_printf(" %s", "\n **INVALID INPUT FILE NAME** \n\n");
		exit(0);
	}
}

void	check_map_pop(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'P')
	{
		game->x_player = y;
		game->y_player = x;
	}
	if (game->map.map[y][x] == 'X')
	{
		game->x_enemy = y;
		game->y_enemy = x;
	}
	if (game->map.map[y][x] == 'Y')
	{
		game->x_enemy2 = y;
		game->y_enemy2 = x;
	}
	if (game->map.map[y][x] == 'Z')
	{
		game->x_enemy3 = y;
		game->y_enemy3 = x;
	}
	if (game->map.map[y][x] == 'W')
	{
		game->x_enemy4 = y;
		game->y_enemy4 = x;
	}
	if ((game->map.map[y][x] != 'P') && (game->map.map[y][x] != 'E')
				&& (game->map.map[y][x] != 'C') &&
				(game->map.map[y][x] != '0') && (game->map.map[y][x] != '1')
				&& (game->map.map[y][x] != 'X') && (game->map.map[y][x] != 'Y')
				&& (game->map.map[y][x] != 'Z') && (game->map.map[y][x] != 'W') 
				&& (game->map.map[y][x] != 'A') && (game->map.map[y][x] != 'O') 
				&& (game->map.map[y][x] != 'K') && (game->map.map[y][x] != 'S'))
	{
		ft_printf(" %s", "\n **INVALID MAP POPULATION** \n\n");
		ft_exit(game);
	}
}

void	find_player_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			check_map_pop(game, x, y);
			x++;
		}
		y++;
	}
}

int	ft_count_rows(int fd)
{
	int		i;
	char	*buff;

	i = 1;
	buff = malloc(sizeof(char *));
	while (read(fd, buff, 1) > 0)
	{
		if (buff[0] == '\n')
			i++;
	}
	free(buff);
	return (i);
}

void	ft_parse_map(t_game *game, char *file)
{
	int		i;
	int		fd;

	/*opening and reading the file .txt*/
	fd = open(file, O_RDONLY, 0);
	if (!fd)
		ft_exit(game);
	game->map.rows = ft_count_rows(fd);
	close(fd);
	fd = open(file, O_RDONLY, 0);
	if (!fd)
		ft_exit(game);
	/*allocating the map matrix and filling it up*/
	game->map.map = malloc(game->map.rows * sizeof(char *));
	if (!game->map.map)
		ft_exit(game);
	i = 0;
	while (i <= game->map.rows)
	{
		game->map.map[i] = get_next_line(fd);
		i++;
	}
	game->map.cols = ft_strlen(game->map.map[0]);

	ft_check(game);
	find_player_exit(game);
	game->map.map_original = game->map.map;
	close(fd);
}
