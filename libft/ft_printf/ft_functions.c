/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:15:11 by vsharma           #+#    #+#             */
/*   Updated: 2023/10/06 22:32:50 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += ft_print_str("(null)");
	}
	else
	{
		while (str[count] != '\0')
		{
			ft_print_char(str[count]);
			count++;
		}
	}
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	char			*hex;
	char			output[16];
	int				count;
	int				i;
	unsigned long	cpy;

	count = 0;
	i = 0;
	hex = "0123456789abcdef";
	cpy = (unsigned long)ptr;
	if (cpy == 0)
	{
		return (ft_print_str("(nil)"));
	}
	write(1, "0x", 2);
	while (cpy != 0)
	{
		output[i] = hex[cpy % 16];
		cpy = cpy / 16;
		i++;
	}
	while (i-- > 0)
		count += ft_print_char(output[i]);
	return (count + 2);
}

int	ft_print_digit(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		return (ft_print_str("-2147483648"));
	if (nbr < 0)
	{
		ft_print_char('-');
		nbr = -nbr;
		return (ft_print_digit(nbr) + 1);
	}
	else if (nbr < 10)
	{
		return (ft_print_char(nbr + '0'));
	}
	else
	{
		count += ft_print_digit(nbr / 10);
		count += ft_print_digit(nbr % 10);
	}
	return (count);
}

int	ft_print_unsign_dec(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr < 10)
	{
		return (ft_print_char(nbr + '0'));
	}
	else
	{
		count += ft_print_unsign_dec(nbr / 10);
		count += ft_print_unsign_dec(nbr % 10);
	}
	return (count);
}

int	ft_print_hex(unsigned int nbr, char c)
{
	int		count;
	char	*hexa;

	if (c == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (nbr < 16)
	{
		return (ft_print_char(hexa[nbr]));
	}
	else
	{
		count = ft_print_hex(nbr / 16, c);
		return (count + ft_print_hex(nbr % 16, c));
	}
}
