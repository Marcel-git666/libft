/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:39:46 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/03 22:14:58 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "main.h"

int	main(void)

{
	printf("\n\n===============================\n");
	printf(    "=========== PART 1 ============\n");
	printf(    "===============================\n");
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
    return (0);
}

void test_isalpha(void)
{
    printf("A is alphanumeric: %d\n", ft_isalpha('A'));
    printf("1 isn't alphanumeric: %d\n", ft_isalpha('1'));
}
void test_isdigit(void)
{

}
void test_isalnum(void)
{

}
void test_isascii(void)
{

}
void test_isprint(void)
{

}
