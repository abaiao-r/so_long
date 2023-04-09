/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:26:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/09 14:37:08 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* The purpose of this function is to deallocate the memory that was 
previously allocated for a 2D array to avoid memory leaks.  
First frees all the rows, it then frees the memory allocated for the matrix
 itself using "free" on the pointer to the matrix. Finally, it sets the 
pointer to the matrix to NULL to prevent any further use of the freed memory.*/
char	**free_map(char **map, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (map);
}

/* The free_t_map function frees the memory allocated to the map stored 
inside t_map and frees the memory of t_map. Then returns a null pointer 
while printing an error message based on the error argument passed to it. */
t_map	*free_t_map(t_map *map_set, char error)
{
	free_map(map_set->map, map_set->y);
	free(map_set);
	map_set = NULL;
	if (error == 'a')
		ft_printf("Error: Map isn't rectangular\n");
	if (error == 'b')
		ft_printf("Error: Map isn't enclosed by walls\n");
	if (error == 'c')
		ft_printf("Error: Player start position or map exit \
is different than 1.\n");
	if (error == 'd')
		ft_printf("Error:  Map doesn't have collectibles or \
map has an invalid	element(!01PCE)\n");
	if (error == 'e')
		ft_printf("Error:  Is not possible for the the player \
to reach all collectibles and the exit\n");
	return (map_set);
}

/* It first frees the memory for the game map, and then checks if 
the window has been initialized before clearing and destroying it 
using the MLX library. Next, it frees the memory for the game sprites, 
the map, the MLX library, and finally, the entire window. 

mlx_clear_window is a function that clears the contents of a window 
in a graphical application using the MiniLibX library.

mlx_destroy_window: This function is used to destroy a given window 
and free any associated resources. */
/* int	free_mlx(t_window *window)
{
	free_map(window->map->map, window->map->y);
	if (!window->mlx_begin && !window->mlx_window)
	{
		mlx_clear_window(window->mlx_begin, window->mlx_window);
		mlx_destroy_image(window->mlx_begin,  );
		mlx_destroy_window(window->mlx_begin, window->mlx_window);
	}
	free(window->sprite);
	free(window->map);
	free(window->mlx_begin);
	free(window);
	exit(0);
	return (1);
} */
int	free_mlx(t_window *window)
{
	free_map(window->map->map, window->map->y);
	if (window->mlx_begin && window->mlx_window)
	{
		mlx_clear_window(window->mlx_begin, window->mlx_window);
		mlx_destroy_image(window->mlx_begin, window->sprite->wall);
		mlx_destroy_image(window->mlx_begin, window->sprite->collectible);
		mlx_destroy_image(window->mlx_begin, window->sprite->player);
		mlx_destroy_image(window->mlx_begin, window->sprite->path);
		mlx_destroy_image(window->mlx_begin, window->sprite->exit);
		mlx_destroy_window(window->mlx_begin, window->mlx_window);
	}
	free(window->sprite);
	free(window->map);
	free(window->mlx_begin);
	free(window);
	exit(0);
}
