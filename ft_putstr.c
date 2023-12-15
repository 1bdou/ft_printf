/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:25:13 by acharik           #+#    #+#             */
/*   Updated: 2023/12/13 05:28:12 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *bytes_written)
{
	if (str == NULL)
	{
		*bytes_written += write(1, "(null)", 6 * sizeof(char));
		return ;
	}
	while (*str)
	{
		*bytes_written += write(1, str, sizeof(char));
		str++;
	}
}
