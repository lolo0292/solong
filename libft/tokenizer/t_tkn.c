/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tkn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:16:07 by nsiefert          #+#    #+#             */
/*   Updated: 2025/01/05 13:03:40 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token.h"

/* ************************************************************************** */
/*																			  */
/*		Utils for the t_token struct -> New elem, add_back, get_type, clear	  */
/*																			  */
/* ************************************************************************** */

void	ft_tknfree(t_token **head)
{
	t_token	*tmp;
	t_token	*save;

	tmp = *head;
	while (tmp)
	{
		save = tmp->next_token;
		free(tmp->str);
		free(tmp);
		tmp = save;
	}
}

int	ft_tknlen(t_token **head)
{
	int		i;
	t_token	*tmp;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next_token;
		i++;
	}
	return (i);
}

int	ft_tknadd_back(t_token **head, t_token *tkn)
{
	t_token	*tmp;

	tmp = *head;
	if (!tmp)
		*head = tkn;
	if (!tmp)
		return (1);
	while (tmp->next_token)
		tmp = tmp->next_token;
	tmp->next_token = tkn;
	tkn->prev_token = tmp;
	return (0);
}

t_token	*ft_tknnew(int type, char *str)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->next_token = NULL;
	new->prev_token = NULL;
	new->type = type;
	new->str = ft_strdup(str);
	if (!new->str)
		return (free(new), NULL);
	return (new);
}