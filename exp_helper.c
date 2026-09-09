/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:47:32 by ktyu              #+#    #+#             */
/*   Updated: 2026/09/10 01:57:44 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env_value(char *key, char **envp, int last_status)
{
	int	len;
	int i;

	if (!key || !*key)
		return (ft_strdup(""));
	if (ft_strcmp(key, "?") == 0)
		return (ft_itoa(last_status));
	len = ft_strlen(key);
	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], key, len) == 0 && envp[i][len] == '=')
			return (ft_strdup(envp[i] + len + 1));
		i++;
	}
	return (ft_strdup(""));
}

static char		*extract_var(char *str, int *i)
{
	int		start;

	(*i)++;
	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_strdup("?"));
	}
	start = *i;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	return (ft_strndup(&str[start], *i - start));
}

static char *expand_var(char *str, char **envp, int last_status)
{
	char	*res;
	char	*var_name;
	char	*var_val;
	int		i;
	int		in_sq;
	int		in_dq;

	res = ft_strdup("");
	i = 0;
	in_sq = 0;
	in_dq = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !in_dq)
		{
			in_sq = !in_sq;
			res = ft_append_char(res, str[i++]);			
		}
		else if (str[i] == '"' && !in_sq)
		{
			in_dq = !in_dq;
			res = ft_append_char(res, str[i++]);		
		}
		else if (str[i] == '$' && !in_sq && (ft_isalnum(str[i + 1]) || str[i + 1] == '_' || str[i + 1] == '?'))
		{
			var_name = extract_var(str, &i);
			var_val = find_env_value(var_name, envp, last_status);
			res = ft_strjoin_free(res, var_val);
			free(var_name);
	
		}
		else
		{
			res = ft_append_char(res, str[i]);
			i++;
		}
	}
	return (res);
}

char	*strip_quotes(char *str)
{
	char	*clean;
	int		i;
	int		in_sq;
	int		in_dq;

	clean = ft_strdup("");
	i = 0;
	in_sq = 0;
	in_dq = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !in_dq)
		{
			in_sq = !in_sq;
			i++;
		}
		else if (str[i] == '"' && !in_sq)
		{
			in_dq = !in_dq;
			i++;
		}
		else
		{
			clean = ft_append_char(clean, str[i]);
			i++;
		}
	}
	return (clean);
}

void	expander(t_token *tokens, char **envp, int last_status)
{
	t_token	*curr;
	char	*expanded;
	char	*clean;

	curr = tokens;
	while (curr)
	{
		if (curr->type == TOKEN_WORD)
		{
			expanded = expand_var(curr->value, envp, last_status);
			
			clean = strip_quotes(expanded);
			
			free(curr->value);
			free(expanded);
			curr->value = clean;
		}
		curr = curr->next;
	}
}
