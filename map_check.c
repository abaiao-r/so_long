/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:23:48 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/03/07 18:29:55 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *map)
{
	char	*line;
	int		fd1;
	int		i;

	fd1 = open("map.ber", O_RDONLY);
	line = get_next_line(fd1);
	i = 0;
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd1);
	}
	close(fd1);
	return (i);
}

int main (void)
{
	
}
