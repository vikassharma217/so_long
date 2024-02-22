/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:32:01 by vsharma           #+#    #+#             */
/*   Updated: 2023/09/06 11:32:08 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*tempsrc;
	char		*tempdst;

	if (dst == src || !n)
		return (dst);
	tempdst = dst;
	tempsrc = src;
	while (n--)
	{
		*tempdst = *tempsrc;
		tempdst++;
		tempsrc++;
	}
	return (dst);
}

/*int	main(void)
{
	const char *src = "This is source";
	char *dest;
	//memcpy (dest, src, 7);
	//printf("%s\n", dest);
	ft_memcpy(dest, src, 7);
	printf("%s\n", dest);
	return (0);
}*/
