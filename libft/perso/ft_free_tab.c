/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:11:18 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/27 12:27:40 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso.h"

//  Free a 2 dimensions tab of pointers
void	free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
