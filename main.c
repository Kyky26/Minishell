/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:35:59 by ktyu              #+#    #+#             */
/*   Updated: 2026/09/21 00:04:42 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    char	*input;
	char	**env;
	t_token	*tokens;
	t_cmd	*cmd_list;
	int		last_status;

	(void)argc;
	(void)argv;
	env = copy_env(envp);
	last_status = 0;
	while (1)
	{
		setup_sig();
		input = readline("minishell$ ");
		if (input == NULL)
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (g_sig == SIGINT)
		{
			last_status = 130;
			g_sig = 0;
		}
		if (*input != '\0')
			add_history(input);
		tokens = lexer(input);
		if (tokens)
		{
			expander(tokens, env, last_status);
			cmd_list = parser(tokens);
			if (!cmd_list)
				last_status = 2;
			else
			{
				t_cmd *c = cmd_list;
				int cmd_idx = 1;
				while (c)
				{
					printf("--- Command %d ---\n", cmd_idx++);
					for (int i = 0; c->args && c->args[i]; i++)
						printf(" arg[%d]: %s\n", i, c->args[i]);
					t_redir *r = c->redirs;
					while (r)
					{
						printf(" redir type: %d, file: %s\n", r->type, r->filename);
						r = r->next;
					}
					c = c->next;
				}
				last_status = 0;
			}
			free_cmd(cmd_list);
			free_all_tokens(tokens);
		}
		free(input);
	}
	free_all_env(env);
    rl_clear_history();
    return (0);
}
