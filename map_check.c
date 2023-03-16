/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:23:48 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/03/16 15:09:53 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	map_has_1_start_position(char **map)
{
	int	i;
	int	j;
	int	count_start_position;

	i = 0;
	count_start_position = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				count_start_position++;
			j++;
		}
		i++;
	}
	if (count_start_position != 1)
		return (0);
	return (1);
}

int	map_has_1_exit(char **map)
{
	int	i;
	int	j;
	int	count_exit;

	i = 0;
	count_exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count_exit++;
			j++;
		}
		i++;
	}
	if (count_exit != 1)
		return (0);
	return (1);
}

int	map_is_enclosed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (i == 0 || i == ft_count_map_lines(map) - 1)
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
		}
		if (map[i][0] != '1')
			return (0);
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_is_rectangular(char **map)
{
	int	i;
	int	line_lenght;
	int	line_lenght2;

	line_lenght = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		line_lenght2 = ft_strlen(map[i]);
		if (line_lenght2 != line_lenght)
			return (0);
		i++;
	}
	if (i < 3)
		return (0);
	return (1);
}

/* int	map_checklist(char **map)
{
	if (!map_is_rectangular(map))
		return (0);
	if (!map_is_enclosed(map))
		return (0);
	if (!map_has_1_exit(map))
		return (0);
	if (!map_has_1_start_position(map))
		return (0);
	if (!map_has_colectibles(map))
		return (0);
	if (!map_exit_is_possible(map))
		return (0);
	if (!map_colectibles_are_possible(map))
		return (0);
	return (1);
} */

/* main to test map_is_rectangular */
int	main(void)
{
	char *map[] = {
		"11111111", 
		"100000E1", 
		"10P0C001", 
		"11111111"
		};

	printf("map is rectangular: %d \n", map_is_rectangular(map));
	printf("map is enclosed: %d \n", map_is_enclosed(map));
	printf("map has 1 exit: %d \n", map_has_1_exit(map));
	printf("map has 1 start_position: %d \n", map_has_1_start_position(map));
	printf("map has colectibles: %d \n", map_has_colectibles(map));
}
