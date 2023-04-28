/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhypark <juhypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:24:01 by juhypark          #+#    #+#             */
/*   Updated: 2023/04/29 00:17:32 by juhypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printchar(int c);
int	ft_check_form(const char c, va_list *ap);
int	ft_printf(const char *format, ...);
int	ft_printnbr_fd(int n);
int	ft_printstr(char *str);
int	ft_printuns_fd(unsigned int n);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_printf_ptr(unsigned long long ptr);
int	ft_putstr_fd(char *s, int fd);

#endif