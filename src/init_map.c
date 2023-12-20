/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:47:02 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/20 10:34:54 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_error_1(t_game *game, char *trimmed_line)
{
	free(game->map.map_tab);
	free(trimmed_line);
	error_failure_message("Memory allocation failed in init_map 1");
}

void	malloc_error_2(t_game *game, char *trimmed_line, int i)
{
	free(game->map.map_tab[i]);
	free(game->map.map_tab);
	free(trimmed_line);
	error_failure_message("Fail to strdup game->map.map_tab[i]");
}

static void	malloc_game_tab_3(t_game *game)
{
	game->map.map_tab = malloc(sizeof(char *) * game->map.rows);
	if (!game->map.map_tab)
	{
		free(game->map.map_tab);
		error_failure_message("Memory allocation failed in init_map");
	}
}

void	allocate_map_tab(t_game *game, int fd)
{
	int		i;
	char	*line;
	char	*trimmed_line;

	malloc_game_tab_3(game);
	i = -1;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		trimmed_line = ft_strtrim(line, "\n");
		free(line);
		if (!trimmed_line)
			malloc_error_1(game, trimmed_line);
		if (++i < game->map.rows)
		{
			game->map.map_tab[i] = ft_strdup(trimmed_line);
			if (!game->map.map_tab[i])
				malloc_error_2(game, trimmed_line, i);
			game->map.columns = (int)ft_strlen(trimmed_line);
			free(trimmed_line);
		}
	}
}

void	init_map(t_game *game)
{
	int	fd;

	fd = open("/home/jsarda/Desktop/so_long/map/map.ber", O_RDONLY);
	if (fd == -1)
		error_failure_message("Could not open the map make sure the map exist");
	allocate_map_tab(game, fd);
	close(fd);
}
