/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:22 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 19:20:36 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h> 
# include <stdarg.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define DIM 48
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_player
{
	int	position_x;
	int	position_y;
	int	moves_counter;
	int	collectable_counter;
	int	valid_exit;
	int	direction;
}		t_player;

typedef struct s_map
{
	int	moves_counter;
	int	collectable_counter;
}		t_map;

typedef struct s_window
{
	int		x;
	int		y;
	void	*mlx_win;
}			t_window;

typedef struct s_image
{
	void	*img;
	int		img_width;
	int		img_height;
}				t_image;

typedef struct s_game
{
	int			moves_counter;
	int			collectable_counter;
	int			player_checker;
	int			exit_checker;
	int			dfs_collectable_counter;
	int			winning_check;
	char		**map;
	void		*mlx;
	t_image		album[6];
	t_player	player;
	t_window	win;
}		t_game;

typedef struct s_index
{
	int	i;
	int	j;
}			t_index;

int		main(int ac, char **av);
int		file_parser(const char *str);
char	**map_parser(int fd, char **av);
void	check_for_walls(char **map, int map_height);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_get_line(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
int		map_width(char *map_row);
int		map_height(char **map);
void	checker(t_game *game);
char	**dfs_marker(char **map);
void	dfs(t_game *game, char **mark_map, int j, int i);
int		valid_path_check(t_game *game, char **mark_map);
void	free_map(char **map);
void	load_images(t_game *game);
void	imgmsg_loadcheck(t_game *game);
void	destroy_images(t_game *game);
void	ft_draw_map(t_game game);
void	ft_draw_tiles(t_game game);
void	destroy_game_pre(t_game *game);
int		destroy_game_post(t_game *game);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	player_find(t_game *game);
int		move_flag(t_game *game, int i, int j);
void	update_game(t_game *game);
void	error_print_msg_pre_map(int error_num);
void	error_print_msg(int error_num, char **map);
#endif
