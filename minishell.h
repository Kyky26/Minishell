/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 00:27:38 by ktyu              #+#    #+#             */
/*   Updated: 2026/08/10 23:45:17 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum token_type
{
	TOKEN_WORD,		//ls, -la, "file name", hello
	TOKEN_PIPE,		// |
	TOKEN_REDIR_IN,	// <
	TOKEN_REDIR_OUT,	// >
	TOKEN_HEREDOC,	// <<
	TOKEN_APPEND	// >>
}	t_token_type;

typedef struct s_token
{
	char	*value;	//Holds the string ("ls", "|")
	t_token_type type;	// Holds the enum label (e.g. TOKEN_WORD, TOKEN_PIPE)
	struct s_token *next;	//Pointer to the next token node
} t_token;

