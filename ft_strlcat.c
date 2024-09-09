/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:55:40 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/09 14:46:12 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char * restrict dst, const char * restrict src,
	size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dstsize == 0)
		return (len_src);
	if (dstsize <= len_dst)
	{
		return (dstsize + len_src);
	}
	while (src[i] != '\0' && len_dst + i < dstsize -1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	if (len_dst + i < dstsize)
		dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
