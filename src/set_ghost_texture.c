/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ghost_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:25:04 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/19 15:25:41 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_ghost_texture(t_game *game, int new_x, int new_y)
{
	int	last_x;
	int	last_y;

	last_x = game->map.ghost.x;
	last_y = game->map.ghost.y;
	if (new_x > last_x)
		game->ghost_texture = RIGHT;
	else if (new_x < last_x)
		game->ghost_texture = LEFT;
	else if (new_y > last_y)
		game->ghost_texture = BACK;
	else if (new_y < last_y)
		game->ghost_texture = TOP;
}
