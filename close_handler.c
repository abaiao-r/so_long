/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:12:38 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/08 17:39:44 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_handler(t_window *window)
{
	free_map(window->map->map, window->map->y);
	mlx_destroy_image(window->mlx_begin, window->sprite->wall);
	mlx_destroy_image(window->mlx_begin, window->sprite->collectible);
	mlx_destroy_image(window->mlx_begin, window->sprite->player);
	mlx_destroy_image(window->mlx_begin, window->sprite->path);
	mlx_destroy_image(window->mlx_begin, window->sprite->exit);
	mlx_clear_window(window->mlx_begin, window->mlx_window);
	mlx_destroy_window(window->mlx_begin, window->mlx_window);
	mlx_destroy_display(window->mlx_begin);
	free(window->sprite);
	free(window->map);
	free(window->mlx_begin);
	free(window);
	exit(0);
	return (1);
}
