/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:49:22 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/09 12:49:43 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* static void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 23)
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
} */

/* Overall, the "ft_count_lines" function counts the number of 
lines in a file by using "get_next_line" to read each line of 
the file and incrementing a counter until the end of the file is reached. */
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

/* Overall, the "map_reader" function reads a map from a file and 
returns a 2D char array with the contents of the file.
It adds a NULL pointer to the end of the "map"*/
char	**map_reader(char *argv)
{
	char	**map;
	int		number_of_lines;
	int		fd1;
	int		i;

	number_of_lines = ft_count_lines(argv);
	map = (char **)ft_calloc(number_of_lines + 1, sizeof(char *));
	if (!map)
		return (0);
	fd1 = open(argv, O_RDONLY);
	if (fd1 < 0 || fd1 > 4096)
		return (0);
	i = 0;
	while (i < number_of_lines)
	{
		map[i] = get_next_line(fd1);
		i++;
	}
	map[i] = NULL;
	close(fd1);
	return (map);
}

/* Overall, the "map_init" function initializes a "t_map" struct 
by reading the map from a file, checking if it is valid, exploring 
the map to check if certain goals are possible, and returns a 
pointer to the initialized "t_map" struct. */
t_map	*map_init(char *argv)
{
	t_map	*map_set;
	char	**map_canvas;

	map_set = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map_set)
		return (0);
	map_set->map = map_reader(argv);
	if (!map_set->map)
	{
		free(map_set);
		free(map_set->map);
		return (0);
	}
	map_set->y = ft_count_lines(argv);
	map_set->x = ft_strlen(map_set->map[0]);
	if (!map_checklist(map_set->map, map_set))
		return (0);
	map_set->number_of_c = number_of_c(map_set->map);
	map_canvas = map_blank(map_set->y, map_set->x);
	map_goal_possible(map_set, map_canvas, map_set->p_pos_y, map_set->p_pos_x);
	free_map(map_canvas, map_set->y);
	if (!(map_set->map_goal_exit)
		|| !(map_set->map_goal_c == map_set->number_of_c))
		return (free_t_map(map_set, 'e'));
	return (map_set);
}

/* main to test map_reader */
/* int main(int argc, char **argv)
{
    char **temp;
    int i;

    (void) argc;
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

/* int	main(int argc, char **argv)
{
	t_map	*gps;
	int		i;

	if (!check_arguments_input(argc, argv))
		return (0);
	gps = map_init(argv[1]);
	if (gps == NULL)
	{
		printf("Error: map_init returned NULL\n");
		return (1);
	}
	printf("Map dimensions: %dy by %dx\n", gps->y, gps->x);
	printf("Player start position: %dy by %dx\n", gps->p_pos_y, gps->p_pos_y);
	printf("Number of colectibles: %d\n", gps->number_of_c);
	printf("Map is rectangular: %d\n", gps->map_is_rectangular);
	printf("Map is enclosed: %d\n", gps->map_is_enclosed);
	printf("Map has 1 exit: %d\n", gps->map_1_exit);
	printf("Map has 1 start position: %d\n", gps->map_1_start_pos);
	printf("Map has only 01PCE: %d\n", gps->map_is_only_01pce);
	printf("Map has collectibles: %d\n", gps->map_has_colectibles);
	printf("Map exit is possible: %d\n", gps->map_goal_exit);
	printf("Map collectibles are possible: %d\n\n", gps->map_goal_c);
	i = 0;
	while (i < gps->y)
	{
		printf("%s", gps->map[i]);
		i++;
	}
	free_t_map(gps, ' ');
	return (0);
} */
