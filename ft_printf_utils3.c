/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejikim <sejikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:46:33 by juhypark          #+#    #+#             */
/*   Updated: 2023/04/29 18:05:36 by sejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_printuns(unsigned int n, int *pt_len)
{
	if (*pt_len == -1)
		return ;
	if (n < 10)
		ft_putchar(n + 48, pt_len);
	else
	{
		ft_printuns(n / 10, pt_len);
		ft_printuns(n % 10, pt_len);
	}
}

void	ft_putchar(const char c, int *pt_len)
{
	if (*pt_len == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*pt_len = -1;
	else
		*pt_len += 1;
}

void	ft_putstr(char *s, int *pt_len)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (*pt_len == -1)
			return ;
		ft_putchar(s[i++], pt_len);
	}
}
