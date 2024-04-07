/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 19:40:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	switch_position4(t_game *game, int col, int line)
{
	int	tcol;
	int	tline;

	tcol = game->x_enemy4;
	tline = game->y_enemy4;
	game->x_enemy4 = col;
	game->y_enemy4 = line;
	if (game->map.map[col][line] == 'P' && game->lost != 2)
	{
		ft_printf("\n\nYOU lose DUMMY👻\n\n");
		game->lost = 1;
		ft_you_lose(game);
	}
	if (game->was_collectible4 == 1)
		game->map.map[tcol][tline] = 'C';
	else
		game->map.map[tcol][tline] = '0';
	if (game->map.map[col][line] == 'C')
		game->was_collectible4 = 1;
	else
		game->was_collectible4 = 0;
	game->map.map[col][line] = 'W';
}

int	ft_moven_four(t_game *game, int col, int line)
{
	switch_position4(game, col, line);
	game->prev_move4 = 'N';
	update_image_enemy4(game, 'N');
	return (0);
}

int	ft_movew_four(t_game *game, int col, int line)
{
	switch_position4(game, col, line);
	game->prev_move4 = 'W';
	update_image_enemy4(game, 'W');
	return (0);
}

int	ft_movee_four(t_game *game, int col, int line)
{
	switch_position4(game, col, line);
	game->prev_move4 = 'E';
	update_image_enemy4(game, 'E');
	return (0);
}

int	ft_moves_four(t_game *game, int col, int line)
{
	switch_position4(game, col, line);
	game->prev_move4 = 'S';
	update_image_enemy4(game, 'S');
	return (0);
}
