/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkju-hyeong <parkju-hyeong@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:23:31 by juhypark          #+#    #+#             */
/*   Updated: 2023/04/30 20:57:13 by parkju-hyeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	ft_check_form(const char c, va_list *ap, int *pt_len)
{
	if (c == 'c')
		ft_putchar(va_arg(*ap, int), pt_len);
	else if (c == 's')
		ft_printstr(va_arg(*ap, char *), pt_len);
	else if (c == 'd' || c == 'i')
		ft_printnbr(va_arg(*ap, int), pt_len);
	else if (c == 'u')
		ft_printuns(va_arg(*ap, unsigned int), pt_len);
	else if (c == 'x')
		ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789abcdef", pt_len);
	else if (c == 'X')
		ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789ABCDEF", pt_len);
	else if (c == 'p')
		ft_printf_ptr(va_arg(*ap, unsigned long long), pt_len);
	else if (c == '%')
		ft_putchar('%', pt_len);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed_len;

	printed_len = 0;
	va_start(ap, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			if (ft_check_form(*(++format), &ap, &printed_len) == 0)
			{
				printed_len = -1;
				break ;
			}
			format++;
		}
		else
			ft_putchar(*(format++), &printed_len);
	}
	va_end(ap);
	return (printed_len);
}
