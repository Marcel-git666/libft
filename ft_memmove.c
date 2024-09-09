/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:35:30 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/09 13:13:55 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t      i;
    char        *csrc; 
    char        *cdst; 

    csrc = (char *)src;
    cdst = (char *)dst;
    i = 0;
    while (i < len)
    {
        cdst[i] = csrc[i];
        i++;
    }
    return (dst);
}