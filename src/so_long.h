/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:40:12 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/14 10:54:00 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
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
# define GHOST_BACK_XPM "/home/jsarda/Desktop/so_long/assets/ghost_back.xpm"
# define GHOST_LEFT_XPM "/home/jsarda/Desktop/so_long/assets/ghost_left.xpm"
# define GHOST_RIGHT_XPM "/home/jsarda/Desktop/so_long/assets/ghost_right.xpm"
# define GHOST_TOP_XPM "/home/jsarda/Desktop/so_long/assets/ghost_top.xpm"

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define GHOST 'G'

# define TEXTURE_WIDTH 32
# define TEXTURE_HEIGHT 32

# define TOP 1
# define BACK 2
# define RIGHT 3
# define LEFT 4

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_Q 113
# define KEY_ESC 65307

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef enum e_bool
{
	false,
	true
}				t_bool;

typedef struct s_image
{
	void		*xpm_ptr;
	int			x;
	int			y;
}				t_image;

typedef struct s_map
{
	char		**map_tab;
	t_position	player;
	int			players;
	t_position	ghost;
	int			ghosts;
	int			columns;
	int			rows;
	int			coins_count;
}				t_map;

typedef struct s_game
{
	void		*win_ptr;
	void		*mlx_ptr;
	int			player_texture;
	int			move_count;
	int			ghost_texture;
	t_map		map;
	t_image		wall;
	t_image		coins;
	t_image		player_left;
	t_image		player_right;
	t_image		player_top;
	t_image		player_back;
	t_image		exit_open;
	t_image		exit_close;
	t_image		ghost_back;
	t_image		ghost_left;
	t_image		ghost_right;
	t_image		ghost_top;
	t_image		floor;
}				t_game;

void			init_new_window(t_game *game);
void			error_message(char *message, t_game *game);
void			init_texture(t_game *game);
void			init_map(t_game *game);
void			render_map(t_game *game);
void			init_values(t_game *game);
int				handle_input(int keysym, t_game *game);
void			count_map_parameters(t_game *game);
int	handle_ghost_move(t_game *game);

#endif
