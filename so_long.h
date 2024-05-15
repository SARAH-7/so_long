/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:22 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/15 21:59:59 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h> 
# include <stdarg.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# define DIM 48
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

typedef	struct s_player
{
	int	position_x;
	int	position_y;
	int	collectable_checker;
	int	moves_counter;
	int	collectable_counter;
	int	valid_exit;
	int	direction;
	
}		t_player;

typedef	struct	s_map
{
	int	moves_counter;
	int	collectable_counter;
}		t_map;

typedef struct s_window {
	int		x;
	int		y;
	void	*mlx_win;
}			t_window;

typedef	struct s_game
{
	int		moves_counter;
	int		collectable_counter;
	int		player_checker;
	int		collectable_checker;
	int		exit_checker;
	int		dfs_collectable_counter;
	int		winning_check;
	char	**map;
	void	*mlx;
	t_player	player;
	t_window	win;
}		t_game;

typedef struct s_index {
	int	i;
	int	j;
}			t_index;

int	main(int ac, char **av);
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
int	file_parser(char *str);
char **map_parser(int fd);
char	*get_next_line(int fd);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_get_line(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
int		map_width(char *map_row);
int		map_height(char **map);
void	elements_checker(t_game *game);
char	**dfs_marker(char **map);
void	dfs(t_game *game, char **mark_map, int j, int i);
int	valid_path_check(t_game game, char **mark_map);
void	free_map(char **map);
#endif
