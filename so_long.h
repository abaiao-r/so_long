/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:07:46 by andrefranci       #+#    #+#             */
/*   Updated: 2023/04/10 20:22:16 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include ".minilibx-linux/mlx.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* To find the keycode in linux-> 
cat /usr/include/X11/keysymdef.h and then convert the hexadecimal to decimal*/
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define PX 64

/* map_set */
typedef struct s_map
{
	int			x;
	int			y;
	int			map_is_rectangular;
	int			map_is_enclosed;
	int			map_1_exit;
	int			map_1_start_pos;
	int			map_is_only_01pce;
	int			map_has_colectibles;
	int			number_of_c;
	int			map_goal_exit;
	int			map_goal_c;

	int			p_pos_y;
	int			p_pos_x;

	char		**map;
}				t_map;

typedef struct s_sprite
{
	void		*wall;
	void		*collectible;
	void		*player;
	void		*path;
	void		*exit;
}				t_sprite;

typedef struct s_window
{
	void		*mlx_begin;
	void		*mlx_window;
	t_sprite	*sprite;
	int			nbr_moves;
	t_map		*map;
}				t_window;

/* check_arguments_input */
int				check_arguments_input(int ac, char **av);

/* close_handler */
int				close_handler(t_window *window);
int				no_event(void *window);

/* end_game */
int				end_game(t_window *window, int y, int x);

/* free_memory */
char			**free_map(char **map, int y);
t_map			*free_t_map(t_map *map_set, char error);
int				free_mlx(t_window *window);

/* key_handler */
void			move_right(t_window *window);
void			move_left(t_window *window);
void			move_down(t_window *window);
void			move_up(t_window *window);
int				key_handler(int keycode, t_window *window);

/* map_init.c */
int				ft_count_lines(char *argv);
char			**map_reader(char *argv);
t_map			*map_init(char *argv);

/* map_check */
int				map_1_exit(char **map, t_map *map_set);
int				map_is_enclosed(char **map, t_map *map_set);
int				map_is_rectangular(char **map, t_map *map_set);
int				map_checklist(char **map, t_map *map_set);

/* map_check2 */
int				map_is_only_01pce(char **map, t_map *map_set);
int				map_has_colectibles(char **map, t_map *map_set);
void			map_goal_possible(t_map *map_set, char **map_canvas,
					int p_pos_y, int p_pos_x);

/* map_check_utils */
size_t			ft_count_map_lines(char **map);
int				number_of_c(char **map);
char			**map_blank(int y, int x);

/* sprites_game */
int				open_image(t_window *window);
void			image_selection(t_window *window, int height, int width);
void			add_images_to_game(t_window *window);

#endif
