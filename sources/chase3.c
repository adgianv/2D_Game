/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chase3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 19:40:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	chase_vertical3(t_game *game)
{
	int	col;
	int	line;
	int	vertical;

	vertical = game->x_enemy3 - game->x_player;
	col = game->x_enemy3;
	line = game->y_enemy3;
	col--;
	if (vertical > 0 && valid(game, col, line) == 1 && game->prev_move3 != 'S')
	{
		ft_moven_three(game, col, line);
		game->prev_move3 = 'N';
		return (1);
	}
	col++;
	col++;
	if (vertical < 0 && valid(game, col, line) == 1 && game->prev_move3 != 'N')
	{
		ft_moves_three(game, col, line);
		game->prev_move3 = 'S';
		return (1);
	}
	return (0);
}

int	chase_horizontal3(t_game *game)
{
	int	col;
	int	line;
	int	horizontal;

	horizontal = game->y_enemy3 - game->y_player;
	col = game->x_enemy3;
	line = game->y_enemy3;
	line--;
	if (horizontal > 0 && valid(game, col, line) == 1
		&& game->prev_move3 != 'E')
	{
		ft_movew_three(game, col, line);
		game->prev_move3 = 'W';
		return (1);
	}
	line++;
	line++;
	if (horizontal < 0 && valid(game, col, line) == 1
		&& game->prev_move3 != 'W')
	{
		ft_movee_three(game, col, line);
		game->prev_move3 = 'E';
		return (1);
	}
	return (0);
}

int	chase_player3(t_game *game)
{
	int vertical;
	int horizontal;

	vertical = game->x_enemy3 - game->x_player;
	horizontal = game->y_enemy3 - game->y_player;
	if (horizontal < 0)
		horizontal *= -1;
	if (vertical < 0)
		vertical *= -1;
	if ((vertical > game->map.cols / 3 || horizontal > game->map.cols / 2)
		&& game->fruit != 0)
		return (0);
	if (vertical > horizontal)
	{
		if (chase_vertical3(game) == 1)
			return (1);
		if (chase_horizontal3(game) == 1)
			return (1);
	}
	else if (horizontal > vertical)
	{
		if (chase_horizontal3(game) == 1)
			return (1);
		if (chase_vertical3(game) == 1)
			return (1);
	}
	return (0);
}