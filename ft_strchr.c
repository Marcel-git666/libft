/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:01:32 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/06 12:16:56 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    while (*s) {
        if (*s == c)
            return ((char *)s);
        s++;
    }
    if (*s == c) // Check if the null terminator matches 'c'
        return ((char *)s);
    return (NULL);
}