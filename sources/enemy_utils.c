/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 19:40:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	switch_position(t_game *game, int col, int line)
{
	int	tcol;
	int	tline;

	tcol = game->x_enemy;
	tline = game->y_enemy;
	game->x_enemy = col;
	game->y_enemy = line;
	if (game->map.map[col][line] == 'P' && game->lost != 2)
	{
		ft_printf("\n\nYOU lose DUMMY👻\n\n");
		game->lost = 1;
		ft_you_lose(game);
	}
	if (game->was_collectible == 1)
		game->map.map[tcol][tline] = 'C';
	else
		game->map.map[tcol][tline] = '0';
	if (game->map.map[col][line] == 'C')
		game->was_collectible = 1;
	else
		game->was_collectible = 0;
	game->map.map[col][line] = 'X';
}

int	ft_moven(t_game *game, int col, int line)
{
	switch_position(game, col, line);
	game->prev_move = 'N';
	update_image_enemy(game, 'N');
	return (0);
}

int	ft_movew(t_game *game, int col, int line)
{
	switch_position(game, col, line);
	game->prev_move = 'W';
	update_image_enemy(game, 'W');
	return (0);
}

int	ft_movee(t_game *game, int col, int line)
{
	switch_position(game, col, line);
	game->prev_move = 'E';
	update_image_enemy(game, 'E');
	return (0);
}

int	ft_moves(t_game *game, int col, int line)
{
	switch_position(game, col, line);
	game->prev_move = 'S';
	update_image_enemy(game, 'S');
	return (0);
}
