/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:40:34 by vsharma           #+#    #+#             */
/*   Updated: 2023/09/09 13:40:36 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	i = 0;
	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (i < n)
	{
		if (temp1[i] > temp2[i])
		{
			return (1);
		}
		else if (temp1[i] < temp2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_memcmp("adcd", "", 2));
}*/
