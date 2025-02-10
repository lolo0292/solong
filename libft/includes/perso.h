/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:06:32 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/27 12:20:12 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSO_H
# define PERSO_H

# include "libft.h"

int		ft_countchar(char *str, char c);
void	free_tab(void **tab);
void	print_tab(char **tab);
int		is_whitespace(char c);

#endif 