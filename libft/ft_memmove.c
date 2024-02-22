/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:54:39 by vsharma           #+#    #+#             */
/*   Updated: 2023/09/06 12:54:45 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*tempsrc;
	char		*tempdst;

	tempdst = dst;
	tempsrc = src;
	if (dst < src)
		ft_memcpy(dst, src, n);
	else if (dst > src)
		while (n--)
			tempdst[n] = tempsrc[n];
	return (dst);
}

/*int main (void) 
{
   char dest[] = "1 2 3 4 5 5 5 5 5 6 6 4 5 6 7 6 7 5  6 7 6 57 6 7 8 9";
   const char src[]  = "A B C D E F G H I Z K L M N O P Q R S T U V W X Y Z";
   ft_memmove(dest, src, 17);
   printf("%s\n", dest);
   memmove(dest, src, 17);
   printf("%s\n", dest);
}*/
