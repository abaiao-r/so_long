/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:26:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/03/21 21:47:39 by andrefranci      ###   ########.fr       */
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
	if (error == 'r')
		ft_printf("Error: Map is not a rectangule\n");
	if (error == 'w')
		ft_printf("Error: Map is not enclosed by walls\n");
	if (error == 'p')
		ft_printf("Error: Is not possible for the player \
            reach all collectibles and the exit\n");
	return (map_set);
}