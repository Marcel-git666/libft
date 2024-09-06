/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:53:17 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/06 17:15:44 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    int  i;

    i = (int)ft_strlen(s) - 1;

    while (i >= 0) {
        if (s[i] == c)
            return ((char *)&s[i]);
        i--;
    }
    return (NULL);
}