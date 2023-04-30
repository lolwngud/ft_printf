/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejikim <sejikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:24:15 by juhypark          #+#    #+#             */
/*   Updated: 2023/04/29 18:00:29 by sejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static void	ft_putptr(unsigned long long ptr, int *pt_len)
{
	if (*pt_len == -1)
		return ;
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, pt_len);
		ft_putptr(ptr % 16, pt_len);
	}
	else
	{
		if (ptr < 10)
			ft_putchar('0' + ptr, pt_len);
		else
			ft_putchar(ptr - 10 + 'a', pt_len);
	}
}

void	ft_printf_ptr(unsigned long long ptr, int *pt_len)
{
	if (*pt_len == -1)
		return ;
	ft_putstr("0x", pt_len);
	ft_putptr(ptr, pt_len);
}

void	ft_printnbr(int n, int *pt_len)
{
	if (*pt_len == -1)
		return ;
	if (n == -2147483648)
		ft_putstr("-2147483648", pt_len);
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-', pt_len);
		ft_printnbr(n, pt_len);
	}
	else if (n < 10)
		ft_putchar(n + 48, pt_len);
	else
	{
		ft_printnbr(n / 10, pt_len);
		ft_printnbr(n % 10, pt_len);
	}
}

void	ft_printstr(char *str, int *pt_len)
{
	if (str == NULL)
		ft_putstr("(null)", pt_len);
	else
		ft_putstr(str, pt_len);
}
