/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 01:39:50 by ktyu              #+#    #+#             */
/*   Updated: 2026/09/10 02:03:21 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
