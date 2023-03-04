/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:26:06 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/10/29 19:10:07 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void*s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
	p[i] = '\0';
	i++;
	}
}
/* int main(void)
{
	char str[] = "ABC";
	printf("\nBefore ft_bzero(): %s\n", str);
  
	// Fill 2 characters starting from str[1] with '.'
	ft_bzero(str + 1, 2*sizeof(char));
	printf("After ft_bzero():  %s", str);
	return (0);
}*/