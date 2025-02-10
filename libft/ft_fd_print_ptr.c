/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_print_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:12:30 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/26 19:12:31 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(int fd, uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(fd, num / 16);
		ft_put_ptr(fd, num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), fd);
		else
			ft_putchar_fd((num - 10 + 'a'), fd);
	}
}

int	ft_fd_print_ptr(int fd, unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr == 0)
	{
		print_length += write(2, "(nil)", 5);
		return (print_length);
	}
	print_length += write(fd, "0x", 2);
	ft_put_ptr(fd, ptr);
	print_length += ft_ptr_len(ptr);
	return (print_length);
}
