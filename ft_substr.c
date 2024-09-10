/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:40:36 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/09 21:59:21 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char            *substring;
    unsigned int    i;

    i = 0;
    substring = ft_calloc(len +1, sizeof(char));
    if (start >= ft_strlen(s))
    {
        substring[i] = '\0';
        return (substring);
    }
    while (i < len && s[start+i] != '\0')
    {
        substring[i] = s[start+i];
        i++;
    }
    substring[i] = '\0';
    return (substring);
}