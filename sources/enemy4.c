/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 20:25:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid4(t_game *game, int col, int line)
{
	if (game->map.map[col][line] == '1')
		return (-1);
	else if (game->map.map[col][line] == 'C')
		return (1);
	else if (game->map.map[col][line] == 'E')
		return (-1);
	else if (game->map.map[col][line] == 'X')
		return (-1);
	else if (game->map.map[col][line] == 'Y')
		return (-1);
	else if (game->map.map[col][line] == 'Z')
		return (-1);
	else if (game->map.map[col][line] == '0')
		return (1);
	else if (game->map.map[col][line] == 'P')
		return (1);
	return (-1);
}

void	update_image_enemy4(t_game *game, char direction)
{
	int	len;

	len = SPRITE_SIZE;
	if (direction == 'W')
		game->map.enemy4 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_sx4.xpm",
				&len, &len);
	else if (direction == 'S')
		game->map.enemy4 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_down4.xpm",
				&len, &len);
	else if (direction == 'E')
		game->map.enemy4 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_dx4.xpm",
				&len, &len);
	else if (direction == 'N')
		game->map.enemy4 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_up4.xpm",
				&len, &len);
}

int	ft_straight4(t_game *game, int col, int line)
{
	if (valid4(game, --col, line) == 1 && game->prev_move4 == 'N')
	{
		switch_position4(game, col, line);
		return (1);
	}
	col++;
	if (valid4(game, col, --line) == 1 && game->prev_move4 == 'W')
	{
		switch_position4(game, col, line);
		return (1);
	}
	line++;
	if (valid4(game, ++col, line) == 1 && game->prev_move4 == 'S')
	{
		switch_position4(game, col, line);
		return (1);
	}
	col--;
	if (valid4(game, col, ++line) == 1 && game->prev_move4 == 'E')
	{
		switch_position4(game, col, line);
		return (1);
	}
	line--;
	return (0);
}

int	move_straight4(t_game *game)
{
	int	col;
	int	line;

	col = game->x_enemy4;
	line = game->y_enemy4;
	return (ft_straight4(game, col, line));
}

int	move_enemy_four(t_game *game)
{
	int	straight;
	int	col;
	int	line;
	int	chase;

	col = game->x_enemy4;
	line = game->y_enemy4;
	chase = chase_player4(game);
	if (chase == 1)
		return (0);
	straight = move_straight4(game);
	if (straight == 1)
		return (0);
	if (valid4(game, col, --line) == 1 && game->prev_move4 != 'E')
		return (ft_movew_four(game, col, line));
	line++;
	if (valid4(game, --col, line) == 1 && game->prev_move4 != 'S')
		return (ft_moven_four(game, col, line));
	col++;
	if (valid4(game, col, ++line) == 1 && game->prev_move4 != 'W')
		return (ft_movee_four(game, col, line));
	line--;
	if (valid4(game, ++col, line) == 1 && game->prev_move4 != 'N')
		return (ft_moves_four(game, col, line));
	col--;
	game->prev_move4 = '0';
	return (0);
}
