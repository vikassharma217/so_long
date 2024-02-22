/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:42:27 by vsharma           #+#    #+#             */
/*   Updated: 2023/09/14 14:42:29 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	l_len = ft_strlen(little);
	if (!l_len)
		return ((char *)big);
	while (*big && l_len <= len)
	{
		if (ft_strncmp(big, little, l_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	*test1 = "aaabcabcd";
	const char	*test2 = "cd";
	size_t	len = 9;
	
	char	*ptr1 = ft_strnstr(test1, test2, len);
	printf("%s\n", ptr1);
}*/
