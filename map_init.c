/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:49:22 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/03/16 18:54:14 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(char *argv)
{
	char	*line;
	int		fd1;
	int		i;

	fd1 = open(argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd1);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd1);
	}
	free(line);
	close(fd1);
	return (i);
}

char	**map_reader(char *argv)
{
	char	**map;
	int		number_of_lines;
	int		fd1;
	int		i;

	number_of_lines = ft_count_lines(argv);
	map = (char **)ft_calloc(number_of_lines, sizeof(char *));
	if (!map)
		return (0);
	fd1 = open(argv, O_RDONLY);
	i = 0;
	while (i < number_of_lines)
	{
		map[i] = get_next_line(fd1);
		i++;
	}
	close(fd1);
	return (map);
}

t_map	*init_map(char *argv)
{
	t_map	*map_characteristics;

	map_characteristics = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map_characteristics)
		return (0);
	map_characteristics->map = map_reader(argv);
	if (!map_characteristics->map)
		return (0);
	map_characteristics->y = ft_count_lines(argv);
	map_characteristics->x = ft_strlen(map_characteristics->map[0]);
	map_checklist(map_characteristics->map);
	

}

/* main to test map_reader */
/* int main(int argc, char **argv)
{
    (void) argc;
    char **temp;
    int i;

    i = 0;
    temp = map_reader(argv[1]);
    while (i < 3)
    {
        printf("%s\n", temp[i]);
        i++;
    }
} */

/* main to test ft_count_lines */
/* int main(int argc, char **argv)
{
    (void)argc;
    printf("%d", ft_count_lines(argv[1]));
} */