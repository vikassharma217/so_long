/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                            :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:33:17 by vsharma           #+#    #+#             */
/*   Updated: 2023/09/06 10:33:33 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *string, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = string;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char	s[99] = "Hello there";
	ft_bzero (s, 4);
	printf("%s\n", s);
}*/
