/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhypark <juhypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:24:15 by juhypark          #+#    #+#             */
/*   Updated: 2023/04/29 00:46:08 by juhypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	int	len;

	len = ft_putchar_fd(c, 1);
	return (len);
}

static void	ft_putptr(unsigned long long ptr, int *len)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, len);
		ft_putptr(ptr % 16, len);
	}
	else
	{
		if (ptr < 10)
			*len += ft_putchar_fd('0' + ptr, 1);
		else
			*len += ft_putchar_fd(ptr - 10 + 'a', 1);
	}
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += ft_putstr_fd("0x", 1);
	ft_putptr(ptr, &len);
	return (len);
}

int	ft_printnbr_fd(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		len += ft_putstr_fd("-2147483648", 1);
	else if (n < 0)
	{
		n = -n;
		len += ft_putchar_fd('-', 1);
		len += ft_printnbr_fd(n);
	}
	else if (n < 10)
		len += ft_putchar_fd(n + 48, 1);
	else
	{
		len += ft_printnbr_fd(n / 10);
		len += ft_printnbr_fd(n % 10);
	}
	return (len);
}

int	ft_printstr(char *str)
{
	int	len;

	if (str == 0)
	{
		len = ft_putstr_fd("(null)", 1);
		return (len);
	}
	len = ft_putstr_fd(str, 1);
	return (len);
}
