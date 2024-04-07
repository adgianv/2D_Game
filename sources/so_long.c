/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 20:32:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	panic(t_game *game)
{
	int	len;

	len = 32;
	if (game->counter_calls % 2 == 0)
	{
		move_enemy(game);
		move_enemy_two(game);
		move_enemy_three(game);
		move_enemy_four(game);
	}
	if (game->panic_counter == 0)
	{
		game->map.enemy = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/panic_blue.xpm",
				&len, &len);
		game->map.enemy2 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/panic_white.xpm",
				&len, &len);
		game->map.enemy3 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/panic_blue.xpm",
				&len, &len);
		game->map.enemy4 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/panic_white.xpm",
				&len, &len);
		game->panic_counter = 1;
	}
	else if (game->panic_counter == 1)
	{
		game->map.enemy = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/panic_white.xpm",
				&len, &len);
		game->map.enemy2 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/panic_blue.xpm",
				&len, &len);
		game->map.enemy3 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/panic_white.xpm",
				&len, &len);
		game->map.enemy4 = mlx_xpm_file_to_image(game->mlx,
				"./2D_Game/img/panic_blue.xpm",
				&len, &len);
		game->panic_counter = 0;
	}
}

int	render_image(t_game *game)
{
	if (game->was_coin == 1)
		close_pacman(game);
	else
		update_image(game);
	if (game->counter_calls % 2 == 0)
	{
		if (game->keycode != 12345)
		{
			key_checker(game);
			move_player(game);
		}
	}
	put_map(game);
	/*moving the enemy*/
	if (game->fruit > 0 || game->panic >= 60)
	{
		if (game->counter_calls % 3 == 0)
		{
			move_enemy(game);
			move_enemy_two(game);
			move_enemy_three(game);
			move_enemy_four(game);
		}
	}
	if (game->fruit == 0 && game->panic < 60)
	{
		panic(game);
		game->panic += 1;
	}
	if (game->lost == 1)
		ft_you_lose(game);
	if (game->lost == 2)
		ft_you_win(game);
	game->counter_calls++;
	if (game->counter_calls == 2147483646)
		game->counter_calls = 0;
	return (0);
}

void	print_strings(t_game *game)
{
	char	*str;
	char	*join;

	str = ft_itoa(game->move_counter);
	join = ft_join("Move counter : ", str);
	mlx_string_put(game->mlx, game->window, 32, (game->map.rows + 1) * 32,
		0x0000FF00, join);
	free(str);
	free(join);
	str = ft_itoa(game->counter_calls);
	str = ft_itoa(game->collectibles);
	join = ft_join("To collect : ", str);
	mlx_string_put(game->mlx, game->window, ((game->map.cols) - 4) * 32,
		(game->map.rows + 1) * 32, 0xCFFF04, join);
	free(str);
	free(join);
}

void	game_init(t_game *game)
{
	/*first print of the map*/
	put_images(game);
	/*first print of the strings on screen*/
	// print_strings(game);
	/*mlx function to close the game*/
	mlx_hook(game->window, 17, 0, &close_game, game);
	/*mlx function for key pressing*/
	mlx_hook(game->window, 2, 0, &key_handler, game);
	/*mlx function looping and rendering the image*/
	mlx_loop_hook(game->mlx, &render_image, game);
	mlx_loop(game->mlx);
}

void	init_struct(t_game *game)
{
	game->lost = 0;
	game->counter_loss = 0;
	game->flag_loss = 1;
	game->fruit = 6;
	game->was_collectible = 0;
	game->was_collectible2 = 0;
	game->was_collectible3 = 0;
	game->was_collectible4 = 0;
	game->move_counter = 0;
	game->panic_counter = 0;
	game->col = game->x_player;
	game->line = game->y_player;
	game->keycode = 12345;
	game->movement = 0;
	game->panic = 0;
}

int	main(void)
{
	t_game		game;
	char		path[PATH_MAX];
	uint32_t	size;
	char		*lastSlash;
				char cwd[1024];

	// Get the path of the executable on macOS
	size = sizeof(path);
	if (_NSGetExecutablePath(path, &size) == 0)
	{
		// Success in getting the executable path
		lastSlash = strrchr(path, '/');
		if (lastSlash != NULL)
		{
			*lastSlash = '\0';
			// Change the working directory to the executable's directory
			if (chdir(path) == 0)
			{
				// Print the current working directory
				if (getcwd(cwd, sizeof(cwd)) != NULL)
				{
					fprintf(stdout, "Current working directory: %s\n", cwd);
				}
				else
				{
					perror("getcwd");
				}
				game.filename = "./2D_Game/map/pacman-classic.ber";
				ft_parse_map(&game,
					"./2D_Game/map/pacman-classic.ber");
				game.mlx = mlx_init();
				game.window = mlx_new_window(game.mlx, game.map.cols * 32,
						(game.map.rows + 2) * 32, "Pacman");
				init_struct(&game);
				game_init(&game);
				ft_exit(&game);
				return (0);
			}
			else
			{
				// Handle the error if chdir fails
				perror("chdir");
				return (1);
			}
		}
	}
	// Handle an error if getting the executable path fails
	perror("_NSGetExecutablePath");
	return (1);
}
