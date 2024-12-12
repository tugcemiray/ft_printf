/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcemirayalgan <tugcemirayalgan@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:20:59 by tukaraca          #+#    #+#             */
/*   Updated: 2024/12/13 01:25:50 by tugcemiraya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr(int nbr);
int	ft_putnbr_hex(unsigned long n, char format);
int	ft_putnbr_unsigned(unsigned int nbr);
int	ft_putptr(unsigned long nbr, char *a);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);
int	specify_format(char format, va_list args);

#endif