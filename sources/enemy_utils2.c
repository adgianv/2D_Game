/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 19:40:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	switch_position2(t_game *game, int col, int line)
{
	int	tcol;
	int	tline;

	tcol = game->x_enemy2;
	tline = game->y_enemy2;
	game->x_enemy2 = col;
	game->y_enemy2 = line;
	if (game->map.map[col][line] == 'P' && game->lost != 2)
	{
		ft_printf("\n\nYOU lose DUMMY👻\n\n");
		game->lost = 1;
		ft_you_lose(game);
	}
	if (game->was_collectible2 == 1)
		game->map.map[tcol][tline] = 'C';
	else
		game->map.map[tcol][tline] = '0';
	if (game->map.map[col][line] == 'C')
		game->was_collectible2 = 1;
	else
		game->was_collectible2 = 0;
	game->map.map[col][line] = 'Y';
}

int	ft_moven_two(t_game *game, int col, int line)
{
	switch_position2(game, col, line);
	game->prev_move2 = 'N';
	update_image_enemy2(game, 'N');
	return (0);
}

int	ft_movew_two(t_game *game, int col, int line)
{
	switch_position2(game, col, line);
	game->prev_move2 = 'W';
	update_image_enemy2(game, 'W');
	return (0);
}

int	ft_movee_two(t_game *game, int col, int line)
{
	switch_position2(game, col, line);
	game->prev_move2 = 'E';
	update_image_enemy2(game, 'E');
	return (0);
}

int	ft_moves_two(t_game *game, int col, int line)
{
	switch_position2(game, col, line);
	game->prev_move2 = 'S';
	update_image_enemy2(game, 'S');
	return (0);
}
