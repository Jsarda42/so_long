/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:52:49 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/10 11:05:15 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *message, t_game *game)
{
	free(game);
	ft_printf("%s\n", message);
	exit (EXIT_FAILURE);
}