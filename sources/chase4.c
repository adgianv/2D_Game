/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chase4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 19:40:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	chase_vertical4(t_game *game)
{
	int	col;
	int	line;
	int	vertical;

	vertical = game->x_enemy4 - game->x_player;
	col = game->x_enemy4;
	line = game->y_enemy4;
	col--;
	if (vertical > 0 && valid(game, col, line) == 1 && game->prev_move4 != 'S')
	{
		ft_moven_four(game, col, line);
		game->prev_move4 = 'N';
		return (1);
	}
	col++;
	col++;
	if (vertical < 0 && valid(game, col, line) == 1 && game->prev_move4 != 'N')
	{
		ft_moves_four(game, col, line);
		game->prev_move4 = 'S';
		return (1);
	}
	return (0);
}

int	chase_horizontal4(t_game *game)
{
	int	col;
	int	line;
	int	horizontal;

	horizontal = game->y_enemy4 - game->y_player;
	col = game->x_enemy4;
	line = game->y_enemy4;
	line--;
	if (horizontal > 0 && valid(game, col, line) == 1
		&& game->prev_move4 != 'E')
	{
		ft_movew_four(game, col, line);
		game->prev_move4 = 'W';
		return (1);
	}
	line++;
	line++;
	if (horizontal < 0 && valid(game, col, line) == 1
		&& game->prev_move4 != 'W')
	{
		ft_movee_four(game, col, line);
		game->prev_move4 = 'E';
		return (1);
	}
	return (0);
}

int	chase_player4(t_game *game)
{
	int vertical;
	int horizontal;

	vertical = game->x_enemy4 - game->x_player;
	horizontal = game->y_enemy4 - game->y_player;
	if (horizontal < 0)
		horizontal *= -1;
	if (vertical < 0)
		vertical *= -1;
	if ((vertical > game->map.cols / 3 || horizontal > game->map.cols / 3)
		&& game->fruit != 0)
		return (0);
	if (vertical > horizontal)
	{
		if (chase_vertical4(game) == 1)
			return (1);
		if (chase_horizontal4(game) == 1)
			return (1);
	}
	else if (horizontal > vertical)
	{
		if (chase_horizontal4(game) == 1)
			return (1);
		if (chase_vertical4(game) == 1)
			return (1);
	}
	return (0);
}