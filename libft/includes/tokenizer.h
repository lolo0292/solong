/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:40:44 by nsiefert          #+#    #+#             */
/*   Updated: 2025/01/05 16:37:11 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
//	The t_token struct is a token struct that is a double linked list who
//		contains all the informations for a tokenization
*/

#ifndef T_TOKEN_H
# define T_TOKEN_H

# include "libft.h"

//	Gestion de mes tokens
//	---------------------
//	STR			==	String without anything particular	
//	PIPE		==	Pipe in-between commands
//	L_CHEVRON	==	Input redirection, should be after the arguments, I can have
//						as much as I want to but I will only read the last one
//	R_CHEVRON	==	Output redirection, should create the files if they don't
//						exist, then only write in the last one
//	HERE_DOC	==	Create a temporary file then write into it the content of
//						the user here-doc. If multiple here-docs, you should
//						exec them all but only read the last one (function as
//						an input redirection)
//	APPEN		==	Same as the here-doc but for the ouput, and also write at
//						the end of the file, without over-writing in the file

# define WORD		0	//	"string"
# define INPUT 		1	//	"<"
# define OUTPUT 	2	//	">"
# define HEREDOC 	3	//	"<<"
# define APPEN 		4	//	">>"
# define PIPE		5	//	"|"
# define CMD		6	//	"string"
# define ARGS		7	//	"string"

/* ************************************************************************** */
/*									STRUCTURE								  */
/* ************************************************************************** */

typedef struct s_token
{
	int				type;
	char			*str;
	struct s_token	*next_token;
	struct s_token	*prev_token;
} t_token;

/* ************************************************************************** */
/*									PROTOTYPES								  */
/* ************************************************************************** */

t_token	*ft_tknnew(int type, char *str);
int		ft_tknadd_back(t_token **head, t_token *tkn);
int		ft_tknlen(t_token **head);
void	ft_tknfree(t_token	**head);
int		tokenizer(t_token **head, char *entry);
int		is_special(char *str);
#endif