/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:53:31 by ktyu              #+#    #+#             */
/*   Updated: 2025/12/12 23:54:08 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*source;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	int a = 20;
// 	int b = 40;
// 	int c = 0;
// 	ft_memcpy(&b, &a, sizeof(int));
// 	memcpy(&c, &a, sizeof(int));
// 	printf("Integer test!\n");
// 	printf("Value of b after ft_memcpy: %d\n", b);
// 	printf("Value of c after memcpy   : %d\n", c);
// 	printf("String test!\n");
// 	char str[] = "AABBC";
// 	char dest[] = "ACSCA";
// 	char dest1[] = "ACSCA";
// 	ft_memcpy(dest, str, sizeof(str));
// 	memcpy(dest1, str, sizeof(str));
// 	printf("dest after ft_memcpy: %s\n", dest);
// 	printf("dest1 of c after memcpy   : %s\n", dest1);
// }