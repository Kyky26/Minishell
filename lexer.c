/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 00:29:36 by ktyu              #+#    #+#             */
/*   Updated: 2026/09/10 01:43:01 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_operator(char *str, int i, t_token **head)
{ 
	if (str[i] == '|')
		add_token_behind(head, new_token(ft_strdup("|"), TOKEN_PIPE));
	else if (str[i] == '<' && str[i + 1] == '<')
	{
		add_token_behind(head, new_token(ft_strdup("<<"), TOKEN_HEREDOC));
		return (i + 2);
	}
	else if (str[i] == '>' && str[i + 1] == '>')
	{
		add_token_behind(head, new_token(ft_strdup(">>"), TOKEN_APPEND));
		return (i + 2);
	}
	else if (str[i] == '<')
    	add_token_behind(head, new_token(ft_strdup("<"), TOKEN_REDIR_IN));
	else if (str[i] == '>')
    	add_token_behind(head, new_token(ft_strdup(">"), TOKEN_REDIR_OUT));
	return (i + 1);
}

int	handle_word(char *str, int i, t_token **head)
{
	int		start;
	char	quote;
	char	*word;

	start = i;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '|' 
			|| str[i] == '<' || str[i] == '>')
			break ;
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				i++;
			if (str[i])
				i++;
		}
		else
			i++;
	}
	word = ft_strndup(&str[start], i - start);
	add_token_behind(head, new_token(word, TOKEN_WORD));
	return (i);
}

t_token	*lexer(char *line)
{
	t_token *head;
	int		i;

	head = NULL;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (line[i] == '|' || line[i] == '<' || line[i] == '>')
			i = handle_operator(line, i, &head);
		else
			i = handle_word(line, i, &head);
	}
	return (head);
}
