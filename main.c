/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:35:59 by ktyu              #+#    #+#             */
/*   Updated: 2026/08/10 23:45:23 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

int main(int argc, char **argv, char **envp) {
    char *input;

	(void)argc;
	(void)argv;
	(void)envp;

    // Read a line from the user
	while (1)
	{
		input = readline("minishell$ ");

		if (input == NULL)
		{
			write(1, "exit\n", 5);
			break ; // EOF encountered
		}

		// Check if the input is not empty, then add to arrow-key history
		if (*input != '\0') {
			add_history(input);
		}

		printf("You entered: %s\n", input);

		// Free the dynamically allocated memory
		free(input);	
	}
    rl_clear_history();
    return 0;
}
