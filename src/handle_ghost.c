/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ghost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:32:57 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/19 17:22:40 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap_texture(t_game *game, int new_y, int new_x)
{
	int	last_x;
	int	last_y;

	last_x = game->map.ghost.x;
	last_y = game->map.ghost.y;
	set_ghost_texture(game, new_x, new_y);
	if (game->map.map_tab[new_y][new_x] != WALL)
	{
		if (game->map.map_tab[new_y][new_x] == FLOOR)
		{
			game->map.map_tab[new_y][new_x] = GHOST;
			game->map.map_tab[last_y][last_x] = FLOOR;
		}
		else if (game->map.map_tab[new_y][new_x] == COINS)
		{
			game->map.map_tab[new_y][new_x] = GHOST;
			game->map.map_tab[last_y][last_x] = COINS;
		}
		else if (game->map.map_tab[new_y][new_x] == PLAYER)
			loose(game);
		render_map(game);
	}
}

void	update_ghost_movement(t_game *game, int new_y, int new_x)
{
	if (new_y >= 0 && new_y < game->map.rows && new_x >= 0
		&& new_x < game->map.columns && game->map.map_tab[new_y][new_x] != WALL
		&& game->map.map_tab[new_y][new_x] != GHOST)
	{
		swap_texture(game, new_y, new_x);
		game->map.ghost.y = new_y;
		game->map.ghost.x = new_x;
	}
}

void	move_random_direction(t_game *game, int *move_direction)
{
	static int	directions[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int			new_direction;
	int			new_x;
	int			new_y;

	new_direction = *move_direction;
	while (true)
	{
		new_direction = (new_direction + (rand() % 3) + 1) % 4;
		new_x = game->map.ghost.x + directions[new_direction][0];
		new_y = game->map.ghost.y + directions[new_direction][1];
		if (new_x >= 0 && new_x < game->map.columns && new_y >= 0
			&& new_y < game->map.rows
			&& game->map.map_tab[new_y][new_x] != WALL)
			break ;
	}
	*move_direction = new_direction;
	update_ghost_movement(game, new_y, new_x);
	game->map.ghost.y = new_y;
	game->map.ghost.x = new_x;
}

void	move_in_direction(t_game *game, int new_x, int new_y)
{
	if (new_x >= 0 && new_x < game->map.columns && new_y >= 0
		&& new_y < game->map.rows && game->map.map_tab[new_y][new_x] != WALL)
	{
		update_ghost_movement(game, new_y, new_x);
		game->map.ghost.y = new_y;
		game->map.ghost.x = new_x;
	}
}

int	move_ghost(t_game *game)
{
	static clock_t	last_move_time = 0;
	static int		move_direction = RIGHT;
	static int		directions[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int				new_x;
	int				new_y;

	if ((double)(clock() - last_move_time)
		/ CLOCKS_PER_SEC >= MOVEMENT_INTERVAL)
	{
		last_move_time = clock();
		new_x = game->map.ghost.x + directions[move_direction][0];
		new_y = game->map.ghost.y + directions[move_direction][1];
		if (new_x >= 0 && new_x < game->map.columns && new_y >= 0
			&& new_y < game->map.rows && game->map.map_tab[new_y][new_x] != WALL
			&& game->map.map_tab[new_y][new_x] != GHOST)
			move_in_direction(game, new_x, new_y);
		else
			move_random_direction(game, &move_direction);
	}
	return (0);
}
