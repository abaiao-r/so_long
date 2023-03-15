/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:23:48 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/03/15 17:49:57 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_checklist(char **map)
{
    if(!map_is_rectangular(map))
        return (0);
    if(!map_is_enclosed(map))
        return(0);
    if(!map_has_1_exit(map))
        return(0);
    if (!map_has_1_start_position(map))
        return(0);
    if(!map_has_colectibles(map))
        return(0);
    if(!map_exit_is_possible(map))
        return(0);
    if(!map_colectibles_are_possible(map))
        return(0);
    return(1);
}

