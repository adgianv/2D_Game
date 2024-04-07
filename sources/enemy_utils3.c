/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 19:40:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	switch_position3(t_game *game, int col, int line)
{
	int	tcol;
	int	tline;

	tcol = game->x_enemy3;
	tline = game->y_enemy3;
	game->x_enemy3 = col;
	game->y_enemy3 = line;
	if (game->map.map[col][line] == 'P' && game->lost != 2)
	{
		ft_printf("\n\nYOU lose DUMMY👻\n\n");
		game->lost = 1;
		ft_you_lose(game);
	}
	if (game->was_collectible3 == 1)
		game->map.map[tcol][tline] = 'C';
	else
		game->map.map[tcol][tline] = '0';
	if (game->map.map[col][line] == 'C')
		game->was_collectible3 = 1;
	else
		game->was_collectible3 = 0;
	game->map.map[col][line] = 'Z';
}

int	ft_moven_three(t_game *game, int col, int line)
{
	switch_position3(game, col, line);
	game->prev_move3 = 'N';
	update_image_enemy3(game, 'N');
	return (0);
}

int	ft_movew_three(t_game *game, int col, int line)
{
	switch_position3(game, col, line);
	game->prev_move3 = 'W';
	update_image_enemy3(game, 'W');
	return (0);
}

int	ft_movee_three(t_game *game, int col, int line)
{
	switch_position3(game, col, line);
	game->prev_move3 = 'E';
	update_image_enemy3(game, 'E');
	return (0);
}

int	ft_moves_three(t_game *game, int col, int line)
{
	switch_position3(game, col, line);
	game->prev_move3 = 'S';
	update_image_enemy3(game, 'S');
	return (0);
}
