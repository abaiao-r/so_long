/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:07 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/03 17:04:24 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_window *window;

	if (!check_arguments_input(ac, av))
		return (0);
	window = (t_window *)ft_calloc(1, sizeof(t_window));
	if (!window)
		return (0);
	window->map = map_init(av[1]);
	if (window == NULL)
	{
		printf("Error: map_init returned NULL\n");
		return (1);
	}
	window->mlx_begin = mlx_init();
    if(!window->mlx_begin)
    {

        return(0);
    }
    window->mlx_window = mlx_new_window(window->mlx_begin, window->map->x * PX, window->map->y * PX, "so_long");
    /* if(!window->mlx_window)
        return(); */
	free_t_map(window->map, ' ');
	return (0);

}