/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                          :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:20:53 by vsharma           #+#    #+#             */
/*   Updated: 2023/09/04 18:11:32 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int digit)
{
	if (digit >= '0' && digit <= '9')
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_isdigit('8'));
	printf("%d\n", ft_isdigit('A'));
	printf("%d\n", ft_isdigit('6'));
}*/
