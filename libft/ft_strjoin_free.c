/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:02:54 by ktyu              #+#    #+#             */
/*   Updated: 2026/09/09 17:03:12 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joined)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = -1;
	while (++i < len1)
		joined[i] = s1[i];
	j = -1;
	while (++j < len2)
		joined[i + j] = s2[j];
	joined[i + j] = '\0';
	free(s1);
	free(s2);
	return (joined);
}
