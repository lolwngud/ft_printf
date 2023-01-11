/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhypark <juhypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:23:31 by juhypark          #+#    #+#             */
/*   Updated: 2023/01/11 18:12:38 by juhypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print;

	print = 0;
	va_start(ap, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
		}
		else
		{
			write(1, format++, 1);
			print++;
		}
	}
	va_end(ap);
	return (print);
}
