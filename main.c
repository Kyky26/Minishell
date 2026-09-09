/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:35:59 by ktyu              #+#    #+#             */
/*   Updated: 2026/09/10 02:09:29 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    char	*input;
	t_token *tokens;

	(void)argc;
	(void)argv;
	(void)envp;

	while (1)
	{
		input = readline("minishell$ ");

		if (input == NULL)
		{
			write(1, "exit\n", 5);
			break ;
		}

		if (*input != '\0')
			add_history(input);

		
		tokens = lexer(input);

		expander(tokens, envp, 0);

		t_cmd *cmd_list = parser(tokens);

		t_cmd *c = cmd_list;
		int cmd_idx = 1;
		while (c)
		{
			printf("--- Command %d ---\n", cmd_idx++);
			for (int i = 0; c->args && c->args[i]; i++)
				printf("  arg[%d]: %s\n", i, c->args[i]);
			
			t_redir *r = c->redirs;
			while (r)
			{
				printf("  redir type: %d, file: %s\n", r->type, r->filename);
				r = r->next;
			}
			c = c->next;
		}

		free_cmd(cmd_list);
		free_all_tokens(tokens);
		free(input);
	}
    rl_clear_history();
    return 0;
}
