/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:11:56 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/10 21:39:13 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev_char_tab(char *tab, int size)
{
	char	temp;
	int		start;
	int		end;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		start++;
		end--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		temp;
	int		is_negative;

	if (n < 0)
		is_negative = 1;
	else
		is_negative = 0;
	i = 0;
	result = (char *)malloc(12 * sizeof(char));
	if (!result)
		return (NULL);
	if (n == 0)
	{
		result[0] = '0';
		i++;
	}
	while (n != 0)
	{
		temp = n % 10;
		if (is_negative)
			temp *= (-1);
		result[i] = temp + '0';
		n /= 10;
		i++;
	}
	if (is_negative)
		result[i++] = '-';
	result[i] = '\0';
	ft_rev_char_tab(result, i);
	return (result);
}