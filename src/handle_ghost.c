/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ghost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:32:57 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/16 10:52:01 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void set_ghost_texture(t_game *game, int new_x, int new_y) {
    int last_x = game->map.ghost.x;
    int last_y = game->map.ghost.y;

    // Check the direction of movement and set the texture accordingly
    if (new_x > last_x) {
        // Moving right
        game->ghost_texture = RIGHT;
    } else if (new_x < last_x) {
        // Moving left
        game->ghost_texture = LEFT;
    } else if (new_y > last_y) {
        // Moving down
        game->ghost_texture = BACK;
    } else if (new_y < last_y) {
        // Moving up
        game->ghost_texture = TOP;
    }
}
void swap_texture(t_game *game, int new_y, int new_x)
{
	int last_x = game->map.ghost.x;
	int last_y = game->map.ghost.y;
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
		{
			ft_printf("You lose\n");
			// Handle the game-over scenario
		}
		render_map(game);
	}
}


void update_ghost_movement(t_game *game, int new_y, int new_x)
{
	if (new_y >= 0 && new_y < game->map.rows && new_x >= 0 && new_x < game->map.columns && game->map.map_tab[new_y][new_x] != WALL && game->map.map_tab[new_y][new_x] != GHOST)
	{
		swap_texture(game, new_y, new_x);
		game->map.ghost.y = new_y;
		game->map.ghost.x = new_x;
	}
}



void move_random_direction(t_game *game, int *move_direction) 
{
	int directions[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int new_direction;
	int new_x, new_y;
	
	new_direction = *move_direction;
	while (true)
	{
		new_direction = (new_direction + (rand() % 3) + 1) % 4; // Randomly pick a new direction
		new_x = game->map.ghost.x + directions[new_direction][0];
		new_y = game->map.ghost.y + directions[new_direction][1];
		if (new_x >= 0 && new_x < game->map.columns && new_y >= 0 && new_y < game->map.rows &&
			game->map.map_tab[new_y][new_x] != WALL)
			break;
	}
	*move_direction = new_direction;
	update_ghost_movement(game, new_y, new_x);
	game->map.ghost.y = new_y;
	game->map.ghost.x = new_x;
}

void move_in_direction(t_game *game, int new_x, int new_y)
{
	if (new_x >= 0 && new_x < game->map.columns && new_y >= 0 && new_y < game->map.rows &&
		game->map.map_tab[new_y][new_x] != WALL)
	{
		update_ghost_movement(game, new_y, new_x);	
		game->map.ghost.y = new_y;
		game->map.ghost.x = new_x;
	}
}

int move_ghost(t_game *game) {
	static clock_t last_move_time = 0;
	clock_t current_time;
	double time_diff;
	static int move_direction = RIGHT;
	int new_x, new_y;
	
	

	current_time = clock();
	time_diff = (double)(current_time - last_move_time) / CLOCKS_PER_SEC;
	if (time_diff >= MOVEMENT_INTERVAL)
	{
		last_move_time = current_time;
		int directions[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		new_x = game->map.ghost.x + directions[move_direction][0];
		new_y = game->map.ghost.y + directions[move_direction][1];

		if (new_x >= 0 && new_x < game->map.columns && new_y >= 0 && new_y < game->map.rows &&
			game->map.map_tab[new_y][new_x] != WALL && game->map.map_tab[new_y][new_x] != GHOST)
		{
			move_in_direction(game, new_x, new_y);
		}
		else
		{
			move_random_direction(game, &move_direction);
		}
	}
	return (0);
}
