/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <andi-gia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by andi-gia          #+#    #+#             */
/*   Updated: 2023/07/15 15:59:01 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/Users/user/Desktop/MY CODE/Projects/C/Pacman/get_next_line/get_next_line.h"
# include "/Users/user/Desktop/MY CODE/Projects/C/Pacman/printf/ft_printf.h"
# include "/Users/user/Desktop/MY CODE/Projects/C/Pacman/includes/mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
#include <limits.h>

# define SPRITE_SIZE 16

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_R 15
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125

typedef struct s_map
{
	char	**map_original;
	int		rows;
	int		cols;
	char	**map;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*player;
	void	*exit;
	void	*enemy;
	void	*enemy2;
	void	*enemy3;
	void	*enemy4;
	void	*apple;
	void    *orange;
	void    *cherry;
	void    *strawberry;
	void	*game_over;
	void	*you_win;
}			t_map;

typedef struct s_game
{
	t_map	map;
	int		collectibles;
	int		x_player;
	int		y_player;
	int		counter_calls;
	int		was_exit;
	char	prev_move;
	char	prev_move2;
	char	prev_move3;
	char	prev_move4;
	char	turn;
	int		x_enemy;
	int		x_enemy2;
	int		x_enemy3;
	int		x_enemy4;
	int		y_enemy;
	int		y_enemy2;
	int		y_enemy3;
	int		y_enemy4;
	int		move_counter;
	void	*mlx;
	void	*window;
	int		was_collectible;
	int		was_collectible2;
	int		was_collectible3;
	int		was_collectible4;
	int		keycode;
	int		was_coin;
	int		lost;
	int		counter_loss;
	int		flag_loss;
	char	*filename;
	int		fruit;
	int		panic_counter;
	int		panic;
	int		col;
	int		line;
	int		movement;
}			t_game;

int			move_player(t_game *game);
void		init_struct(t_game *game);
int			key_checker (t_game *game);
void		put_map(t_game *game);
void		put_images(t_game *game);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_valid_name(char *str);
void		ft_parse_map(t_game *game, char *file);
char		*ft_join(char *s1, char *s2);
int			ft_strlen(char *str);
int			key_handler(int keycode, t_game *game);
int			move_enemy(t_game *game);
int			move_enemy_two(t_game *game);
int			move_enemy_three(t_game *game);
int			move_enemy_four(t_game *game);
char		*ft_itoa(int n);
void		ft_exit(t_game *game);
int			ft_moven(t_game *game, int col, int line);
int			ft_movew(t_game *game, int col, int line);
int			ft_movee(t_game *game, int col, int line);
int			ft_moves(t_game *game, int col, int line);
int			ft_moven_two(t_game *game, int col, int line);
int			ft_movew_two(t_game *game, int col, int line);
int			ft_movee_two(t_game *game, int col, int line);
int			ft_moves_two(t_game *game, int col, int line);
int			ft_moven_three(t_game *game, int col, int line);
int			ft_movew_three(t_game *game, int col, int line);
int			ft_movee_three(t_game *game, int col, int line);
int			ft_moves_three(t_game *game, int col, int line);
int			ft_moven_four(t_game *game, int col, int line);
int			ft_movew_four(t_game *game, int col, int line);
int			ft_movee_four(t_game *game, int col, int line);
int			ft_moves_four(t_game *game, int col, int line);
void		switch_position(t_game *game, int col, int line);
void		switch_position2(t_game *game, int col, int line);
void		switch_position3(t_game *game, int col, int line);
void		switch_position4(t_game *game, int col, int line);
void		update_image_enemy(t_game *game, char direction);
void		update_image_enemy2(t_game *game, char direction);
void		update_image_enemy3(t_game *game, char direction);
void		update_image_enemy4(t_game *game, char direction);
void		ft_check(t_game *game);
void		destroy_image(t_game *game);
void		update_image(t_game *game);
void		check_shape(t_game *game);
int			chase_player(t_game *game);
int			chase_player2(t_game *game);
int			chase_player3(t_game *game);
int			chase_player4(t_game *game);
int			valid(t_game *game, int col, int line);
void		close_pacman(t_game *game);
void		ft_you_lose(t_game *game);
void		game_init(t_game *game);
void		update_img_win(t_game *game);
void		update_img_loss(t_game *game);
void		ft_you_lose(t_game *game);
void		ft_you_win(t_game *game);
void		ft_exit(t_game *game);
int			close_game(void);
#endif
