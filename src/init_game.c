/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:14:24 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/10 12:04:31 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_new_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game->mlx_ptr);
		error_message("Error getting the mlx-ptr", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1900, 1080, "42 so_long");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		error_message("Fail to open the new window", game);
	}
}

t_image	new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	texture;

	texture.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &texture.x, &texture.y);
	if (!texture.xpm_ptr)
		error_message("Couldn't find any texture.", game);
	return (texture);
}

void	init_texture(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = new_sprite(mlx, WALL_XPM, game);
	ft_printf("we did it %s", game->wall);
}