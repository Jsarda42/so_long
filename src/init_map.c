/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:47:02 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/12 17:49:37 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game)
{
	int		fd;
	char	*line;
	char	*map;

	fd = open("/home/jsarda/Desktop/so_long/map/map.ber", O_RDONLY);
	if (fd == -1)
		error_message("Could not open the map, make sure the map exist", game);
	map = ft_strdup("");
	if (!map)
		error_message("failed to strdup", game);
	game->map.rows = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = ft_strtrim(line, "\n");
		game->map.rows++;
		game->map.map_tab = realloc(game->map.map_tab, sizeof(char *)
				* game->map.rows);
		if (game->map.map_tab == NULL)
			error_message("Memory allocation failed", game);
		game->map.map_tab[game->map.rows - 1] = ft_strdup(map);
		free(line);
		free(map);
	}
	close(fd);
}
