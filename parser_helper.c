/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 01:39:50 by ktyu              #+#    #+#             */
/*   Updated: 2026/09/20 18:29:56 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_syntax_errors(t_token *tokens)
{
	if (!tokens)
		return (0);
	if (tokens->type == TOKEN_PIPE)
	{
		printf("minishell: syntax error near unexpected token '|'\n");
		return (1);
	}
	while (tokens)
	{
		if (tokens->type >= TOKEN_REDIR_IN && tokens->type <= TOKEN_APPEND)
		{
			if (!tokens->next || tokens->next->type != TOKEN_WORD)
			{
				printf("minishell: syntax error near unexpected token 'newline'\n");
				return (1);
			}
		}
		if (tokens->type == TOKEN_PIPE)
		{
			if (!tokens->next)
			{
				printf("minishell: syntax error near unexpected token '|'\n");
				return (1);
			}
			if (tokens->next->type == TOKEN_PIPE)
			{
				printf("minishell: syntax error near unexpected token '|'\n");
				return (1);
			}			
		}
		tokens = tokens->next;
	}
	return (0);
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp_cmd;
	t_redir	*tmp_redir;
	int		i;

	while (cmd)
	{
		tmp_cmd = cmd->next;
		if (cmd->args)
		{
			i = 0;
			while (cmd->args[i])
				free(cmd->args[i++]);
			free(cmd->args);
		}
		while (cmd->redirs)
		{
			tmp_redir = cmd->redirs->next;
			free(cmd->redirs->filename);
			free(cmd->redirs);
			cmd->redirs = tmp_redir;
		}
		free(cmd);
		cmd = tmp_cmd;
	}
}


