/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 07:21:11 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/14 08:39:08 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to get the position of the player on the map.
// Keep count on number of player (later on will
// make sure we can use the map.players == 1 in parsing)
// getting the coins count as well
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
			if (game->map.map_tab[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			if (game->map.map_tab[y][x] == GHOST)
			{
				game->map.ghosts++;
				game->map.ghost.x = x;
				game->map.ghost.y = y;
			}
			if (game->map.map_tab[y][x] == COINS)
				game->map.coins_count++;
			x++;
		}
		y++;
	}
}
