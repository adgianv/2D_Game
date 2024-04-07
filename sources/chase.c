/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 19:39:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	chase_vertical(t_game *game)
{
	int	col;
	int	line;
	int	vertical;

	vertical = game->x_enemy - game->x_player;
	col = game->x_enemy;
	line = game->y_enemy;
	col--;
	if (vertical > 0 && valid(game, col, line) == 1 && game->prev_move != 'S')
	{
		ft_moven(game, col, line);
		game->prev_move = 'N';
		return (1);
	}
	col++;
	col++;
	if (vertical < 0 && valid(game, col, line) == 1 && game->prev_move != 'N')
	{
		ft_moves(game, col, line);
		game->prev_move = 'S';
		return (1);
	}
	return (0);
}

int	chase_horizontal(t_game *game)
{
	int	col;
	int	line;
	int	horizontal;

	horizontal = game->y_enemy - game->y_player;
	col = game->x_enemy;
	line = game->y_enemy;
	line--;
	if (horizontal > 0 && valid(game, col, line) == 1 && game->prev_move != 'E')
	{
		ft_movew(game, col, line);
		game->prev_move = 'W';
		return (1);
	}
	line++;
	line++;
	if (horizontal < 0 && valid(game, col, line) == 1 && game->prev_move != 'W')
	{
		ft_movee(game, col, line);
		game->prev_move = 'E';
		return (1);
	}
	return (0);
}

int	chase_player(t_game *game)
{
    int vertical;
    int horizontal;

	vertical = game->x_enemy - game->x_player;
	horizontal = game->y_enemy - game->y_player;
	if (horizontal < 0)
		horizontal *= -1;
	if (vertical < 0)
		vertical *= -1;
	if ((vertical > game->map.cols / 2 || horizontal > game->map.cols / 2)
		&& game->fruit != 0)
		return (0);
	if (vertical > horizontal)
	{
		if (chase_vertical(game) == 1)
			return (1);
		if (chase_horizontal(game) == 1)
			return (1);
	}
	else if (horizontal > vertical)
	{
		if (chase_horizontal(game) == 1)
			return (1);
		if (chase_vertical(game) == 1)
			return (1);
	}
	return (0);
}