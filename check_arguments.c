/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:34:34 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/10 15:18:54 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Funtion returns a 0 if the terminal input to run the program is wrong.
It checks if the number of arguments is 2.
Then checks if the second argument first 4 characters are
/maps and the last 4 are .ber*/
int	check_arguments_input(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("Your input on terminal should \
be: ./so_long maps/<map_name>.ber");
		return (0);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			ft_printf("File %s does not exist: %s\n", av[1], strerror(errno));
			return (0);
		}
		close(fd);
	}
	return (1);
}

/* main to test check_arguments_input */
/* int main(int ac, char **av)
{
    (void) ac;
    (void) av;

    if(!check_arguments_input(ac, av))
        return(0);        
} */