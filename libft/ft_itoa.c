/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:16:11 by vsharma           #+#    #+#             */
/*   Updated: 2023/09/18 10:16:16 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

char	*ft_itoa(int n)
{
	char	*arr;
	size_t	len;

	len = length(n) + 1;
	arr = (char *)malloc(sizeof (char) * (len));
	len--;
	if (!arr)
		return (0);
	arr[len] = '\0';
	if (n == 0)
	{
		len--;
		arr[len] = '0';
	}
	while (n)
	{
		len--;
		arr[len] = ft_abs(n % 10) + '0';
		n = n / 10;
	}
	if (len--)
		arr[len] = '-';
	return (arr);
}

/*int main() 
{
   int	test1 = 34665436;
   char	*result = ft_itoa(test1);
   
   printf("Integer: %d\n", test1);
   printf(" String: %s\n", result);
   free(result);  
}*/
