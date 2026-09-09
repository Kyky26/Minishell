/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 01:33:38 by ktyu              #+#    #+#             */
/*   Updated: 2026/09/09 18:46:47 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redir_type	get_redir_type(t_token_type type)
{
	if (type == TOKEN_REDIR_IN)
		return (REDIR_IN);
	if (type == TOKEN_REDIR_OUT)
		return (REDIR_OUT);
	if (type == TOKEN_HEREDOC)
		return (REDIR_HEREDOC);
	return (REDIR_APPEND);
}

static void	add_redir_back(t_redir **head, t_redir_type type, char *filename)
{
	t_redir *new_node;
	t_redir *curr;

	new_node = malloc(sizeof(t_redir));
	if (!new_node)
		return ;
	new_node->type = type;
	new_node->filename = ft_strdup(filename);
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

static void		add_arg_to_cmd(t_cmd *cmd, char *arg)
{
	int		count;
	char	**new_args;
	int		i;

	count = 0;
	while (cmd->args && cmd->args[count])
		count++;
	new_args = malloc(sizeof(char *) * (count + 2));
	if (!new_args)
		return ;
	i = 0;
	while (i < count)
	{
		new_args[i] = cmd->args[i];
		i++;
	}
	new_args[i] = ft_strdup(arg);
	new_args[i + 1] = NULL;
	free(cmd->args);
	cmd->args = new_args;
}

static t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*parser(t_token *tokens)
{
	t_cmd	*head;
	t_cmd	*curr_cmd;

	if (!tokens)
		return (NULL);
	head = new_cmd();
	curr_cmd = head;
	while (tokens)
	{
		if (tokens->type == TOKEN_WORD)
			add_arg_to_cmd(curr_cmd, tokens->value);
		else if (tokens->type >= TOKEN_REDIR_IN && tokens->type <= TOKEN_APPEND)
		{
			if (tokens->next && tokens->next->type == TOKEN_WORD)
			{
				add_redir_back(&curr_cmd->redirs, get_redir_type(tokens->type), tokens->next->value);
				tokens = tokens->next;
			}
		}
		else if (tokens->type == TOKEN_PIPE)
		{
			curr_cmd->next = new_cmd();
			curr_cmd = curr_cmd->next;
		}
		tokens = tokens->next;
	}
	return (head);
}
