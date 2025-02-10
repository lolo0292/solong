/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:08:12 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/26 19:08:13 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tempo;
	t_list	*tempo_content;

	tempo_content = ft_lstnew(f(lst->content));
	if (!tempo_content)
		return (NULL);
	tempo = tempo_content;
	lst = lst->next;
	while (lst)
	{
		tempo_content = ft_lstnew(f(lst->content));
		if (!tempo_content)
		{
			ft_lstclear(&tempo, del);
			return (NULL);
		}
		ft_lstadd_back(&tempo, tempo_content);
		lst = lst->next;
	}
	return (tempo);
}
