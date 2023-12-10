/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:40:12 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/10 11:46:12 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
#include <fcntl.h>

# define WALL_XPM	"../assets/wall.xpm"
# define FLOOR_XPM	"../texture/floor.xpm"
# define COINS_XPM	"../texture/coins.xpm"
# define EXIT_OPEN_XPM	"../texute/exit_open.xpm"
# define EXIT_CLOSE_XPM	"../texute/exit_close.xpm"
# define PLAYER_LEFT_XPM	"../texute/player_left.xpm"
# define PLAYER_RIGHT_XPM	"../texute/player_right.xpm"
# define PLAYER_FRONT_XPM	"../texute/player_front.xpm"
# define PLAYER_BACK_XPM	"../texute/player_back.xpm"

typedef struct s_image
{
	void	*xpm_ptr;
	int	x;
	int	y;
} t_image;


typedef struct s_game
{
	void *win_ptr;
	void *mlx_ptr;
	t_image	wall;
} t_game;

void	init_new_window(t_game *game);
void	error_message(char *message, t_game *game);
void	init_texture(t_game *game);

#endif
