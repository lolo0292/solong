/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:28:30 by nsiefert          #+#    #+#             */
/*   Updated: 2025/01/05 16:19:08 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static void	copy_token(char *command, int length, char *str, int i)
{
	int	j;

	j = 0;
	while (command[i + j] && i < length)
	{
		if (command[i + j] == '\'' && ++j)
		{
			while (command[i + j] != '\'' && ++i)
				str[i - 1] = command[(i - 1) + j];
			j++;
		}
		else if (command[i + j] == '"' && ++j)
		{
			while (command[i + j] != '"' && ++i)
				str[i - 1] = command[(i - 1) + j];
			j++;
		}
		else
		{
			str[i] = command[i + j];
			i++;
		}
	}
	str[i] = 0;
}

static bool	add_cmd(t_token **begin, char **command)
{
	char	*str;
	int		length;
	int		quotes;
	int		i;

	i = 0;
	length = length_cmd(*command, &quotes);
	if (((length) - (2 * quotes)) < 0)
		return (true);
	str = malloc(sizeof(char) * ((length + 1) - (2 * quotes)));
	if (!str)
		return (false);
	copy_token(*command, length - (2 * quotes), str, i);
	if (!append_token(begin, str, 0))
		return (false);
	if ((*begin)->prev_token == (*begin) || (*begin)->prev_token->prev_token->type == PIPE)
		(*begin)->prev_token->type = CMD;
	else
		(*begin)->prev_token->type = ARGS;
	(*command) += length;
	return (true);
}

static bool	add_special(t_token **begin, char **command)
{
	int	spe;

	spe = is_special(*command);
	if (!spe)
		return (false);
	if (spe == INPUT && !append_token(begin, ft_strdup("<"), INPUT))
		return (false);
	else if (spe == HEREDOC && !append_token(begin, ft_strdup("<<"), HEREDOC))
		return (false);
	else if (spe == OUTPUT && !append_token(begin, ft_strdup(">"), OUTPUT))
		return (false);
	else if (spe == APPEN && !append_token(begin, ft_strdup(">>"), APPEN))
		return (false);
	else if (spe == PIPE && !append_token(begin, ft_strdup("|"), PIPE))
		return (false);
	if (spe == INPUT || spe == OUTPUT || spe == PIPE)
		(*command)++;
	else if (spe == HEREDOC || spe == APPEN)
		(*command) += 2;
	return (true);
}

int	tokenizer(t_token **begin, char *entry)
{
	(*begin) = NULL;
	while (*entry)
	{
		while (is_space(*entry))
			entry++;
		if (*entry && !is_special(entry) && !ft_tknadd_back(begin, \
			&entry))
		{
			if (*begin)
				free_token(begin);
			return (1);
		}
		else if (*entry && is_special(entry) && \
					!add_special(begin, &entry))
		{
			if (*begin)
				ft_tknfree(begin);
			return (1);
		}
	}
	return (0);
}
