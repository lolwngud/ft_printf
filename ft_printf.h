/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejikim <sejikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:24:01 by juhypark          #+#    #+#             */
/*   Updated: 2023/04/29 17:56:13 by sejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *format, ...);
void	ft_printnbr(int n, int *pt_len);
void	ft_printstr(char *str, int *pt_len);
void	ft_printuns(unsigned int n, int *pt_len);
void	ft_putchar(const char c, int *pt_len);
void	ft_putnbr_base(unsigned int nbr, char *base, int *pt_len);
void	ft_printf_ptr(unsigned long long ptr, int *pt_len);
void	ft_putstr(char *s, int *pt_len);

#endif
