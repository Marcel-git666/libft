/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:39:46 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/09 14:48:03 by mmravec          ###   ########.fr       */
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
	test_strrchr();
	test_strncmp();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	 
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

void test_strrchr(void)
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

	c = 'l';
	printf("Looking for last occurence of character %c in string: %s\nFound: %s\n", c, s, ft_strrchr(s, c));
}

void test_strncmp(void)
{
	char	*s1 = "Three Rings for the Elven-kings";
	char	*s2 = "Three Rings for the elven-kings";
	int		n = 21;

	printf("Difference between s1 and s2 while comparing: %d chars is: %d\n", n, ft_strncmp(s1, s2, n));
}

void test_memset(void)
{
	char str[50];

   strcpy(str, "Welcome to testing ft_memset");
   puts(str);

   ft_memset(str, '#', 7);
   puts(str);

   strcpy(str, "Welcome to original memset");
   memset(str, '#', 7);
   puts(str);
}

void print_memory(const char *str, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '\0')
            printf("\\0");  
        else
            printf("%c", str[i]);
    }
    printf("\n");
}

void test_bzero(void)
{
	char str[50];

	strcpy(str, "Welcome to testing ft_bzero");
   	puts(str);

   	ft_bzero(str, 3);
    print_memory(str, ft_strlen("Welcome to testing ft_bzero") + 1); 

    // Test original bzero
    strcpy(str, "Welcome to original bzero");
    puts(str);

    bzero(str, 3);
    print_memory(str, ft_strlen("Welcome to testing bzero") + 1);
}

void test_memcpy(void)
{
	const char src[50] = "42 Prague";
   	char dest[50];
   	strcpy(dest,"Heloooo!!");
   	printf("Before ft_memcpy dest = %s\n", dest);
   	ft_memcpy(dest, src, ft_strlen(src) + 1);
   	printf("After ft_memcpy dest = %s\n", dest);
	strcpy(dest,"Heloooo!!");
   	printf("Before memcpy dest = %s\n", dest);
   	memcpy(dest, src, strlen(src) + 1);
   	printf("After memcpy dest = %s\n", dest);

}

void test_memmove(void)
{
const char src[50] = "42 Prague";
   	char dest[50];
   	strcpy(dest,"Heloooo!!");
   	printf("Before ft_memmove dest = %s\n", dest);
   	ft_memmove(dest, src, 3);
   	printf("After ft_memmove dest = %s\n", dest);
	strcpy(dest,"Heloooo!!");
   	printf("Before memmove dest = %s\n", dest);
   	memmove(dest, src, 3);
   	printf("After memmove dest = %s\n", dest);
}

void test_strlcpy(void)
{
char src[50] = "42 Prague";
    char dest[50];
    size_t n;

    // Test ft_strlcpy
    strcpy(dest, "Hello World!!");
    printf("Before ft_strlcpy dest = %s\n", dest);

    n = ft_strlcpy(dest, src, 5);  // Copy up to 4 chars + null terminator
    printf("After ft_strlcpy (5 bytes) dest = %s, return value = %zu\n", dest, n);

    strcpy(dest, "Hello World!!");
    printf("Before ft_strlcpy dest = %s\n", dest);

    n = ft_strlcpy(dest, src, sizeof(dest));  // Copy the entire string
    printf("After ft_strlcpy (entire src) dest = %s, return value = %zu\n", dest, n);

    // Test original strlcpy
    strcpy(dest, "Hello World!!");
    printf("Before strlcpy dest = %s\n", dest);

    n = strlcpy(dest, src, 5);  // Copy up to 4 chars + null terminator
    printf("After strlcpy (5 bytes) dest = %s, return value = %zu\n", dest, n);

    strcpy(dest, "Hello World!!");
    printf("Before strlcpy dest = %s\n", dest);

    n = strlcpy(dest, src, sizeof(dest));  // Copy the entire string
    printf("After strlcpy (entire src) dest = %s, return value = %zu\n", dest, n);
}

void test_strlcat(void) {
    char src[50] = "42 Prague";
    char dest[50];
    size_t n;

    // Test ft_strlcat
    strcpy(dest, "Hello ");
    printf("Before ft_strlcat dest = %s\n", dest);

    n = ft_strlcat(dest, src, 15);  // Append with enough space
    printf("After ft_strlcat (size 15) dest = %s, return value = %zu\n", dest, n);

    strcpy(dest, "Hello ");
    printf("Before ft_strlcat dest = %s\n", dest);

    n = ft_strlcat(dest, src, 10);  // Append but with limited space
    printf("After ft_strlcat (size 10) dest = %s, return value = %zu\n", dest, n);

    // Test original strlcat
    strcpy(dest, "Hello ");
    printf("Before strlcat dest = %s\n", dest);

    n = strlcat(dest, src, 15);  // Append with enough space
    printf("After strlcat (size 15) dest = %s, return value = %zu\n", dest, n);

    strcpy(dest, "Hello ");
    printf("Before strlcat dest = %s\n", dest);

    n = strlcat(dest, src, 10);  // Append but with limited space
    printf("After strlcat (size 10) dest = %s, return value = %zu\n", dest, n);
}