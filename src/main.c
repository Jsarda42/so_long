/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:40:38 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/10 11:26:55 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
		error_message("Malloc failed allocation", game);
	init_new_window(game);
	init_texture(game);
	mlx_loop(game->mlx_ptr);
}