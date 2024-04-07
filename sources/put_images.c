/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 20:26:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_image(t_game *game)
{
	int	len;

	len = SPRITE_SIZE;
	if (game->keycode == KEY_A || game->keycode == KEY_LEFT)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/player_sx.xpm", &len, &len);
	else if (game->keycode == KEY_W || game->keycode == KEY_UP)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/player_up.xpm", &len, &len);
	else if (game->keycode == KEY_D || game->keycode == KEY_RIGHT)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/player_dx.xpm", &len, &len);
	else if (game->keycode == KEY_S || game->keycode == KEY_DOWN)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/player_down.xpm", &len, &len);
}

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map.player);
	mlx_destroy_image(game->mlx, game->map.floor);
	mlx_destroy_image(game->mlx, game->map.wall);
	mlx_destroy_image(game->mlx, game->map.enemy);
	mlx_destroy_image(game->mlx, game->map.enemy2);
	mlx_destroy_image(game->mlx, game->map.coin);
	mlx_destroy_image(game->mlx, game->map.exit);
	mlx_destroy_image(game->mlx, game->map.game_over);
	mlx_destroy_window(game->mlx, game->window);
}

void	put_images(t_game *game)
{
	int	len;
	int	tot_vert;
	int	tot_hor;

	len = 32;
	tot_vert = 3;
	tot_hor = len * game->map.cols;
	game->map.wall = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/wall.xpm", &len,
			&len);
	game->map.player = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/player_dx.xpm",
			&len, &len);
	game->map.floor = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/floor.xpm", &len,
			&len);
	game->map.exit = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/exit.xpm", &len,
			&len);
	game->map.coin = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/coin.xpm", &len,
			&len);
	game->map.enemy = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/enemy_dx.xpm",
			&len, &len);
	game->map.enemy2 = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/enemy_dx2.xpm",
			&len, &len);
	game->map.enemy3 = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/enemy_dx3.xpm",
			&len, &len);
	game->map.enemy4 = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/enemy_dx4.xpm",
			&len, &len);
	game->map.apple = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/apple.xpm",
			&len, &len);
	game->map.orange = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/orange.xpm",
			&len, &len);
	game->map.cherry = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/cherry.xpm",
			&len, &len);
	game->map.strawberry = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/strawberry.xpm",
			&len, &len);
	game->map.game_over = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/game_over.xpm",
			&tot_vert, &tot_hor);
	game->map.you_win = mlx_xpm_file_to_image(game->mlx, "./2D_Game/img/you_win.xpm",
			&tot_vert, &tot_hor);
}

void	mlx_put_image(int x, int y, t_game *game)
{
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->map.wall, x * 32,
			y * 32);
	if (game->map.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->map.floor, x
			* 32, y * 32);
	if (game->map.map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->map.player, x
			* 32, y * 32);
	if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->map.exit, x * 32,
			y * 32);
	if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->map.coin, x * 32,
			y * 32);
	if (game->map.map[y][x] == 'X')
		mlx_put_image_to_window(game->mlx, game->window, game->map.enemy, x
			* 32, y * 32);
	if (game->map.map[y][x] == 'Y')
		mlx_put_image_to_window(game->mlx, game->window, game->map.enemy2, x
			* 32, y * 32);
	if (game->map.map[y][x] == 'Z')
		mlx_put_image_to_window(game->mlx, game->window, game->map.enemy3, x
			* 32, y * 32);
	if (game->map.map[y][x] == 'W')
		mlx_put_image_to_window(game->mlx, game->window, game->map.enemy4, x
			* 32, y * 32);
	if (game->map.map[y][x] == 'A')
		mlx_put_image_to_window(game->mlx, game->window, game->map.apple, x * 32,
			y * 32);
	if (game->map.map[y][x] == 'O')
		mlx_put_image_to_window(game->mlx, game->window, game->map.orange, x * 32,
			y * 32);
	if (game->map.map[y][x] == 'K')
		mlx_put_image_to_window(game->mlx, game->window, game->map.cherry, x * 32,
			y * 32);
	if (game->map.map[y][x] == 'S')
		mlx_put_image_to_window(game->mlx, game->window, game->map.strawberry, x * 32,
			y * 32);
}

void	put_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x] != '\0')
		{
			mlx_put_image(x, y, game);
			x++;
		}
		y++;
	}
}
