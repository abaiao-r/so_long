/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:07 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/11 15:09:43 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Notes:
mlx_init() function initializes the connection between the program 
and the graphics system of the computer. It returns a pointer to a 
t_mlx structure, which contains information about the connection 
that was established.

Once mlx_init() has been called, you can use other functions provided 
by the MLX library to create windows, draw shapes, and display images 
on the screen. 

mlx_new_window() is a function provided by the MLX (MiniLibX) library 
in C programming, which creates a new window on the screen.

mlx_hook() is a function provided by the MLX (MiniLibX) library in C 
programming, which is used to register a function to handle a specific 
type of event that occurs in the window (pointer to thw window struct, 
event_type, event_mask, pointer to a function).

mlx_loop() is a function provided by the MLX (MiniLibX) library in C 
programming, which starts an event loop that waits for events to occur 
in the window and calls the appropriate event handlers.
*/
static int	start_game(t_window *window)
{
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
	mlx_hook(window->mlx_window, 17, 1L << 17, close_handler, window);
	mlx_hook(window->mlx_window, 2, 1L << 0, key_handler, window);
	mlx_loop(window->mlx_begin);
	return (0);
}

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
	start_game(window);
}
