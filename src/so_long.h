/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:40:12 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/12 14:04:33 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define WALL_XPM "/home/jsarda/Desktop/so_long/assets/wall.xpm"
# define COINS_XPM "/home/jsarda/Desktop/so_long/assets/coins.xpm"
# define PLAYER_LEFT_XPM "/home/jsarda/Desktop/so_long/assets/player_left.xpm"
# define PLAYER_RIGHT_XPM "/home/jsarda/Desktop/so_long/assets/player_right.xpm"
# define PLAYER_TOP_XPM "/home/jsarda/Desktop/so_long/assets/player_top.xpm"
# define PLAYER_BACK_XPM "/home/jsarda/Desktop/so_long/assets/player_back.xpm"
# define EXIT_OPEN_XPM "/home/jsarda/Desktop/so_long/assets/exit_open.xpm"
# define EXIT_CLOSE_XPM "/home/jsarda/Desktop/so_long/assets/exit_close.xpm"
# define FLOOR_XPM "/home/jsarda/Desktop/so_long/assets/floor.xpm"

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define TEXTURE_WIDTH 32
# define TEXTURE_HEIGHT 32

# define TOP 1
# define BACK 2
# define RIGHT 3
# define LEFT 4

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}			t_image;

typedef struct s_map
{
	char	**map_tab;
	int		columns;
	int		rows;
	int		coins_count;
}			t_map;

typedef struct s_game
{
	void	*win_ptr;
	void	*mlx_ptr;
	int		player_move;
	t_map	map;
	t_image	wall;
	t_image	coins;
	t_image	player_left;
	t_image	player_right;
	t_image	player_top;
	t_image	player_back;
	t_image	exit_open;
	t_image	exit_close;
	t_image	floor;
}			t_game;

void		init_new_window(t_game *game);
void		error_message(char *message, t_game *game);
void		init_texture(t_game *game);
void		init_map(t_game *game);
void		render_map(t_game *game);
char		*ft_strappend(char **s1, const char *s2);
void	init_values(t_game *game);

#endif
