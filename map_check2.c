/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:47:26 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/03/21 21:37:02 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_only_01pce(char **map, t_map *map_set)
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
	map_set->map_is_only_01pce = 1;
	return (1);
}

int	map_has_colectibles(char **map, t_map *map_set)
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
			{
				map_set->map_has_colectibles = 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	map_goal_possible(t_map *map_set, char **map_canvas, int p_pos_y,
		int p_pos_x)
{
	if (!(p_pos_y >= 0 && p_pos_y < map_set->y && p_pos_x >= 0
			&& p_pos_x < map_set->x))
		return ;
	if (map_set->map[p_pos_y][p_pos_y] == '1')
		return ;
	if (map_canvas[p_pos_y][p_pos_y] == '1')
		return ;
	if (map_set->map[p_pos_y][p_pos_x] == 'E')
	{
		map_set->map_goal_exit = 1;
		return ;
	}
	if (map_set->map[p_pos_y][p_pos_x] == 'C'
		&& map_canvas[p_pos_y][p_pos_x] != '1')
		map_set->map_goal_c++;
	map_canvas[p_pos_y][p_pos_x] = '1';
	map_goal_possible(map_set, map_canvas, p_pos_y + 1, p_pos_x);
	map_goal_possible(map_set, map_canvas, p_pos_y, p_pos_x + 1);
	map_goal_possible(map_set, map_canvas, p_pos_y - 1, p_pos_x);
	map_goal_possible(map_set, map_canvas, p_pos_y, p_pos_x - 1);
	return ;
}

/* bool is_valid(int map_set->y, int map_set->x)
{
	return()
}
int	map_exit_is_possible(char **map, t_map size, t_map pos, char target)
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
