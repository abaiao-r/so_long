/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:26:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/03/21 23:17:41 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_map(char **map, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(map[i]);
		i++;
	}
	map = NULL;
	return (map);
}

t_map	*free_t_map(t_map *map_set, char error)
{
	free_map(map_set->map, map_set->y);
	free(map_set);
	map_set = NULL;
	if (error == 'a')
		ft_printf("Error: Map isn't rectangular\n");
	if (error == 'b')
		ft_printf("Error: Map isn't enclosed by walls\n");
	if (error == 'c')
		ft_printf("Error: Player start position or map exit \
         is different than 1.\n");
	if (error == 'd')
		ft_printf("Error:  Map does not have collectibles or \
        have and invalid element(!01PCE)\n");
	if (error == 'e')
		ft_printf("Error:  Is not possible for the the player \
        to reach all collectibles and the exit\n");
	return (map_set);
}
