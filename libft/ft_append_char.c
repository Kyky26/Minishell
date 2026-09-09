/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:01:08 by ktyu              #+#    #+#             */
/*   Updated: 2026/09/09 17:01:39 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_char(char *str, char c)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 2)); // Allocate space for len + char + '\0'
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);
	return (new_str);
}
