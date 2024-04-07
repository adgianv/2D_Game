/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 20:25:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid3(t_game *game, int col, int line)
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
	else if (game->map.map[col][line] == 'W')
		return (-1);
	else if (game->map.map[col][line] == '0')
		return (1);
	else if (game->map.map[col][line] == 'P')
		return (1);
	return (-1);
}

void	update_image_enemy3(t_game *game, char direction)
{
	int	len;

	len = SPRITE_SIZE;
	if (direction == 'W')
		game->map.enemy3 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_sx3.xpm",
				&len, &len);
	else if (direction == 'S')
		game->map.enemy3 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_up3.xpm",
				&len, &len);
	else if (direction == 'E')
		game->map.enemy3 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_dx3.xpm",
				&len, &len);
	else if (direction == 'N')
		game->map.enemy3 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/enemy_down3.xpm",
				&len, &len);
}

int	ft_straight3(t_game *game, int col, int line)
{
	if (valid3(game, --col, line) == 1 && game->prev_move3 == 'N')
	{
		switch_position3(game, col, line);
		return (1);
	}
	col++;
	if (valid3(game, col, --line) == 1 && game->prev_move3 == 'W')
	{
		switch_position3(game, col, line);
		return (1);
	}
	line++;
	if (valid3(game, ++col, line) == 1 && game->prev_move3 == 'S')
	{
		switch_position3(game, col, line);
		return (1);
	}
	col--;
	if (valid3(game, col, ++line) == 1 && game->prev_move3 == 'E')
	{
		switch_position3(game, col, line);
		return (1);
	}
	line--;
	return (0);
}

int	move_straight3(t_game *game)
{
	int	col;
	int	line;

	col = game->x_enemy3;
	line = game->y_enemy3;
	return (ft_straight3(game, col, line));
}

int	move_enemy_three(t_game *game)
{
	int	straight;
	int	col;
	int	line;
	int	chase;

	col = game->x_enemy3;
	line = game->y_enemy3;
	chase = chase_player3(game);
	if (chase == 1)
		return (0);
	straight = move_straight3(game);
	if (straight == 1)
		return (0);
	if (valid3(game, col, --line) == 1 && game->prev_move3 != 'E')
		return (ft_movew_three(game, col, line));
	line++;
	if (valid3(game, ++col, line) == 1 && game->prev_move3 != 'N')
		return (ft_moves_three(game, col, line));
	col--;
	if (valid3(game, col, ++line) == 1 && game->prev_move3 != 'W')
		return (ft_movee_three(game, col, line));
	line--;
	if (valid3(game, --col, line) == 1 && game->prev_move3 != 'S')
		return (ft_moven_three(game, col, line));
	col++;
	game->prev_move3 = '0';
	return (0);
}
