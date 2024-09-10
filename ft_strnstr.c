/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:46:11 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/10 20:54:29 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t  len_str;
	size_t	len_to_find;
	size_t 	i;
	size_t 	j;

	i = 0;
	len_str = ft_strlen(haystack);
	len_to_find = ft_strlen(needle);
	while (haystack[i] != '\0' && (len_str - i >= len_to_find) && (i <= len - len_to_find))
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] && j < len_to_find)
				j++;
			if (j == len_to_find)
				return ((char *)(haystack+i));
		}
		i++;
	}
	if (len_to_find == 0)
		return ((char *)haystack);
	return (0);
}
