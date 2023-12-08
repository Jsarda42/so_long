#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"

# define WALL_XPM	"../texture/wall.xpm"
# define FLOOR_XPM	"../texture/floor.xpm"
# define COINS_XPM	"../texture/coins.xpm"
# define EXIT_OPEN_XPM	"../texute/exit_open.xpm"
# define EXIT_CLOSE_XPM	"../texute/exit_close.xpm"
# define PLAYER_LEFT_XPM	"../texute/player_left.xpm"
# define PLAYER_RIGHT_XPM	"../texute/player_right.xpm"
# define PLAYER_FRONT_XPM	"../texute/player_front.xpm"
# define PLAYER_BACK_XPM	"../texute/player_back.xpm"

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
}	t_map;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
} t_image;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int		player_texture;
	t_map		map;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		exit_open;
	t_image		exit_close;
	t_image		player_left;
	t_image		player_right;
	t_image		player_front;
	t_image		player_back;
}	t_game;

void	init_texture(t_game *game);

# define WALL	'1'
# define FLOOR	'0'
# define COINS	'C'
# define PLAYER	'P'
# define EXIT	'E'

# define PLAYER_FRONT	1
# define PLAYER_BACK	2
# define PLAYER_RIGHT	3
# define PLAYER_LEFT	4

#endif
