/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:01:21 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/15 21:28:41 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t      i;
    char        *csrc;
    char        *cdst;

    csrc = (char *)src;
    cdst = (char *)dst;
    i = 0;
    while (i < n)
    {
        cdst[i] = csrc[i];
        i++;
    }
    return (dst);
}
