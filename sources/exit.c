/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 20:25:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_img_win(t_game *game)
{
	int	len;
	int	tot_vert;
	int	tot_hor;

	len = 32;
	tot_vert = 3;
	tot_hor = len * game->map.cols;
	if (game->flag_loss == 1)
	{
		game->map.you_win = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/you_win.xpm",
				&tot_vert, &tot_hor);
		game->flag_loss = 0;
	}
	else
	{
		game->map.you_win = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/you_win1.xpm",
				&tot_vert, &tot_hor);
		game->flag_loss = 1;
	}
}

void	update_img_loss(t_game *game)
{
	int	len;
	int	tot_vert;
	int	tot_hor;

	len = 32;
	tot_vert = 3;
	tot_hor = len * game->map.cols;
	if (game->flag_loss == 1)
	{
		game->map.game_over = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/game_over.xpm",
				&tot_vert, &tot_hor);
		game->flag_loss = 0;
	}
	else
	{
		game->map.game_over = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/game_over1.xpm",
				&tot_vert, &tot_hor);
		game->flag_loss = 1;
	}
}

void	ft_you_lose(t_game *game)
{
	game->counter_loss++;
	if (game->counter_loss % 7 == 0)
		update_img_loss(game);
	mlx_put_image_to_window(game->mlx, game->window, game->map.game_over, 0, 0);
	game->map.map = game->map.map_original;
}

void	ft_you_win(t_game *game)
{
	game->counter_loss++;
	if (game->counter_loss % 7 == 0)
		update_img_win(game);
	mlx_put_image_to_window(game->mlx, game->window, game->map.you_win, 0, 0);
	game->map.map = game->map.map_original;
}

void	ft_exit(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		free(game->map.map[y]);
		y++;
	}
	ft_printf("Time: %d seconds\n", game->counter_calls / 20);
	free(game->map.map);
	destroy_image(game);
	exit(0);
}

int	close_game(void)
{
	printf("** EXIT GAME **");
	exit(0);
	return (0);
}