/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:52:49 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/12 16:31:02 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *message, t_game *game)
{
	free(game);
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	init_values(t_game *game)
{
	game->map.columns = ft_strlen((game->map.map_tab[0]));
	ft_printf("this is the len of my columns : %d\n", game->map.columns);
	game->map.coins_count = 0;
	game->player_move = RIGHT;
}
