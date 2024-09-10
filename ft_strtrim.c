/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:09:06 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/10 20:54:30 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char const *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *result;
    int     i;
    int     j;

    result = malloc((ft_strlen(s1)+ 1) * sizeof(char));
    if (!result)
        return (NULL);
    while (is_in_set(*s1, set))
        s1++;
    i = ft_strlen(s1) - 1;
    while (is_in_set(s1[i], set))
        i--;
    j = 0;
    while (j <= i)
    {
        result[j] = s1[j];
        j++;
    }
    result[j] = '\0';
    return (result);
}