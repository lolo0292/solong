/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:12:03 by nsiefert          #+#    #+#             */
/*   Updated: 2025/01/03 23:43:18 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso.h"

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab[0])
	{
		printf("pass  at 1\n");
		if (!tab[0][0])
		{
		printf("pass  at 2\n");
		return ;
		}
	}
	printf("j'ai qqch\n");
	while (tab[++i])
		printf("i %d -- %s\n",i , tab[i]);
}
