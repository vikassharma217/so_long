/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:19:03 by vsharma           #+#    #+#             */
/*   Updated: 2023/09/16 20:19:05 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	s;

	s = (nmemb * size);
	if (nmemb == 0)
		nmemb = 1;
	if ((size * nmemb) / nmemb != size)
		return (NULL);
	ptr = malloc(s);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, s);
	return (ptr);
}
