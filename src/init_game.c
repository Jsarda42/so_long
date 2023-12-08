/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:50:54 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/08 15:08:42 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	new_texture(void *mlx, char *path, t_game *game)
{
	t_image	texture;

	texture.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &texture.x, &texture.y);
	if (texture.xpm_ptr == NULL)
		ft_error_msg("Couldn't find a sprite. Does it exist?", game);
	return (texture);
}

void	init_texture(t_game *game)
{
	void	*mlx;
	mlx = game->mlx_ptr;
	game->wall = new_texture(mlx, game, WALL_XPM);
	game->floor = new_texture(mlx, game, FLOOR_XPM);
	game->coins = new_texture(mlx, game, COINS_XPM);
	game->exit_open = new_texture(mlx, game, EXIT_OPEN_XPM);
	game->exit_close = new_texture(mlx, game, EXIT_CLOSE_XPM);
	game->player_left = new_texture(mlx, game, PLAYER_LEFT_XPM);
	game->player_right = new_texture(mlx, game, PLAYER_RIGHT_XPM);
	game->player_front = new_texture(mlx, game, PLAYER_FRONT_XPM);
	game->player_back = new_texture(mlx, game, PLAYER_BACK_XPM);
}

