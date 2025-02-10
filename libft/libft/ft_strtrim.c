/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:10:24 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/26 19:10:25 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i])
		i++;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	j = ft_strlen(s1);
	while (ft_strrchr(set, s1[j - 1]) != NULL && j > i)
		j--;
	str = (char *)malloc(j - i + 1);
	if (!str)
		return (NULL);
	k = 0;
	while (i < j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
