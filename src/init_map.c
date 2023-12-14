/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:47:02 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/14 07:51:05 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// need to adds arguments instead of path
void	init_map(t_game *game)
{
	int		fd;
	char	*line;
	char	*trimmed_line;
	int		i;

	fd = open("/home/jsarda/Desktop/so_long/map/map.ber", O_RDONLY);
	if (fd == -1)
		error_message("Could not open the map, make sure the map exist", game);
	game->map.map_tab = malloc(sizeof(char *) * game->map.rows);
	if (!game->map.map_tab)
	{
		free(game->map.map_tab);
		error_message("Memory allocation failed", game);
	}
	i = -1;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		trimmed_line = ft_strtrim(line, "\n");
		if (++i < game->map.rows)
		{
			game->map.map_tab[i] = ft_strdup(trimmed_line);
			game->map.columns = (int)ft_strlen(trimmed_line);
		}
	}
	close(fd);
}

// need a function to check the arguments validity
// make parsing for the map
