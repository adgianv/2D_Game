/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 20:24:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid2(t_game *game, int col, int line)
{
	if (game->map.map[col][line] == '1')
		return (-1);
	else if (game->map.map[col][line] == 'C')
		return (1);
	else if (game->map.map[col][line] == 'E')
		return (-1);
	else if (game->map.map[col][line] == 'X')
		return (-1);
	else if (game->map.map[col][line] == 'Z')
		return (-1);
	else if (game->map.map[col][line] == 'W')
		return (-1);
	else if (game->map.map[col][line] == '0')
		return (1);
	else if (game->map.map[col][line] == 'P')
		return (1);
	return (-1);
}

void	update_image_enemy2(t_game *game, char direction)
{
	int	len;

	len = SPRITE_SIZE;
	if (direction == 'W')
		game->map.enemy2 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_sx2.xpm",
				&len, &len);
	else if (direction == 'S')
		game->map.enemy2 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_up2.xpm",
				&len, &len);
	else if (direction == 'E')
		game->map.enemy2 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_dx2.xpm",
				&len, &len);
	else if (direction == 'N')
		game->map.enemy2 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_down2.xpm",
				&len, &len);
}

int	ft_straight2(t_game *game, int col, int line)
{
	if (valid2(game, --col, line) == 1 && game->prev_move2 == 'N')
	{
		switch_position2(game, col, line);
		return (1);
	}
	col++;
	if (valid2(game, col, --line) == 1 && game->prev_move2 == 'W')
	{
		switch_position2(game, col, line);
		return (1);
	}
	line++;
	if (valid2(game, ++col, line) == 1 && game->prev_move2 == 'S')
	{
		switch_position2(game, col, line);
		return (1);
	}
	col--;
	if (valid2(game, col, ++line) == 1 && game->prev_move2 == 'E')
	{
		switch_position2(game, col, line);
		return (1);
	}
	line--;
	return (0);
}

int	move_straight2(t_game *game)
{
	int	col;
	int	line;

	col = game->x_enemy2;
	line = game->y_enemy2;
	return (ft_straight2(game, col, line));
}

int	move_enemy_two(t_game *game)
{
	int	straight;
	int	col;
	int	line;
	int	chase;

	col = game->x_enemy2;
	line = game->y_enemy2;
	chase = chase_player2(game);
	if (chase == 1)
		return (0);
	straight = move_straight2(game);
	if (straight == 1)
		return (0);
	if (valid2(game, --col, line) == 1 && game->prev_move2 != 'S')
		return (ft_moven_two(game, col, line));
	col++;
	if (valid2(game, col, --line) == 1 && game->prev_move2 != 'E')
		return (ft_movew_two(game, col, line));
	line++;
	if (valid2(game, ++col, line) == 1 && game->prev_move2 != 'N')
		return (ft_moves_two(game, col, line));
	col--;
	if (valid2(game, col, ++line) == 1 && game->prev_move2 != 'W')
		return (ft_movee_two(game, col, line));
	line--;
	game->prev_move2 = '0';
	return (0);
}
