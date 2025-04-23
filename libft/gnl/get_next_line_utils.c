/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:52:25 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/26 13:14:00 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlen3(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc3(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}

char	*ft_substr3(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s || start >= ft_strlen3(s))
		return (ft_calloc3(1, 1));
	if (len > ft_strlen3(s + start))
		len = ft_strlen3(s + start);
	substr = ft_calloc3(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*stj1(const char *s1, const char *s2, char *str)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = ft_strlen3(s1);
	len2 = ft_strlen3(s2);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin3(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1)
		s1 = ft_calloc3(1, 1);
	if (!s1 || !s2)
	{
		free(s1);
		return (NULL);
	}
	len1 = ft_strlen3(s1);
	len2 = ft_strlen3(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	str = stj1(s1, s2, str);
	free(s1);
	return (str);
}

// char *ft_strjoin(char *s1, char *s2)
// {
//     char    *str;
//     size_t  len1 = ft_strlen(s1);
//     size_t  len2 = ft_strlen(s2);
//     size_t  i = 0;

//     if (!s1)
//         s1 = ft_calloc(1, 1);
//     if (!s1 || !s2)
//         return (free(s1), NULL);
//     str = ft_calloc(len1 + len2 + 1, sizeof(char));
//     if (!str)
//         return (free(s1), NULL);
//     while (i < len1)
//     {
//         str[i] = s1[i];
//         i++;
//     }
//     while (i - len1 < len2)
//     {
//         str[i] = s2[i - len1];
//         i++;
//     }
//     str[i] = '\0';
//     free(s1);
//     return (str);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;
// 	size_t	len1;
// 	size_t	len2;
// 	size_t	i;

// 	if (!s1)
// 		s1 = ft_calloc(1, 1);
// 	if (!s2)
// 		return (free(s1), NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	str = ft_calloc(len1 + len2 + 1, sizeof(char));
// 	if (!str)
// 		return (free(s1), NULL);
// 	i = -1;
// 	while (++i < len1)
// 		str[i] = s1[i];
// 	i = -1;
// 	while (++i < len2)
// 		str[len1 + i] = s2[i];
// 	str[len1 + len2] = '\0';
// 	free(s1);
// 	return (str);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 		return ((char *)(s + i));
// 	else
// 		return (NULL);
// }
