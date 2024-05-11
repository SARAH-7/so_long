/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:22 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/11 18:49:17 by sbakhit          ###   ########.fr       */
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

typedef	struct s_player
{
	int	x;
	int	y;
	int	moves_counter;
	int	collectable_counter;
	int	valid_exit;
	
}		t_player;

typedef	struct	s_map
{
	int	moves_counter;
	int	collectable_counter;
}		t_map;

typedef	struct s_game
{
	int	moves_counter;
	int	collectable_counter;
	int	player_checker;
	int	collectable_checker;
	int	exit_checker;
	char **map;
	t_player	player;
}		t_game;
    
// typedef	struct	s_window
// {
	
// }		t_window;


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
#endif
