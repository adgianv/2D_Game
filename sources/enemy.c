/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 20:23:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid(t_game *game, int col, int line)
{
	if (game->map.map[col][line] == '1')
		return (-1);
	else if (game->map.map[col][line] == 'C')
		return (1);
	else if (game->map.map[col][line] == 'E')
		return (-1);
	else if (game->map.map[col][line] == 'Y')
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

void	update_image_enemy(t_game *game, char direction)
{
	int	len;

	len = SPRITE_SIZE;
	if (direction == 'W')
		game->map.enemy = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_sx.xpm",
				&len, &len);
	else if (direction == 'S')
		game->map.enemy = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_up.xpm",
				&len, &len);
	else if (direction == 'E')
		game->map.enemy = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_dx.xpm",
				&len, &len);
	else if (direction == 'N')
		game->map.enemy = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_down.xpm",
				&len, &len);
}

int	ft_straight(t_game *game, int col, int line)
{
	if (valid(game, --col, line) == 1 && game->prev_move == 'N')
	{
		switch_position(game, col, line);
		return (1);
	}
	col++;
	if (valid(game, col, --line) == 1 && game->prev_move == 'W')
	{
		switch_position(game, col, line);
		return (1);
	}
	line++;
	if (valid(game, ++col, line) == 1 && game->prev_move == 'S')
	{
		switch_position(game, col, line);
		return (1);
	}
	col--;
	if (valid(game, col, ++line) == 1 && game->prev_move == 'E')
	{
		switch_position(game, col, line);
		return (1);
	}
	line--;
	return (0);
}

int	move_straight(t_game *game)
{
	int	col;
	int	line;

	col = game->x_enemy;
	line = game->y_enemy;
	return (ft_straight(game, col, line));
}

int	move_enemy(t_game *game)
{
	int	straight;
	int	col;
	int	line;
	int	chase;

	col = game->x_enemy;
	line = game->y_enemy;
	chase = chase_player(game);
	if (chase == 1)
		return (0);
	straight = move_straight(game);
	if (straight == 1)
		return (0);
	if (valid(game, ++col, line) == 1 && game->prev_move != 'N')
		return (ft_moves(game, col, line));
	col--;
	if (valid(game, col, ++line) == 1 && game->prev_move != 'W')
		return (ft_movee(game, col, line));
	line--;
	if (valid(game, --col, line) == 1 && game->prev_move != 'S')
		return (ft_moven(game, col, line));
	col++;
	if (valid(game, col, --line) == 1 && game->prev_move != 'E')
		return (ft_movew(game, col, line));
	line++;
	game->prev_move = '0';
	return (0);
}
