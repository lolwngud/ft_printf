/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhypark <juhypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:23:31 by juhypark          #+#    #+#             */
/*   Updated: 2023/04/29 00:35:55 by juhypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_form(const char c, va_list *ap)
{
	if (c == 'c')
		return (ft_printchar(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(*ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_printnbr_fd(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_printuns_fd(va_arg(*ap, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_printf_ptr(va_arg(*ap, unsigned long long)));
	else if (c == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print;
	int		i;

	print = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			print += ft_check_form(format[++i], &ap);
			i++;
		}
		else
		{
			print += ft_printchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (print);
}
