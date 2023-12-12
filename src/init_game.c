/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:14:24 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/12 14:19:09 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_new_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		error_message("Error getting the mlx-ptr", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1900, 1080, "42 so_long"); //rendre dynamic
	if (!game->win_ptr)
	{
		free(game->mlx_ptr);
		error_message("Fail to open the new window", game);
	}
}

void	init_map(t_game *game)
{
	int		fd;
	char	*line;
	char	*map;

	fd = open("/home/jsarda/Desktop/so_long/map/map.ber", O_RDONLY);
	if (fd == -1)
		error_message("Could not open the map, make sure the map exist", game);
	map = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map.rows++;
		game->map.map_tab = realloc(game->map.map_tab, sizeof(char *)
				* game->map.rows);
		if (game->map.map_tab == NULL)
			error_message("Memory allocation failed", game);
		game->map.map_tab[game->map.rows - 1] = ft_strdup(line);
		free(line);
	}
	close(fd); // Close the file descriptor after reading
}

t_image	new_texture(void *mlx, char *path, t_game *game)
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
	game->wall = new_texture(mlx, WALL_XPM, game);
	game->coins = new_texture(mlx, COINS_XPM, game);
	game->player_right = new_texture(mlx, PLAYER_RIGHT_XPM, game);
	game->player_left = new_texture(mlx, PLAYER_LEFT_XPM, game);
	game->player_top = new_texture(mlx, PLAYER_TOP_XPM, game);
	game->player_back = new_texture(mlx, PLAYER_BACK_XPM, game);
	game->exit_open = new_texture(mlx, EXIT_OPEN_XPM, game);
	game->floor = new_texture(mlx, FLOOR_XPM, game);
	game->exit_close = new_texture(mlx, EXIT_CLOSE_XPM, game);
}
