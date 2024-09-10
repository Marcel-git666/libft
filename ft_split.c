/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:26:55 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/10 20:59:39 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *str, char c)
{
	int		words;
	int		is_inside_word;

	words = 0;
	is_inside_word = 0;
	while (*str)
	{
		if (*str == c)
		{
			is_inside_word = 0;
		}
		else
		{
			if (!is_inside_word)
			{
				words++;
				is_inside_word = 1;
			}
		}
		str++;
	}
	return (words);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((src[i] != '\0') && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*alloc_copy_word(char *current_word, int word_length)
{
	char	*word;

	word = (char *)malloc((word_length + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strncpy(word, current_word, word_length);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*current_word;
	int		word_length;
	int		words;

	word_length = 0;
	words = 0;
	result = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	while (*s || word_length > 0)
	{
		if ((*s == c) || *s == '\0')
		{
			if (word_length > 0)
				result[words++] = alloc_copy_word(current_word, word_length);
			word_length = 0;
		}
		else
			if (word_length++ == 0)
				current_word = (char *)s;
		s++;
	}
	result[words] = NULL;
	return (result);
}
