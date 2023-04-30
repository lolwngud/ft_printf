/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejikim <sejikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:27:05 by juhypark          #+#    #+#             */
/*   Updated: 2023/04/29 18:04:26 by sejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

static void	ft_convert_hex(long long nbr, char *base, int *pt_len)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-', pt_len);
		ft_convert_hex(nbr, base, pt_len);
	}
	else if (nbr < 16)
		ft_putchar(base[nbr], pt_len);
	else
	{
		ft_convert_hex(nbr / 16, base, pt_len);
		ft_convert_hex(nbr % 16, base, pt_len);
	}
}

static void	ft_convert_dec(long long nbr, char *base, int *pt_len)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-', pt_len);
		ft_convert_dec(nbr, base, pt_len);
	}
	else if (nbr < 10)
		ft_putchar(base[nbr], pt_len);
	else
	{
		ft_convert_dec(nbr / 10, base, pt_len);
		ft_convert_dec(nbr % 10, base, pt_len);
	}
}

void	ft_putnbr_base(unsigned int nbr, char *base, int *pt_len)
{
	int	b_len;

	b_len = ft_strlen(base);
	if (b_len == 10)
		ft_convert_dec(nbr, base, pt_len);
	else if (b_len == 16)
		ft_convert_hex(nbr, base, pt_len);
}
