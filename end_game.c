/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:44:58 by andrefranci       #+#    #+#             */
/*   Updated: 2023/04/06 00:24:18 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_window *window, int y, int x)
{
	if (window->map->map[y][x] == 'C')
		window->map->number_of_c--;
	else if (window->map->map[y][x] == 'E' && window->map->number_of_c > 0)
		return (0);
	else if (window->map->map[y][x] == 'E' && window->map->number_of_c == 0)
	{
		ft_printf("You won!! Game ended in %d moves\n", window->nbr_moves);
		close_handler(window);
	}
	return (1);
}
