/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:52:32 by ktyu              #+#    #+#             */
/*   Updated: 2025/12/06 18:08:03 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*temp;
	size_t	len;

	len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	temp = ptr;
	while (*s)
	{
		*temp = *s;
		s++;
		temp++;
	}
	*temp = '\0';
	return (ptr);
}

// #include <stdio.h>

// int main(void)
// {
//     char *s1 = "Hello, world!";
//     char *s2 = "";
//     size_t large_len = 100000; // very long string
//     char *s3 = malloc(large_len + 1);
//     if (!s3)
//     {
//         printf("Failed to allocate large string for test\n");
//         return 1;
//     }

//     // Fill the large string with 'A's and null terminate
//     for (size_t i = 0; i < large_len; i++)
//         s3[i] = 'A';
//     s3[large_len] = '\0';

//     // Test 1: Normal string
//     char *dup1 = ft_strdup(s1);
//     printf("Original: '%s', Duplicate: '%s'\n", s1, dup1);

//     // Test 2: Empty string
//     char *dup2 = ft_strdup(s2);
//     printf("Original: '%s', Duplicate: '%s'\n", s2, dup2);

//     // Test 3: Very long string
//     char *dup3 = ft_strdup(s3);
//     if (dup3)
//         printf("Very long str dup success. First 10 chars: %.10s\n", dup3);
//     else
//         printf("Failed to duplicate very long string\n");

//     // Free allocated memory
//     free(dup1);
//     free(dup2);
//     free(dup3);
//     free(s3);

//     return 0;
// }
