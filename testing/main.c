/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:39:46 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/06 12:18:30 by mmravec          ###   ########.fr       */
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
	test_strlen();
	test_toupper();
	test_tolower();
	test_strchr();

    return (0);
}

void test_isalpha(void)
{
    printf("A is alpha: %d\n", ft_isalpha('A'));
    printf("1 isn't alpha: %d\n", ft_isalpha('1'));
}
void test_isdigit(void)
{
	printf("1 is a digit: %d\n", ft_isdigit('1'));
    printf("a isn't a digit: %d\n", ft_isdigit('a'));
}
void test_isalnum(void)
{
	printf("A is alphanumeric: %d\n", ft_isalnum('A'));
    printf("1 is alphanumeric: %d\n", ft_isalnum('1'));
	printf("Space is not alphanumeric: %d\n", ft_isalnum(' '));
}
void test_isascii(void)
{
	char	c;

	c = 180;
	printf("A is ascii: %d\n", ft_isascii('A'));
    printf("1 is ascii: %d\n", ft_isascii('1'));
	printf("%c is not ascii: %d\n", c, ft_isascii(c));
}
void test_isprint(void)
{
	printf("A is printable: %d\n", ft_isprint('A'));
    printf("1 is printable: %d\n", ft_isprint('1'));
	printf("\\n is not printable: %d\n", ft_isprint('\n'));
	printf("DEL is not printable: %d\n", ft_isprint(127));
}

void test_strlen(void)
{
	printf("'Coding in C' has: %ld chars.\n", ft_strlen("Coding in C"));
	printf("Empty string has: %ld chars.\n", ft_strlen(""));
}

void test_toupper(void)
{
	char	c;

	c = 'b';
	printf("%c to upper is %c\n", c, ft_toupper(c)); 
	c = 'C';
	printf("%c to upper is %c\n", c, ft_toupper(c)); 
}

void test_tolower(void)
{
	char	c;

	c = 'B';
	printf("%c to lower is %c\n", c, ft_tolower(c)); 
	c = 'c';
	printf("%c to lower is %c\n", c, ft_tolower(c)); 
}

void test_strchr(void)
{
	char	c;
	char	*s = "Three Rings for the Elven-kings under the sky, "
				"Seven for the Dwarf-lords in their halls of stone, "
				"Nine for Mortal Men, doomed to die, "
				"One for the Dark Lord on his dark throne "
				"In the Land of Mordor where the Shadows lie. "
				"One Ring to rule them all, One Ring to find them, "
				"One Ring to bring them all and in the darkness bind them. "
				"In the Land of Mordor where the Shadows lie.";

	c = '.';
	printf("Looking for first occurence of character %c in string: %s\nFound: %s\n", c, s, ft_strchr(s, c));
}