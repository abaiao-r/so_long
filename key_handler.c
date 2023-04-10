/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:43:09 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/10 14:04:48 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_window *window)
{
	int	y;
	int	x;

	y = window->map->p_pos_y;
	x = window->map->p_pos_x;
	if ((x + 1 < (window->map->x - 1)) && (window->map->map[y][x + 1] != '1'))
	{
		if (!(end_game(window, y, x + 1)))
			return ;
		window->map->p_pos_x++;
		window->map->map[y][x + 1] = 'P';
		window->map->map[y][x] = '0';
		image_selection(window, y, x);
		image_selection(window, y, x + 1);
		window->nbr_moves++;
		ft_printf("Total of moves:%d\n", window->nbr_moves);
	}
}

void	move_left(t_window *window)
{
	int	y;
	int	x;

	y = window->map->p_pos_y;
	x = window->map->p_pos_x;
	if ((x - 1 > 0) && (window->map->map[y][x - 1] != '1'))
	{
		if (!(end_game(window, y, x - 1)))
			return ;
		window->map->p_pos_x--;
		window->map->map[y][x - 1] = 'P';
		window->map->map[y][x] = '0';
		image_selection(window, y, x);
		image_selection(window, y, x - 1);
		window->nbr_moves++;
		ft_printf("Total of moves:%d\n", window->nbr_moves);
	}
}

void	move_down(t_window *window)
{
	int	y;
	int	x;

	y = window->map->p_pos_y;
	x = window->map->p_pos_x;
	if ((y + 1 < window->map->y) && (window->map->map[y + 1][x] != '1'))
	{
		if (!(end_game(window, y + 1, x)))
			return ;
		window->map->p_pos_y++;
		window->map->map[y + 1][x] = 'P';
		window->map->map[y][x] = '0';
		image_selection(window, y, x);
		image_selection(window, y + 1, x);
		window->nbr_moves++;
		ft_printf("Total of moves:%d\n", window->nbr_moves);
	}
}

void	move_up(t_window *window)
{
	int	y;
	int	x;

	y = window->map->p_pos_y;
	x = window->map->p_pos_x;
	if ((y - 1 > 0) && (window->map->map[y - 1][x] != '1'))
	{
		if (!(end_game(window, y - 1, x)))
			return ;
		window->map->p_pos_y--;
		window->map->map[y - 1][x] = 'P';
		window->map->map[y][x] = '0';
		image_selection(window, y, x);
		image_selection(window, y - 1, x);
		window->nbr_moves++;
		ft_printf("Total of moves:%d\n", window->nbr_moves);
	}
}

int	key_handler(int keycode, t_window *window)
{
	if (keycode == KEY_ESC)
		close_handler(window);
	if (keycode == KEY_UP || keycode == KEY_W)
		move_up(window);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		move_down(window);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		move_left(window);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_right(window);
	return (1);
}
