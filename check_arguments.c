/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:34:34 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/03 17:53:25 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_name(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' || str[i
			- 3] != '.')
		return (1);
	if (str[0] != 'm' || str[1] != 'a' || str[2] != 'p' || str[3] != 's'
		|| str[4] != '/')
		return (1);
	return (0);
}

int	check_arguments_input(int ac, char **av)
{
	if (ac == 1 || ac > 2)
	{
		ft_printf("Your input on terminal should \
		be: ./so_long maps/<map_name.ber>");
		return (0);
	}
	else if (ac == 2 && check_map_name(av[1]))
	{
		ft_printf("Wrong map name. Map name should be maps/<map_name>.ber");
		return (0);
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