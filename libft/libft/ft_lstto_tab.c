/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstto_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:08:27 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/27 16:35:50 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lstto_tab(t_list **head)
{
	char	**tab;
	int		i;
	int		size;
	t_list	*tmp;

	if (!head)
		return (NULL);
	tmp = *head;
	if (!tmp)
		return (NULL);
	size = ft_lstlen(head);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < size && tmp)
	{
		tab[i] = ft_strdup((char *)tmp->content);
		if (!tab[i])
			return (free_tab((void **)tab), NULL);
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}
