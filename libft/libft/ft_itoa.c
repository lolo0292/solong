/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:07:38 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/26 19:07:39 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_sign(char *str, long *nb)
{
	if ((*nb) == 0)
		str[0] = '0';
	if ((*nb) < 0)
	{
		str[0] = '-';
		*nb = -*nb;
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	size_t		i;
	size_t		modulus;
	short int	rparodilpb;
	char		str[13];
	long		nb;

	nb = n;
	rparodilpb = 0;
	modulus = 1000000000;
	ft_bzero(str, 13);
	i = ft_check_sign(str, &nb);
	while (modulus != 0)
	{
		if (nb / modulus != 0 || rparodilpb != 0)
		{
			str[i++] = (nb / modulus) + 48;
			rparodilpb++;
		}
		nb %= modulus;
		modulus /= 10;
	}
	return (ft_strdup(str));
}
