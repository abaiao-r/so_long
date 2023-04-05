/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:07 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/06 00:11:28 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_window	*window;

	if (!check_arguments_input(ac, av))
		return (0);
	window = (t_window *)ft_calloc(1, sizeof(t_window));
	if (!window)
		return (0);
	window->map = map_init(av[1]);
	if (!window->map)
	{
		free(window);
		return (0);
	}
	window->mlx_begin = mlx_init();
	if (!window->mlx_begin)
		return (free_mlx(window));
	window->mlx_window = mlx_new_window(window->mlx_begin, (window->map->x - 1)
			* PX, window->map->y * PX, "so_long");
	if (!window->mlx_window)
		return (free_mlx(window));
	if (!open_image(window))
		return (free_mlx(window));
	add_images_to_game(window);
	mlx_hook(window->mlx_begin, 17, 1L << 17, close_handler, window);
	mlx_hook(window->mlx_begin, 2, 1L << 0, key_handler, window);
	mlx_loop(window->mlx_begin);
}
