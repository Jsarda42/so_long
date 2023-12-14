/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ghost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:44:59 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/14 15:53:20 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>
#define GHOST_MOVE_INTERVAL 500

void	ghost_move(t_game *game, int new_y, int new_x)
{
	game->map.map_tab[game->map.ghost.y][game->map.ghost.x] = FLOOR;
	game->map.map_tab[new_y][new_x] = GHOST;
	game->map.ghost.y = new_y;
	game->map.ghost.x = new_x;
	render_map(game);
}

int	check_available_paths(t_game *game, int y, int x)
{
	int	up;
	int	down;
	int	left;
	int	right;

	up = (game->map.map_tab[y - 1][x] != WALL);
	down = (game->map.map_tab[y + 1][x] != WALL);
	left = (game->map.map_tab[y][x - 1] != WALL);
	right = (game->map.map_tab[y][x + 1] != WALL);
	if (up)
		return (0);
	if (down)
		return (1);
	if (left)
		return (2);
	if (right)
		return (3);
	return (4);
}


int	handle_ghost_move(t_game *game)
{
	static clock_t	last_move_time = 0;
	clock_t			current_time;
	double			time_diff;
	int				last_y;
	int				last_x;
	int				available_paths;

	current_time = clock();
	time_diff = (double)(current_time - last_move_time) / CLOCKS_PER_SEC;
	last_y = game->map.ghost.y;
	last_x = game->map.ghost.x;
	if (time_diff >= ((double)GHOST_MOVE_INTERVAL / 1000))
	{
		available_paths = check_available_paths(game, last_y, last_x);
		if (available_paths >= 0 && available_paths <= 3)
		{
		}
		last_move_time = current_time;
		return (1);
	}
	return (0);
}
