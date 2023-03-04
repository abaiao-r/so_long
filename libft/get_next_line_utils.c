/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:17:52 by andrefranci       #+#    #+#             */
/*   Updated: 2023/03/03 15:48:11 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	stash_organizer(char *stash)
{
	int	i;
	int	j;
	int	isnewline;

	i = 0;
	j = 0;
	isnewline = 0;
	while (stash[i])
	{
		if (isnewline)
		{
			stash[j++] = stash[i];
		}
		if (stash[i] == '\n')
		{
			isnewline = 1;
		}
		stash[i++] = '\0';
	}
	return (isnewline);
}

//main para testar stash_organizer
/* int main (void)
{
	char stash[] = "\0André\nFrancis\0co";
	printf ("%i", stash_organizer(stash));
	printf("%s", stash);
} */
//main para testar ft_strjoin
/* int	main(void)
{
	char	str1[] = "Andre";
	char	str2[] = "Francisco";

	printf("ft_strjoin %s\n", ft_strjoin(str1, str2));
} */