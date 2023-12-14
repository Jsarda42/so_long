/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:14:24 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/14 08:33:24 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to initialise a new window
// the size will depend on the texture size from the map
void	init_new_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game->mlx_ptr);
		error_message("Error getting the mlx-ptr", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns
			* TEXTURE_WIDTH, game->map.rows * TEXTURE_HEIGHT, "42 so_long");
	if (!game->win_ptr)
	{
		free(game->mlx_ptr);
		error_message("Fail to open the new window", game);
	}
}

// function to add new texture with mlx function xpm to image
t_image	new_texture(void *mlx, char *path, t_game *game)
{
	t_image	texture;

	texture.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &texture.x, &texture.y);
	if (!texture.xpm_ptr)
		error_message("Couldn't find any texture.", game);
	return (texture);
}

// function to initialise the texture depending o the parameter of the map
void	init_texture(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = new_texture(mlx, WALL_XPM, game);
	game->coins = new_texture(mlx, COINS_XPM, game);
	game->player_right = new_texture(mlx, PLAYER_RIGHT_XPM, game);
	game->player_left = new_texture(mlx, PLAYER_LEFT_XPM, game);
	game->player_top = new_texture(mlx, PLAYER_TOP_XPM, game);
	game->player_back = new_texture(mlx, PLAYER_BACK_XPM, game);
	game->ghost_right = new_texture(mlx, GHOST_RIGHT_XPM, game);
	game->ghost_left = new_texture(mlx, GHOST_LEFT_XPM, game);
	game->ghost_top = new_texture(mlx, GHOST_TOP_XPM, game);
	game->ghost_back = new_texture(mlx, GHOST_BACK_XPM, game);
	game->exit_open = new_texture(mlx, EXIT_OPEN_XPM, game);
	game->floor = new_texture(mlx, FLOOR_XPM, game);
	game->exit_close = new_texture(mlx, EXIT_CLOSE_XPM, game);
}
