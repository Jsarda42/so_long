/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:56:08 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/14 11:21:42 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_texture(t_game *game, t_image texture, int rows, int columns)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, texture.xpm_ptr,
		columns * texture.y, rows * texture.x);
}

void	print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->move_count);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 0xFFFFFF, phrase);
	free(movements);
	free(phrase);
}

void	render_player(t_game *game, int y, int x)
{
	if (game->player_texture == TOP)
		render_texture(game, game->player_top, y, x);
	if (game->player_texture == LEFT)
		render_texture(game, game->player_left, y, x);
	if (game->player_texture == RIGHT)
		render_texture(game, game->player_right, y, x);
	if (game->player_texture == BACK)
		render_texture(game, game->player_back, y, x);
}

void	render_ghost(t_game *game, int y, int x)
{
	if (game->ghost_texture == TOP)
		render_texture(game, game->ghost_top, y, x);
	if (game->ghost_texture == LEFT)
		render_texture(game, game->ghost_left, y, x);
	if (game->ghost_texture == RIGHT)
		render_texture(game, game->ghost_right, y, x);
	if (game->ghost_texture == BACK)
		render_texture(game, game->ghost_back, y, x);
}
void	define_texture(t_game *game, int y, int x)
{
	char	parameter;

	parameter = game->map.map_tab[y][x];
	if (parameter == WALL)
		render_texture(game, game->wall, y, x);
	else if (parameter == FLOOR)
		render_texture(game, game->floor, y, x);
	else if (parameter == COINS)
		render_texture(game, game->coins, y, x);
	else if (parameter == EXIT)
	{
		if (game->map.coins_count == 0)
			render_texture(game, game->exit_open, y, x);
		else
			render_texture(game, game->exit_close, y, x);
	}
	else if (parameter == PLAYER)
		render_player(game, y, x);
	else if (parameter == GHOST)
		render_ghost(game, y, x);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			define_texture(game, y, x);
			x++;
		}
		y++;
	}
	print_movements(game);
}
