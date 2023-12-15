/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:25:27 by acharik           #+#    #+#             */
/*   Updated: 2023/12/13 05:33:38 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_to_hex_pointer(unsigned long quotient, int write_0x,
		int *bytes_written, int recursion)
{
	const char	*hex_digits;

	if (write_0x)
		*bytes_written += write(1, "0x", 2);
	if (quotient)
		convert_to_hex_pointer(quotient / 16, 0, bytes_written, 0);
	hex_digits = "0123456789abcdef";
	if (quotient)
	{
		*bytes_written += write(1, &hex_digits[quotient % 16], sizeof(char));
	}
	if (!quotient && recursion)
	{
		*bytes_written += write(1, "0", 1);
	}
}

void	convert_to_hex(unsigned int quotient, int flag, int *bytes_written,
		int recursion)
{
	const char	*hex_digits;
	const char	*hex_digits_up;

	if (quotient)
	{
		convert_to_hex(quotient / 16, flag, bytes_written, 0);
	}
	hex_digits = "0123456789abcdef";
	hex_digits_up = "0123456789ABCDEF";
	if (quotient && !flag)
	{
		*bytes_written += write(1, &hex_digits[quotient % 16], sizeof(char));
	}
	if (quotient && flag)
	{
		*bytes_written += write(1, &hex_digits_up[quotient % 16], sizeof(char));
	}
	if (!quotient && recursion)
	{
		*bytes_written += write(1, "0", 1);
	}
}
