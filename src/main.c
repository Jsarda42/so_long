/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:40:38 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/13 17:22:06 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	game;

	init_values(&game);
	init_map(&game);
	init_new_window(&game);
	init_texture(&game);
	count_map_parameters(&game);
	render_map(&game);
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &handle_input, &game);
	mlx_loop(game.mlx_ptr);
}
