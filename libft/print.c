/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:14:06 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/19 21:50:01 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse(char format, va_list ap)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_c(va_arg(ap, int));
	else if (format == 's')
		count += print_s(va_arg(ap, const char *));
	else if (format == 'x' || format == 'X')
		count += print_xx(va_arg(ap, unsigned int), format, 0);
	else if (format == 'd' || format == 'i')
		count += print_id(va_arg(ap, int));
	else if (format == 'u')
		count += print_u(va_arg(ap, unsigned int));
	else if (format == '%')
		count += print_c('%');
	else if (format == 'p')
		count += print_p(va_arg(ap, long int *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_parse(format[i], ap);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
