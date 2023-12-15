/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:25:51 by acharik           #+#    #+#             */
/*   Updated: 2023/12/13 05:28:54 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int number, int *bytes_written)
{
	long	digit;
	long	div_by;
	long	nbr;

	digit = number;
	nbr = number;
	if (number < 0)
	{
		digit = -digit;
		nbr = -nbr;
		*bytes_written += write(1, "-", 1);
	}
	div_by = 1;
	while (digit / div_by > 9)
		div_by *= 10;
	while (digit || div_by)
	{
		digit = digit / div_by + '0';
		*bytes_written += write(1, &digit, sizeof(char));
		digit = nbr % div_by;
		div_by = div_by / 10;
	}
}

void	ft_putnbr_unsigned(unsigned int number, int *bytes_written)
{
	long	digit;
	long	div_by;
	long	nbr;

	digit = number;
	nbr = number;
	if (number < 0)
	{
		digit = -digit;
		nbr = -nbr;
		*bytes_written += write(1, "-", 1);
	}
	div_by = 1;
	while (digit / div_by > 9)
		div_by *= 10;
	while (digit || div_by)
	{
		digit = digit / div_by + '0';
		*bytes_written += write(1, &digit, sizeof(char));
		digit = nbr % div_by;
		div_by = div_by / 10;
	}
}
