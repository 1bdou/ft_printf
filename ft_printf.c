/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:25:34 by acharik           #+#    #+#             */
/*   Updated: 2023/12/13 05:51:56 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		bytes_writen;
	int		i;
	int		j;
	va_list	args;

	bytes_writen = 0;
	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			check_format(str, ++i, args, &bytes_writen);
		else if (str[i] != '%')
		{
			ft_putchar(str[i], &bytes_writen);
		}
		i++;
	}
	va_end(args);
	return (bytes_writen);
}
