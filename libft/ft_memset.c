/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                           :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:07:48 by vsharma           #+#    #+#             */
/*   Updated: 2023/09/05 17:07:50 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *string, int c, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = string;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (string);
}

/*int	main(void)
{
	char	test[] = "RANDOM string";
	ft_memset (test, '4', 5);
	printf("%s\n", test);
	memset (test, '4', 5);
	printf("%s\n", test);
}*/
