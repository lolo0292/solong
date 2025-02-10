/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:06:20 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/26 19:06:21 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
 ** =========[ Includes ]==========
 */

/* get_next_line */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>	
# include "./libft.h"

/*
 ** =========[ Defines ]===========
 */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

/*
 ** =========[ Prototypes ]========
 */

/*
 ** get_next_line_utils.c
 */

char	*ft_strchr(char const *s, int c);
size_t	ft_strlen(char const *str);
char	*ft_strdup(char const *s1);
char	*ft_strjoin_free_s1(char *s1, char *s2);
char	*ft_substr(char const *str, unsigned int start, size_t size);

/*
 ** get_next_line.c
 */

/* static char *ft_next(char **temp) */
/* static char *ft_read(char *temp, int fd) */
char	*get_next_line(int fd);

#endif