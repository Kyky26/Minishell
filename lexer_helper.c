/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:44:52 by ktyu              #+#    #+#             */
/*   Updated: 2026/08/13 01:50:36 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *new_token(char *value, t_token_type type)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = value;
	token->type = type;
	token->next = NULL;
	return (token);
}

void	add_token_behind(t_token **head, t_token *new)
{
	t_token	*curr;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	free_all_tokens(t_token *head)
{
	t_token *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->value);
		free(head);
		head = tmp;
	}
}

