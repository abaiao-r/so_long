/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:17:18 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/10/29 17:15:43 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
	p[i] = c;
	i++;
	}
	return (p);
}
/* int main(void)
{
    char str[5] = "ABC";
    printf("\nBefore ft_memset(): %s\n", str);
  
    // Fill 2 characters starting from str[1] with '.'
    ft_memset(str + 1, 'D', 2*sizeof(char));
    printf("After ft_memset():  %s", str);
    return (0);
} */
