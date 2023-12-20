/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:40:38 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/20 10:50:11 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_command_line_arguments(argc, argv);
	init_values(&game);
	init_map(&game);
	check_map(&game);
	init_new_window(&game);
	init_texture(&game);
	render_map(&game);
	mlx_loop_hook(game.mlx_ptr, &move_ghost, &game);
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &handle_input, &game);
	mlx_hook(game.win_ptr, DestroyNotify, ButtonPressMask, &close_game, &game);
	mlx_hook(game.win_ptr, Expose, ExposureMask, &render_map, &game);
	mlx_loop(game.mlx_ptr);
	free_all(&game);
}
