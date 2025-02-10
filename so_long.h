/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:01:10 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/10 11:04:36 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <signal.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_map {
    char **grid;      // Tableau 2D contenant la carte
    int width;        // Largeur de la carte
    int height;       // Hauteur de la carte
    int collectibles; // Nombre d’objets à ramasser (C)
    int player_x;     // Position X du joueur
    int player_y;     // Position Y du joueur
    int exit_x;       // Position X de la sortie
    int exit_y;       // Position Y de la sortie
} t_map;

#endif