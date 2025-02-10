/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:09:53 by nsiefert          #+#    #+#             */
/*   Updated: 2025/01/03 18:51:55 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && len < n)
		len++;
	return (len);
}

size_t	ft_strlen_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		continue ;
	return (i);
}

size_t	ft_lstlen(t_list **head)
{
	int		i;
	t_list	*tmp;

	if (!head)
		return (0);
	tmp = *head;
	if (!tmp)
		return (0);
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
