/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhypark <juhypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:27:05 by juhypark          #+#    #+#             */
/*   Updated: 2023/04/29 07:56:36 by juhypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuns_fd(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
		len += ft_putchar_fd(n + 48, 1);
	else
	{
		len += ft_printuns_fd(n / 10);
		len += ft_printuns_fd(n % 10);
	}
	return (len);
}

int	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
	return (1);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

static int	ft_base_convert(unsigned int nbr, char *base, unsigned int b_len)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len += ft_putchar_fd('-', 1);
		len += ft_base_convert(nbr, base, b_len);
	}
	else if (nbr < b_len)
		len += ft_putchar_fd(base[nbr], 1);
	else
	{
		len += ft_base_convert(nbr / b_len, base, b_len);
		len += ft_base_convert(nbr % b_len, base, b_len);
	}
	return (len);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	b_len;
	int	len;

	b_len = ft_strlen(base);
	len = ft_base_convert(nbr, base, b_len);
	return (len);
}
