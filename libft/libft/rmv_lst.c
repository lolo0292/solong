/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmv_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:11:04 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/26 19:11:05 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Remove an element of my list :
//		return 0 if it removed the element
//		return 1 if there was nothing to remove
int	rmv_lst(t_list **head, void *content)
{
	t_list	*tmp;
	t_list	*save;

	tmp = *head;
	save = NULL;
	while (tmp)
	{
		if (!ft_memcmp(tmp->content, content, ft_strlen((char *)content)))
		{
			if (!save)
				*head = tmp->next;
			else
				save->next = tmp->next;
			free(tmp->content);
			free(tmp);
			return (0);
		}
		save = tmp;
		tmp = tmp->next;
	}
	return (1);
}
