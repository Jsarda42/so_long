/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:52:49 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/13 16:40:57 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *message, t_game *game)
{
	free(game);
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	get_rows_len(t_game *game)
{
	int		fd;
	char	*line;

	fd = open("/home/jsarda/Desktop/so_long/map/map.ber", O_RDONLY);
	if (fd == -1)
		error_message("Could not open the map, make sure the map exist", game);
	game->map.rows = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map.rows++;
	}
	close(fd);
}

void	init_values(t_game *game)
{
	get_rows_len(game);
	game->player_move = RIGHT;
	game->map.coins_count = 0;
}
