/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:34:18 by tukaraca          #+#    #+#             */
/*   Updated: 2024/12/13 18:42:17 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putchar((nbr % 10) + '0');
	}
	else
		i += ft_putchar(nbr + '0');
	return (i);
}

int	ft_putnbr_hex(unsigned long n, char format)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_putnbr_hex(n / 16, format);
	}
	if (format == 'x')
		i += ft_putchar("0123456789abcdef"[n % 16]);
	else if (format == 'X')
		i += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (i);
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 9)
	{
		i += ft_putnbr_unsigned(nbr / 10);
		i += ft_putnbr_unsigned(nbr % 10);
	}
	else
		i += ft_putchar(nbr + '0');
	return (i);
}

int	ft_putptr(unsigned long nbr, int c)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	i += ft_putstr("0x");
	i += ft_putnbr_hex(nbr, c);
	return (i);
}
