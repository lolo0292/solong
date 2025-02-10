/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:11:13 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/26 19:11:14 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso.h"

int	ft_countchar(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}
