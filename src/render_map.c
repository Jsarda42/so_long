/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:23:24 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/08 12:02:08 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_texture(t_game *game, t_image texture, int line, int column)
{
	mlx_put_image_to_window(game->mlx->ptr, game->win_ptr, image->xpm_ptr,
		column * texture->x, line * texture->y);
}

void	render_player(t_game *game, int y, int x)
{
	if (player_texture == PLAYER_FRONT)
		render_texture(game, game->player_front, y, x);
	if (player_texture == PLAYER_BACK)
		render_texture(game, game->player_back, y, x);
	if (player_texture == PLAYER_LEFT)
		render_texture(game, game->player_left, y, x);
	if (player_texture == PLAYER_RIGHT)
		render_texture(game, game->player_right, y, x);
}

void	check_texture(t_game *game, int y, int x)
{
	char	param;

	param = game->map.full[y][x];
	if (param == WALL)
		render_texture(game, game->wall, y, x);
	else if (param == FLOOR)
		render_texture(game, game->floor, y, x);
	else if (param == COINS)
		render_texture(game, game->coins, y, x);
	else if (param == PLAYER)
		render_player(game, y, x);
	else if (param == EXIT)
	{
		if (game->map.coins == 0)
			render_texture(game->exit_open);
		else
			render_texture(game->exit_close);
	}
}

int	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.column)
		{
			check_texture(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
