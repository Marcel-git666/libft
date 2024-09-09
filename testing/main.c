/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:39:46 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/09 21:35:41 by mmravec          ###   ########.fr       */
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
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();
	printf("\n\n===============================\n");
	printf(    "=========== PART 2 ============\n");
	printf(    "===============================\n");
	
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


void test_memchr(void)
{
    const char s[] = "Hello, 42 Prague!";
    char *result;

    // Test ft_memchr
    result = ft_memchr(s, '4', sizeof(s));
    if (result != NULL)
        printf("ft_memchr found '4' at position: %ld\n", result - s);
    else
        printf("ft_memchr did not find '4'\n");

    result = ft_memchr(s, 'z', sizeof(s));
    if (result != NULL)
        printf("ft_memchr found 'z' at position: %ld\n", result - s);
    else
        printf("ft_memchr did not find 'z'\n");

    // Test original memchr
    result = memchr(s, '4', sizeof(s));
    if (result != NULL)
        printf("memchr found '4' at position: %ld\n", result - s);
    else
        printf("memchr did not find '4'\n");

    result = memchr(s, 'z', sizeof(s));
    if (result != NULL)
        printf("memchr found 'z' at position: %ld\n", result - s);
    else
        printf("memchr did not find 'z'\n");
}

void test_memcmp(void) {
    const char s1[] = "Hello, 42 Prague!";
    const char s2[] = "Hello, 42 Paris!";
    int result;

    size_t s1_len = strlen(s1); // Get the length of s1 (without null terminator)
    size_t s2_len = strlen(s2); // Get the length of s2 (without null terminator)
    size_t min_len = s1_len < s2_len ? s1_len : s2_len; // Find the smaller length

    // Test ft_memcmp: strings differ at byte 11
    result = ft_memcmp(s1, s2, min_len);  // Compare only up to the smaller length
    if (result == 0)
        printf("ft_memcmp: s1 and s2 are identical.\n");
    else
        printf("ft_memcmp: s1 and s2 differ at result = %d\n", result);

    // Test ft_memcmp: comparing the same string
    result = ft_memcmp(s1, s1, s1_len);  // Compare s1 with itself
    if (result == 0)
        printf("ft_memcmp: s1 and s1 are identical.\n");
    else
        printf("ft_memcmp: s1 and s1 differ at result = %d\n", result);

    // Test original memcmp for comparison
    result = memcmp(s1, s2, min_len);  // Compare only up to the smaller length
    if (result == 0)
        printf("memcmp: s1 and s2 are identical.\n");
    else
        printf("memcmp: s1 and s2 differ at result = %d\n", result);

	// Test memcmp: comparing the same string
    result = memcmp(s1, s1, s1_len);  // Compare s1 with itself
    if (result == 0)
        printf("memcmp: s1 and s1 are identical.\n");
    else
        printf("memcmp: s1 and s1 differ at result = %d\n", result);
}

void test_strnstr(void) {
    const char haystack1[] = "Foo Bar";
    const char needle1[] = "Bar";
    const char needle2[] = "Foo";
    const char haystack2[] = "Hello World";
    const char needle3[] = "World";
    const char needle4[] = "";
    char *result;

    // Test case 1: Search for "Bar" within 7 characters of "Foo Bar"
    result = ft_strnstr(haystack1, needle1, 7);
    if (result != NULL)
        printf("ft_strnstr found '%s' in '%s' within len=7: %s\n", needle1, haystack1, result);
    else
        printf("ft_strnstr did not find '%s' in '%s' within len=7\n", needle1, haystack1);

    // Test case 2: Search for "Bar" within 6 characters of "Foo Bar"
    result = ft_strnstr(haystack1, needle1, 6);
    if (result != NULL)
        printf("ft_strnstr found '%s' in '%s' within len=6: %s\n", needle1, haystack1, result);
    else
        printf("ft_strnstr did not find '%s' in '%s' within len=6\n", needle1, haystack1);

    // Test case 3: Search for "Foo" within 3 characters of "Foo Bar"
    result = ft_strnstr(haystack1, needle2, 3);
    if (result != NULL)
        printf("ft_strnstr found '%s' in '%s' within len=3: %s\n", needle2, haystack1, result);
    else
        printf("ft_strnstr did not find '%s' in '%s' within len=3\n", needle2, haystack1);

    // Test case 4: Search for "World" within 5 characters of "Hello World"
    result = ft_strnstr(haystack2, needle3, 5);
    if (result != NULL)
        printf("ft_strnstr found '%s' in '%s' within len=5: %s\n", needle3, haystack2, result);
    else
        printf("ft_strnstr did not find '%s' in '%s' within len=5\n", needle3, haystack2);

    // Test case 5: Search for a non-existent substring "Test" within "Foo Bar"
    result = ft_strnstr(haystack1, needle4, 7);
    if (result != NULL)
        printf("ft_strnstr found '%s' in '%s' within len=7: %s\n", needle4, haystack1, result);
    else
        printf("ft_strnstr did not find '%s' in '%s' within len=7\n", needle4, haystack1);

    // For comparison, let's use the standard strnstr
    printf("\nComparing with strnstr:\n");

    result = strnstr(haystack1, needle1, 7);
    if (result != NULL)
        printf("strnstr found '%s' in '%s' within len=7: %s\n", needle1, haystack1, result);
    else
        printf("strnstr did not find '%s' in '%s' within len=7\n", needle1, haystack1);

    result = strnstr(haystack1, needle1, 6);
    if (result != NULL)
        printf("strnstr found '%s' in '%s' within len=6: %s\n", needle1, haystack1, result);
    else
        printf("strnstr did not find '%s' in '%s' within len=6\n", needle1, haystack1);

    result = strnstr(haystack1, needle2, 3);
    if (result != NULL)
        printf("strnstr found '%s' in '%s' within len=3: %s\n", needle2, haystack1, result);
    else
        printf("strnstr did not find '%s' in '%s' within len=3\n", needle2, haystack1);

    result = strnstr(haystack2, needle3, 5);
    if (result != NULL)
        printf("strnstr found '%s' in '%s' within len=5: %s\n", needle3, haystack2, result);
    else
        printf("strnstr did not find '%s' in '%s' within len=5\n", needle3, haystack2);

    result = strnstr(haystack1, needle4, 7);
    if (result != NULL)
        printf("strnstr found '%s' in '%s' within len=7: %s\n", needle4, haystack1, result);
    else
        printf("strnstr did not find '%s' in '%s' within len=7\n", needle4, haystack1);
}

void test_atoi(void)
{
    const char *str1 = "42";
    const char *str2 = "-42";
    const char *str3 = "   1234abc";
    const char *str4 = "2147483647";      // INT_MAX
    const char *str5 = "-2147483648";     // INT_MIN
    const char *str6 = "2147483648";      // Overflow
    const char *str7 = "-2147483649";     // Underflow
    const char *str8 = "+987";            // Positive sign
    const char *str9 = "   -001234";      // Leading spaces and zeros
    int result;

    // Test case 1: Simple positive number
    result = ft_atoi(str1);
    printf("ft_atoi(\"%s\") = %d\n", str1, result);

    // Test case 2: Simple negative number
    result = ft_atoi(str2);
    printf("ft_atoi(\"%s\") = %d\n", str2, result);

    // Test case 3: Leading spaces and characters after the number
    result = ft_atoi(str3);
    printf("ft_atoi(\"%s\") = %d\n", str3, result);

    // Test case 4: INT_MAX
    result = ft_atoi(str4);
    printf("ft_atoi(\"%s\") = %d (INT_MAX is %d)\n", str4, result, INT_MAX);

    // Test case 5: INT_MIN
    result = ft_atoi(str5);
    printf("ft_atoi(\"%s\") = %d (INT_MIN is %d)\n", str5, result, INT_MIN);

    // Test case 6: Overflow (greater than INT_MAX)
    result = ft_atoi(str6);
    printf("ft_atoi(\"%s\") = %d (should handle overflow)\n", str6, result);

    // Test case 7: Underflow (less than INT_MIN)
    result = ft_atoi(str7);
    printf("ft_atoi(\"%s\") = %d (should handle underflow)\n", str7, result);

    // Test case 8: Positive number with explicit '+'
    result = ft_atoi(str8);
    printf("ft_atoi(\"%s\") = %d\n", str8, result);

    // Test case 9: Leading spaces and multiple zeros
    result = ft_atoi(str9);
    printf("ft_atoi(\"%s\") = %d\n", str9, result);

    // For comparison, let's use the standard atoi
    printf("\nComparing with atoi:\n");

    printf("atoi(\"%s\") = %d\n", str1, atoi(str1));
    printf("atoi(\"%s\") = %d\n", str2, atoi(str2));
    printf("atoi(\"%s\") = %d\n", str3, atoi(str3));
    printf("atoi(\"%s\") = %d (INT_MAX is %d)\n", str4, atoi(str4), INT_MAX);
    printf("atoi(\"%s\") = %d (INT_MIN is %d)\n", str5, atoi(str5), INT_MIN);
    printf("atoi(\"%s\") = %d (should handle overflow)\n", str6, atoi(str6));
    printf("atoi(\"%s\") = %d (should handle underflow)\n", str7, atoi(str7));
    printf("atoi(\"%s\") = %d\n", str8, atoi(str8));
    printf("atoi(\"%s\") = %d\n", str9, atoi(str9));
}

void test_calloc(void)
{
    int *arr1;
    int *arr2;
    size_t count = 5;
    size_t size = sizeof(int);

    // Test case 1: Using ft_calloc
    arr1 = (int *)ft_calloc(count, size);
    if (arr1 != NULL) {
        printf("ft_calloc allocated memory: ");
        for (size_t i = 0; i < count; i++) {
            printf("%d ", arr1[i]);  // Should print all zeros
        }
        printf("\n");
        free(arr1);  // Always free allocated memory after use
    } else {
        printf("ft_calloc failed to allocate memory.\n");
    }

    // Test case 2: Using standard calloc for comparison
    arr2 = (int *)calloc(count, size);
    if (arr2 != NULL) {
        printf("calloc allocated memory: ");
        for (size_t i = 0; i < count; i++) {
            printf("%d ", arr2[i]);  // Should also print all zeros
        }
        printf("\n");
        free(arr2);  // Free the memory after use
    } else {
        printf("calloc failed to allocate memory.\n");
    }
}

void test_strdup(void) {
    const char *str1 = "Hello, 42!";
    const char *str2 = "";
    const char *str3 = "A longer string for testing ft_strdup.";
    char *dup1, *dup2, *dup3;

    // Test case 1: Duplicate a simple string
    dup1 = ft_strdup(str1);
    if (dup1 != NULL) {
        printf("Original: \"%s\"\n", str1);
        printf("ft_strdup: \"%s\"\n", dup1);
        free(dup1);  // Free the duplicated string
    } else {
        printf("ft_strdup failed to duplicate \"%s\"\n", str1);
    }

    // Test case 2: Duplicate an empty string
    dup2 = ft_strdup(str2);
    if (dup2 != NULL) {
        printf("Original: \"%s\"\n", str2);
        printf("ft_strdup: \"%s\"\n", dup2);
        free(dup2);  // Free the duplicated string
    } else {
        printf("ft_strdup failed to duplicate an empty string.\n");
    }

    // Test case 3: Duplicate a longer string
    dup3 = ft_strdup(str3);
    if (dup3 != NULL) {
        printf("Original: \"%s\"\n", str3);
        printf("ft_strdup: \"%s\"\n", dup3);
        free(dup3);  // Free the duplicated string
    } else {
        printf("ft_strdup failed to duplicate \"%s\"\n", str3);
    }

    // Comparison with standard strdup:
    printf("\nComparing with strdup:\n");

    char *dup_std = strdup(str1);
    printf("strdup: \"%s\"\n", dup_std);
    free(dup_std);
}