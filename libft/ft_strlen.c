/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:18:06 by ktyu              #+#    #+#             */
/*   Updated: 2025/12/07 17:22:41 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%ld\n", ft_strlen("Gaoo")); //4
// 	printf("%ld\n", ft_strlen("90wwe eas3")); //10
// }//size_t is 64 bits can take higher value than int (32 bits)