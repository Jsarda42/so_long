/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:42:56 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/19 14:18:53 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	free_all(game);
	exit(EXIT_SUCCESS);
}

int	victory(t_game *game)
{
	free_all(game);
	ft_printf("\n\
BBBBB    RRRRR       A    V       V   OOOOO\n\
B    B   R    R    A  A    V     V   O     O\n\
BBBBB    RRRRR    AAAAAA    V   V    O     O\n\
B    B   R   R    A    A     V V     O     O\n\
BBBBB    R    R   A    A      V       OOOOO\n\
");
	exit (EXIT_SUCCESS);
}

int	loose(t_game *game)
{
	free_all(game);
	ft_printf("\n\
L       OOOO    SSSS   EEEEE\n\
L      O    O   S      E\n\
L      O    O    SSS   EEEE\n\
L      O    O       s  E\n\
LLLLL   OOOO    SSSS   EEEEE\n\
");
	exit (EXIT_SUCCESS);
}
