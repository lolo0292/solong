/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:06:15 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/27 12:21:03 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_printf_fd(int fd, const char *str, ...);
int		ft_fd_formats(int fd, const char format, va_list args);
int		ft_fd_printchar(int c, int fd);
int		ft_fd_printstr(int fd, char *str);
int		ft_fd_print_ptr(int fd, unsigned long long ptr);
int		ft_fd_printnbr(int fd, int n);
int		ft_fd_print_unsigned(int fd, unsigned int n);
int		ft_fd_print_hex(int fd, unsigned int num, const char format);
int		ft_fd_printpercent(int fd);
int		ft_ptr_len(uintptr_t num);
int		ft_num_len(unsigned	int num);
int		ft_hex_len(unsigned	int num);

void	ft_putstr(int fd, char *str);
void	ft_put_ptr(int fd, uintptr_t num);
void	ft_put_hex(int fd, unsigned int num, const char format);

char	*ft_uitoa(unsigned int n);

#endif