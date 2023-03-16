/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:07:46 by andrefranci       #+#    #+#             */
/*   Updated: 2023/03/16 15:09:39 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* map coordinates */
typedef struct s_map
{
	int		x;
	int		y;
	int		map_is_rectangular;
	int		map_is_enclosed;
	int		map_has_1_exit;
	int		map_has_1_start_position;
	int		map_has_colectibles;

	char	**map;
}			t_map;

/* check_arguments_input */
int			check_map_name(char *str);
int			check_arguments_input(int ac, char **av);

/* map_init.c */
int			ft_count_lines(char *argv);
char		**map_reader(char *argv);

/* map_check */
int			map_has_1_exit(char **map);
int			map_is_enclosed(char **map);
int			map_is_rectangular(char **map);
int			map_checklist(char **map);

/* map_check2 */
int			map_has_colectibles(char **map);

/* map_check_utils */
int			ft_count_map_lines(char **map);

#endif
