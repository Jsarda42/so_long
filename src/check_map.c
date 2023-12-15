/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 07:21:11 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/15 16:42:36 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map_parameters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01G", game->map.map_tab[y][x]))
				error_message("Invalid map parameter only CEP01");
			if (game->map.map_tab[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.map_tab[y][x] == COINS)
				game->map.coins_count++;
			else if (game->map.map_tab[y][x] == EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.map_tab[i][0] != WALL)
			error_message("Invalid Map the map need to be sourounded by walls");
		else if (game->map.map_tab[i][game->map.columns - 1] != WALL)
			error_message("Invalid Map the map need to be sourounded by walls");
		i++;
	}
}

void	check_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.map_tab[0][i] != WALL)
			error_message("Invalid Map the map need to be sourounded by walls");
		else if (game->map.map_tab[game->map.rows - 1][i] != WALL)
			error_message("Invalid Map the map need to be sourounded by walls");
		i++;
	}
}

void	set_param_rules(t_game *game)
{
	if (game->map.coins_count == 0)
		error_message("Error no coins on the map");
	else if (game->map.exit == 0)
		error_message("Error no exit on the map");
	if (game->map.players != 1)
		error_message("It must be only 1 player");
}

void	check_map(t_game *game)
{
	check_columns(game);
	check_rows(game);
	count_map_parameters(game);
	set_param_rules(game);
}
