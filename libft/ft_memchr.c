/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                           :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:16:49 by vsharma           #+#    #+#             */
/*   Updated: 2023/09/09 12:16:52 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *string, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)string;
	while (i < n)
	{
		if (temp[i] == (unsigned char)c)
			return (temp + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*teststring1 = "abcdefgh@vienna42.com";
	char	*pos = ft_memchr(teststring1, '@', 20);
	if ( pos == NULL)
		printf("Character not found\n");
	else
		printf("%s\n", pos);
}*/
