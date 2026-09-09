/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 00:27:38 by ktyu              #+#    #+#             */
/*   Updated: 2026/09/09 20:34:13 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND
}	t_token_type;

typedef struct s_token
{
	char	*value;
	t_token_type type;
	struct s_token *next;
} t_token;

typedef enum e_redir_type
{
	REDIR_IN,      // Matches TOKEN_REDIR_IN
	REDIR_OUT,     // Matches TOKEN_REDIR_OUT
	REDIR_HEREDOC, // Matches TOKEN_HEREDOC
	REDIR_APPEND   // Matches TOKEN_APPEND
}	t_redir_type;

typedef struct s_redir
{
	t_redir_type	type;
	char			*filename;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**args;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;


//Helper Lexer functions

t_token *new_token(char *value, t_token_type type);
void	add_token_behind(t_token **head, t_token *new);
void	free_all_tokens(t_token *head);

int	handle_operator(char *str, int i, t_token **head);
int	handle_word(char *str, int i, t_token **head);
t_token	*lexer(char *line);

char	*find_env_value(char *key, char **envp, int last_status);
char	*strip_quotes(char *str);
void	expander(t_token *tokens, char **envp, int last_status);

void	free_cmd(t_cmd *cmd);
t_cmd	*parser(t_token *tokens);

#endif
