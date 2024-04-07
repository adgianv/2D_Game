/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2024/04/07 20:32:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_collect(t_game *game)
{
	if (game->lost == 0)
	{
		game->collectibles--;
		game->was_coin = 1;
	}
	return (1);
}

int	valid_move(t_game *game, int col, int line, int pressed_key)
{
	// if (game->movement != 0)
	// 	return(-1);
	if ((game->map.map[col][line] == 'X' || game->map.map[col][line] == 'Y' 
	|| game->map.map[col][line] == 'Z'|| game->map.map[col][line] == 'W') && game->lost != 2)
	{
		ft_printf("\n\nYOU lose DUMMY👻\n\n");
		game->lost = 1;
	}
	else if (game->map.map[col][line] == '1')
		return (-1);
	else if (game->map.map[col][line] == 'C')
		return (ft_collect(game));
	else if (game->map.map[col][line] == 'A'
			|| game->map.map[col][line] == 'S' || game->map.map[col][line] == 'K' 
			|| game->map.map[col][line] == 'O')
	{
		game->fruit--;
		return (ft_collect(game));
	}
	else if (game->map.map[col][line] == 'E' && game->collectibles > 0)
		return (-1);
	else if (game->map.map[col][line] == 'E' && game->collectibles == 0)
	{
		ft_printf("\n\nYOU WIN🏆\n\n");
		game->lost = 2;
		game->flag_loss = 2;
	}
	else if (pressed_key != KEY_W && pressed_key != KEY_S
		&& pressed_key != KEY_A && pressed_key != KEY_D
		&& pressed_key != KEY_UP && pressed_key != KEY_DOWN
		&& pressed_key != KEY_LEFT && pressed_key != KEY_RIGHT)
		return (-1);
	return (1);
}

void	switch_player(t_game *game, int prev_col, int prev_line)
{
	game->map.map[game->x_player][game->y_player] = 'P';
	game->map.map[prev_col][prev_line] = '0';
	update_image(game);
	if (game->lost == 0)
		ft_printf("Moves: %d\n", game->move_counter++);
}

int	move_player(t_game *game)
{
	int		valid;
	int		prev_col;
	int		prev_line;
	int 	keycode;
	int		col;
	int		line;

	prev_col = game->x_player;
	prev_line = game->y_player;
	keycode = game->keycode;
	col = game->col;
	line = game->line;
	valid = valid_move(game, col, line, keycode);
	if (valid != -1)
	{
		game->y_player = line;
		game->x_player = col;
		switch_player(game, prev_col, prev_line);
	}
	return (0);
}

int	key_checker (t_game *game)
{
	int	col;
	int	line;
	int keycode;

	col = game->x_player;
	line = game->y_player;
	keycode = game->keycode;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		line--;
	else if (keycode == KEY_W || keycode == KEY_UP)
		col--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		line++;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		col++;
	else if (keycode == 53)
	{
		printf("** EXIT GAME **");
		ft_exit(game);
	}
	if (keycode == KEY_R && (game->lost == 1 || game->lost == 2))
	{
		init_struct(game);
		ft_parse_map(game, game->filename);
		game_init(game);
	}
	game->col = col;
	game->line = line;
	return (0);
}

int	key_handler(int keycode, t_game *game)
{
	game->keycode = keycode;
	return (0);
}
