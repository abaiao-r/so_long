/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:47:26 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/03/16 18:08:36 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_only_01pce(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_has_colectibles(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* int	map_exit_is_possible(char **map, t_map size, t_map pos, char target)
{
	char	replacement;

	replacement = ;
	if (pos.y < 0 || pos.y >= size.y || pos.x < 0 || pos.x >= size.x
		|| tab[pos.y][pos.x] != target, replacement)
		return ;
	tab[pos.y][pos.x] = 'F';
	map_exit_is_possible(tab, size, (t_map){pos.x - 1, pos.y}, target,
			replacement);
	map_exit_is_possible(tab, size, (t_map){pos.x + 1, pos.y}, target,
			replacement);
	map_exit_is_possible(tab, size, (t_map){pos.x, pos.y - 1}, target,
			replacement);
	map_exit_is_possible(tab, size, (t_map){pos.x, pos.y + 1}, target,
			replacement);
} */
