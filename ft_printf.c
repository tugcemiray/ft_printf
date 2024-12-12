/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcemirayalgan <tugcemirayalgan@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:17:35 by tukaraca          #+#    #+#             */
/*   Updated: 2024/12/13 02:36:10 by tugcemiraya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	return (i);
}

int	specify_format(char a, va_list args)
{
	if (a == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (a == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (a == 'p')
		return (ft_putptr(va_arg(args, unsigned long), "0123456789abcdef"));
	else if (a == 'd' || a == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (a == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (a == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), a));
	else if (a == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), a));
	else if (a == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j += specify_format(format[i], args);
		}
		else
			j += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (j);
}
