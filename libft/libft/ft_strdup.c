/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:09:23 by nsiefert          #+#    #+#             */
/*   Updated: 2025/01/03 23:31:07 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*to_return;

	if (!s || !*s)
	{
		to_return = malloc(sizeof(char) * 2);
		if (!to_return)
			return (NULL);
		ft_strlcpy(to_return, "", 2);
		return (to_return);
	}
	len = ft_strlen(s) + 1;
	to_return = (char *)malloc(sizeof(char) * len);
	if (!to_return)
		return (NULL);
	ft_strlcpy(to_return, s, len);
	return (to_return);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*to_return;

	len = strnlen(s, n) + 1;
	to_return = (char *)malloc(sizeof(char) * len + 1);
	if (!to_return)
		return (NULL);
	ft_strlcpy(to_return, s, n);
	to_return[n] = '\0';
	return (to_return);
}
