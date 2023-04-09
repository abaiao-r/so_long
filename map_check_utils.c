/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:24:59 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/09 12:12:10 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Funtion to count the lines of the (char **) map.*/
size_t	ft_count_map_lines(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

/* Funtion to count the number of collectible ('C') present int char **map. */
int	number_of_c(char **map)
{
	int	i;
	int	j;
	int	count_colectibles;

	i = 0;
	count_colectibles = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				count_colectibles++;
			}
			j++;
		}
		i++;
	}
	return (count_colectibles);
}

/* Funtion to create a (char **) with the same size as (char **) map. */
char	**map_blank(int y, int x)
{
	char	**map_blank;
	int		i;

	map_blank = (char **)ft_calloc(y, sizeof(char *));
	i = 0;
	while (i < y)
	{
		map_blank[i] = (char *)ft_calloc(x + 1, sizeof(char));
		i++;
	}
	return (map_blank);
}