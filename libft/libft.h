/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:03:28 by ktyu              #+#    #+#             */
/*   Updated: 2026/09/09 20:14:48 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
int		ft_isalnum(int c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_append_char(char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strndup(const char *s, size_t n);
int		ft_strcmp(const char *s1, const char *s2);


#endif
