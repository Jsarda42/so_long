/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:16:14 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/20 10:42:32 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(char **map, int x, int y)
{
	if (map[y][x] && (map[y][x] != WALL && map[y][x] != VISITED))
	{
		map[y][x] = VISITED;
		floodfill(map, x + 1, y);
		floodfill(map, x, y + 1);
		floodfill(map, x - 1, y);
		floodfill(map, x, y - 1);
	}
}

char	**copy_map(t_game *game)
{
	int		r;
	char	**temp;

	r = 0;
	temp = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!temp)
	{
		free_map(game);
		free(temp);
		error_failure_message("failed to malloc the temp in map parsing");
	}
	while (r < game->map.rows)
	{
		temp[r] = ft_strdup(game->map.map_tab[r]);
		if (!temp[r])
		{
			ft_free(temp);
			free_map(game);
			error_failure_message("failed to malloc the temp in map parsing");
		}
		r++;
	}
	temp[r] = NULL;
	return (temp);
}

void	check_map_elements(char **temp, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (temp[y])
	{
		x = 0;
		while (temp[y][x])
		{
			if (temp[y][x] == COINS || temp[y][x] == EXIT)
			{
				ft_printf("wrong map format\n");
				free_map(game);
				ft_free(temp);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

void	is_path_available(t_game *game)
{
	char	**temp;

	temp = copy_map(game);
	if (!temp)
	{
		free(temp);
		free_map(game);
		error_failure_message("failed to malloc the temp in map parsing");
	}
	floodfill(temp, game->map.player.x, game->map.player.y);
	check_map_elements(temp, game);
	ft_free(temp);
}

void	set_param_rules(t_game *game)
{
	if (game->map.coins_count == 0)
	{
		free_map(game);
		error_failure_message("Error no coins on the map");
	}
	else if (game->map.exit == 0)
	{
		free_map(game);
		error_failure_message("Error no exit on the map");
	}
	if (game->map.players != 1)
	{
		free_map(game);
		error_failure_message("It must be only 1 player");
	}
}
