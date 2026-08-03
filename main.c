/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:35:59 by ktyu              #+#    #+#             */
/*   Updated: 2026/08/04 00:55:38 by ktyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer = NULL;
    size_t size = 0;
    
    printf("minishell$ ");
    
    // getline automatically handles memory allocation
    if (getline(&buffer, &size, stdin) != -1) {
        printf("You typed: %s", buffer);
    }
    
    // Always free the buffer allocated by getline
    free(buffer);
    return 0;
}
