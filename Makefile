# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 16:08:07 by abaiao-r          #+#    #+#              #
#    Updated: 2023/04/10 15:32:52 by abaiao-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 	check_arguments.c \
		close_handler.c \
		end_game.c \
		free_memory.c \
		key_handler.c \
		map_check.c  \
		map_check2.c \
		map_check_utils.c \
		map_init.c \
		sprites_game.c \
		main.c


#OBJS = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror -g

CC= cc 

RM = rm -rf 



LIBFT_DIR = libft/
LIBFT_INCLUDE = libft

MLX_LIB_DIR = .minilibx-linux/
MLX_INCLUDE = -I mlx_linux
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)
	
$(NAME): $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) bonus
			$(MAKE) -C $(MLX_LIB_DIR)
			$(CC) $(CFLAGS) $(MLX_INCLUDE) $(SRC) libft/libft.a $(MLX_FLAGS) -o $(NAME) -fsanitize=address
clean:	
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(MLX_LIB_DIR) clean

fclean:	clean
				$(RM) $(NAME)
				$(MAKE) -C $(LIBFT_DIR) fclean
				$(MAKE) -C $(MLX_LIB_DIR) clean

re: fclean all
				
.PHONY: all clean fclean re bonus run