/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:25:23 by acharik           #+#    #+#             */
/*   Updated: 2023/12/13 06:21:16 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(const char *str, int i, va_list args, int *bytes_written)
{
	if (str[i] == 's')
		ft_putstr(va_arg(args, char *), bytes_written);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(args, int), bytes_written);
	else if (str[i] == 'p')
		convert_to_hex_pointer(va_arg(args, unsigned long), 1, bytes_written,
			1);
	else if (str[i] == 'x')
		convert_to_hex(va_arg(args, unsigned int), 0, bytes_written, 1);
	else if (str[i] == 'X')
		convert_to_hex(va_arg(args, unsigned int), 1, bytes_written, 1);
	else if (str[i] == '%')
		ft_putchar('%', bytes_written);
	else if (str[i] == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), bytes_written);
	else if (str[i] == 'c')
		ft_putchar(va_arg(args, int), bytes_written);
}
