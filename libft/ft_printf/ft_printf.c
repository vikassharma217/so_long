/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:36:01 by vsharma           #+#    #+#             */
/*   Updated: 2023/10/06 22:10:00 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_formatcheck(char specifier, va_list arguments)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_print_char(va_arg(arguments, int));
	else if (specifier == 's')
		len += ft_print_str(va_arg(arguments, char *));
	else if (specifier == 'p')
		len += ft_print_pointer(va_arg(arguments, void *));
	else if (specifier == 'd')
		len += ft_print_digit(va_arg(arguments, int));
	else if (specifier == 'i')
		len += ft_print_digit(va_arg(arguments, int));
	else if (specifier == 'u')
		len += ft_print_unsign_dec(va_arg(arguments, unsigned int));
	else if (specifier == 'x')
		len += ft_print_hex(va_arg(arguments, unsigned int), 'x');
	else if (specifier == 'X')
		len += ft_print_hex(va_arg(arguments, unsigned int), 'X');
	else if (specifier == '%')
		len += ft_print_char('%');
	else
		len += write(1, &specifier, 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		len;

	len = 0;
	if (!format)
		return (-1);
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_formatcheck(*++format, arguments);
		}
		else
		{
			len += write(1, format, 1);
		}
		format++;
	}
	va_end(arguments);
	return (len);
}

/*int	main(void)
{
	void *ptr;
	ft_printf("Total count: %d\n", ft_printf("Hex is %x\n", -10));
	printf("Total count: %d\n", printf("Hex is %x\n", -10));
	printf("\n");
	ft_printf("Total count: %d\n", ft_printf("Hex is %X\n",10));
	printf("Total count: %d\n", printf("Hex is %X\n",10));
	printf("\n");
	ft_printf("Total count: %d\n", ft_printf("unsigned int %u\n",8));
	printf("Total count: %d\n", printf("unsigned int %u\n",8));
	printf("\n");
	ft_printf("Total count: %d\n", ft_printf("Decimal: %d\n",8));
	printf("Total count: %d\n", printf("Decimal: %d\n",8));
	printf("\n");
	ft_printf("Total count: %d\n", ft_printf("Integer %i\n",8));
	printf("Total count: %d\n", printf("Integer %i\n",8));
	printf("\n");
	ft_printf("Total count: %d\n", ft_printf("Pointer %p\n", &ptr));
	printf("Total count: %d\n", printf("Pointer %p\n", &ptr));
	printf("%d\n", printf(" %p %p ", 0, 0));
	printf("%d\n", ft_printf(" %p %p ", 0, 0));
	return (0);
}*/
