/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:53:33 by juliensarda       #+#    #+#             */
/*   Updated: 2023/12/07 20:35:19 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int collectables = 0;
int	exit = 0;

int	all_Collectables_Collected(int total_collectables) // i need to get the total_collectables while reading the map(with gnl)
{
	if (collectables == total_collectables)
		return (1);
	else
		return (0);
}

int check_adjacent_directions(int player_x, int player_y) 
{
	if (canMoveUp(player_x, player_x) || canMoveDown(player_x, player_x) || canMoveLeft(player_x, player_x) || canMoveRight(player_x, player_x))
		return (1);
	else
		return (0);
}

int	check_Map_Validity(char current_position, int total_collectables)
{
	if (all_Collectables_Collected(total_collectables))
	{
		exit = 1;
		return (1);
	}
	if (current_position == 'W')
		return (0);
	if (current_position == 'C')
		collectables++;
	if (current_position == 'E' && exit == 1)
		return (1);
	if (check_adjacent_directions())
		return 1;
	return 0;
}

