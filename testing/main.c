/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:39:46 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/10 21:31:00 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "main.h"
#include "utils.h"

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
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();

	
    return (0);
}

void test_isalpha(void) {
    printf(COLOR_BLUE "====== Test ft_isalpha ======\n" COLOR_RESET);
    assert_int_equal(ft_isalpha('A'), 1, "'A' is alpha");
    assert_int_equal(ft_isalpha('1'), 0, "'1' is not alpha");
}

void test_isdigit(void) {
    printf(COLOR_BLUE "====== Test ft_isdigit ======\n" COLOR_RESET);
    assert_int_equal(ft_isdigit('1'), 1, "'1' is a digit");
    assert_int_equal(ft_isdigit('a'), 0, "'a' is not a digit");
}

void test_isalnum(void) {
    printf(COLOR_BLUE "====== Test ft_isalnum ======\n" COLOR_RESET);
    assert_int_equal(ft_isalnum('A'), 1, "'A' is alphanumeric");
    assert_int_equal(ft_isalnum('1'), 1, "'1' is alphanumeric");
    assert_int_equal(ft_isalnum(' '), 0, "' ' is not alphanumeric");
}

void test_isascii(void) {
    char c = 180;
    printf(COLOR_BLUE "====== Test ft_isascii ======\n" COLOR_RESET);
    assert_int_equal(ft_isascii('A'), 1, "'A' is ASCII");
    assert_int_equal(ft_isascii('1'), 1, "'1' is ASCII");
    assert_int_equal(ft_isascii(c), 0, "'180' is not ASCII");
}

void test_isprint(void) {
    printf(COLOR_BLUE "====== Test ft_isprint ======\n" COLOR_RESET);
    assert_int_equal(ft_isprint('A'), 1, "'A' is printable");
    assert_int_equal(ft_isprint('1'), 1, "'1' is printable");
    assert_int_equal(ft_isprint('\n'), 0, "'\\n' is not printable");
    assert_int_equal(ft_isprint(127), 0, "DEL is not printable");
}

void test_strlen(void) {
    printf(COLOR_BLUE "====== Test ft_strlen ======\n" COLOR_RESET);
    assert_int_equal(ft_strlen("Coding in C"), 11, "'Coding in C' has 11 characters");
    assert_int_equal(ft_strlen(""), 0, "Empty string has 0 characters");
}

void test_toupper(void) {
    printf(COLOR_BLUE "====== Test ft_toupper ======\n" COLOR_RESET);
    assert_int_equal(ft_toupper('b'), 'B', "'b' to upper is 'B'");
    assert_int_equal(ft_toupper('C'), 'C', "'C' to upper remains 'C'");
}

void test_tolower(void) {
    printf(COLOR_BLUE "====== Test ft_tolower ======\n" COLOR_RESET);
    assert_int_equal(ft_tolower('B'), 'b', "'B' to lower is 'b'");
    assert_int_equal(ft_tolower('c'), 'c', "'c' to lower remains 'c'");
}


void test_strchr(void) {
    char c = '.';
    char *s = "Three Rings for the Elven-kings under the sky...";
    
    printf(COLOR_BLUE "====== Test ft_strchr ======\n" COLOR_RESET);
    
    // Compare the result of ft_strchr with standard strchr
    assert_str_equal(ft_strchr(s, c), strchr(s, c), "Looking for first occurrence of '.'");
}

void test_strrchr(void) {
    char c = 'L';
    char *s = "The Dark Lord in the Land of Mordor.";
    
    printf(COLOR_BLUE "====== Test ft_strrchr ======\n" COLOR_RESET);

    // Get results from ft_strrchr and strrchr
    char *result_ft = ft_strrchr(s, c);
    char *result_std = strrchr(s, c);
    
    // Check if either result is NULL before passing to assert_str_equal
    if (result_ft == NULL || result_std == NULL) {
        if (result_ft == result_std) {
            printf(COLOR_GREEN "PASS: " COLOR_RESET "Both functions returned NULL\n");
        } else {
            printf(COLOR_RED "FAIL: " COLOR_RESET "ft_strrchr returned %s, but strrchr returned %s\n",
                   result_ft == NULL ? "NULL" : result_ft, 
                   result_std == NULL ? "NULL" : result_std);
        }
    } else {
        // Perform comparison only if both are non-NULL
        assert_str_equal(result_ft, result_std, "Looking for last occurrence of 'l'");
    }
}


void test_strncmp(void) {
    char *s1 = "Three Rings for the Elven-kings";
    char *s2 = "Three Rings for the elven-kings";
    int n = 21;

    printf(COLOR_BLUE "====== Test ft_strncmp ======\n" COLOR_RESET);
    
    // Get results from ft_strncmp and standard strncmp
    int result_ft = ft_strncmp(s1, s2, n);
    int result_std = strncmp(s1, s2, n);
    
    // Use assert_int_equal to compare the two results
    if (result_ft == result_std) {
        printf(COLOR_GREEN "PASS: " COLOR_RESET "Comparing first %d chars of s1 and s2\n", n);
    } else {
        printf(COLOR_RED "FAIL: " COLOR_RESET "ft_strncmp returned %d, but strncmp returned %d\n", result_ft, result_std);
    }
}


void test_memset(void) {
    char str[50];

    printf(COLOR_BLUE "====== Test ft_memset ======\n" COLOR_RESET);

    strcpy(str, "Welcome to testing ft_memset");
    ft_memset(str, '#', 7);
    printf("ft_memset result: %s\n", str);

    strcpy(str, "Welcome to original memset");
    memset(str, '#', 7);
    printf("Original memset result: %s\n", str);
}


void test_bzero(void) {
    char str[50];

    printf(COLOR_BLUE "====== Test ft_bzero ======\n" COLOR_RESET);

    // Test case 1: ft_bzero
    strcpy(str, "Welcome to testing ft_bzero");
    puts(str);
    ft_bzero(str, 3);
    printf("After ft_bzero (3 bytes cleared):\n");
    print_memory(str, ft_strlen("Welcome to testing ft_bzero") + 1);

    // Test case 2: Original bzero
    strcpy(str, "Welcome to original bzero");
    puts(str);
    bzero(str, 3);
    printf("After original bzero (3 bytes cleared):\n");
    print_memory(str, ft_strlen("Welcome to testing bzero") + 1);
}

void test_memcpy(void) {
    const char src[50] = "42 Prague";
    char dest[50];

    printf(COLOR_BLUE "====== Test ft_memcpy ======\n" COLOR_RESET);

    // Test case 1: ft_memcpy
    strcpy(dest, "Heloooo!!");
    printf("Before ft_memcpy dest = %s\n", dest);
    ft_memcpy(dest, src, ft_strlen(src) + 1);  // Copying the entire string
    printf("After ft_memcpy dest = %s\n", dest);
    assert_str_equal(dest, "42 Prague", "ft_memcpy copied string correctly");

    // Test case 2: Original memcpy
    strcpy(dest, "Heloooo!!");
    printf("Before memcpy dest = %s\n", dest);
    memcpy(dest, src, strlen(src) + 1);
    printf("After memcpy dest = %s\n", dest);
    assert_str_equal(dest, "42 Prague", "Original memcpy copied string correctly");
}

void test_memmove(void) {
    const char src[50] = "42 Prague";
    char ft_dest[50];
    char orig_dest[50];

    printf(COLOR_BLUE "====== Test ft_memmove vs memmove ======\n" COLOR_RESET);

    // Setup initial destination string
    strcpy(ft_dest, "Heloooo!!");
    strcpy(orig_dest, "Heloooo!!");

    // Apply ft_memmove and memmove
    printf("Before memmove: dest = %s\n", orig_dest);
    ft_memmove(ft_dest, src, 3);  // Copying 3 bytes using ft_memmove
    memmove(orig_dest, src, 3);   // Copying 3 bytes using standard memmove
    printf("After ft_memmove: dest = %s\n", ft_dest);
    printf("After memmove: dest = %s\n", orig_dest);

    // Compare the results of ft_memmove and memmove
    if (strcmp(ft_dest, orig_dest) == 0) {
        printf(COLOR_GREEN "PASS: ft_memmove behaves the same as memmove\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_memmove differs from memmove\n" COLOR_RESET);
    }
}

void test_strlcpy(void) {
    char src[50] = "42 Prague";
    char ft_dest[50];
    char orig_dest[50];
    size_t n;

    printf(COLOR_BLUE "====== Test ft_strlcpy vs strlcpy ======\n" COLOR_RESET);

    // Test ft_strlcpy
    strcpy(ft_dest, "Hello World!!");
    printf("Before ft_strlcpy: dest = %s\n", ft_dest);
    n = ft_strlcpy(ft_dest, src, 5);  // Copy up to 4 chars + null terminator
    printf("After ft_strlcpy (5 bytes): dest = %s, return value = %zu\n", ft_dest, n);

    // Compare with original strlcpy
    strcpy(orig_dest, "Hello World!!");
    n = strlcpy(orig_dest, src, 5);  // Copy up to 4 chars + null terminator
    printf("After strlcpy (5 bytes): dest = %s, return value = %zu\n", orig_dest, n);

    if (strcmp(ft_dest, orig_dest) == 0 && n == strlcpy(orig_dest, src, 5)) {
        printf(COLOR_GREEN "PASS: ft_strlcpy matches strlcpy for 5 bytes\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_strlcpy differs from strlcpy for 5 bytes\n" COLOR_RESET);
    }

    // Test ft_strlcpy with full size
    strcpy(ft_dest, "Hello World!!");
    n = ft_strlcpy(ft_dest, src, sizeof(ft_dest));  // Copy the entire string
    printf("After ft_strlcpy (entire src): dest = %s, return value = %zu\n", ft_dest, n);

    strcpy(orig_dest, "Hello World!!");
    n = strlcpy(orig_dest, src, sizeof(orig_dest));  // Copy the entire string
    printf("After strlcpy (entire src): dest = %s, return value = %zu\n", orig_dest, n);

    if (strcmp(ft_dest, orig_dest) == 0 && n == strlcpy(orig_dest, src, sizeof(orig_dest))) {
        printf(COLOR_GREEN "PASS: ft_strlcpy matches strlcpy for full size\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_strlcpy differs from strlcpy for full size\n" COLOR_RESET);
    }
}

void test_strlcat(void) {
    char src[50] = "42 Prague";
    char ft_dest[50];
    char orig_dest[50];
    size_t n;

    printf(COLOR_BLUE "====== Test ft_strlcat vs strlcat ======\n" COLOR_RESET);

    // Test ft_strlcat
    strcpy(ft_dest, "Hello ");
    printf("Before ft_strlcat: dest = %s\n", ft_dest);
    n = ft_strlcat(ft_dest, src, 15);  // Append with enough space
    printf("After ft_strlcat (size 15): dest = %s, return value = %zu\n", ft_dest, n);

    // Compare with original strlcat
    strcpy(orig_dest, "Hello ");
    n = strlcat(orig_dest, src, 15);  // Append with enough space
    printf("After strlcat (size 15): dest = %s, return value = %zu\n", orig_dest, n);

    if (strcmp(ft_dest, orig_dest) == 0 && n == (strlen("Hello ") + strlen("42 Prague"))) {
        printf(COLOR_GREEN "PASS: ft_strlcat matches strlcat for size 15\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_strlcat differs from strlcat for size 15\n" COLOR_RESET);
        printf("Detailed comparison:\n");
        printf("Expected dest = '%s', Actual ft_strlcat dest = '%s'\n", orig_dest, ft_dest);
        printf("Expected return value = %zu, Actual return value = %zu\n",
               strlen("Hello ") + strlen("42 Prague"), n);
    }

    // Test ft_strlcat with limited space
    strcpy(ft_dest, "Hello ");
    n = ft_strlcat(ft_dest, src, 10);  // Append but with limited space
    printf("After ft_strlcat (size 10): dest = %s, return value = %zu\n", ft_dest, n);

    strcpy(orig_dest, "Hello ");
    n = strlcat(orig_dest, src, 10);  // Append but with limited space
    printf("After strlcat (size 10): dest = %s, return value = %zu\n", orig_dest, n);

    if (strcmp(ft_dest, orig_dest) == 0 && n == (strlen("Hello ") + strlen("42 Prague"))) {
        printf(COLOR_GREEN "PASS: ft_strlcat matches strlcat for size 10\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_strlcat differs from strlcat for size 10\n" COLOR_RESET);
        printf("Detailed comparison:\n");
        printf("Expected dest = '%s', Actual ft_strlcat dest = '%s'\n", orig_dest, ft_dest);
        printf("Expected return value = %zu, Actual return value = %zu\n",
               strlen("Hello ") + strlen("42 Prague"), n);
    }
}

void test_memchr(void) {
    const char s[] = "Hello, 42 Prague!";
    char *ft_result;
    char *orig_result;

    printf(COLOR_BLUE "====== Test ft_memchr vs memchr ======\n" COLOR_RESET);

    // Test ft_memchr
    ft_result = ft_memchr(s, '4', sizeof(s));
    if (ft_result != NULL)
        printf("ft_memchr found '4' at position: %ld\n", ft_result - s);
    else
        printf("ft_memchr did not find '4'\n");

    orig_result = memchr(s, '4', sizeof(s));
    if (orig_result != NULL)
        printf("memchr found '4' at position: %ld\n", orig_result - s);
    else
        printf("memchr did not find '4'\n");

    // Compare results
    if (ft_result == orig_result) {
        printf(COLOR_GREEN "PASS: ft_memchr matches memchr for '4'\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_memchr differs from memchr for '4'\n" COLOR_RESET);
    }

    // Test ft_memchr with different character
    ft_result = ft_memchr(s, 'z', sizeof(s));
    if (ft_result != NULL)
        printf("ft_memchr found 'z' at position: %ld\n", ft_result - s);
    else
        printf("ft_memchr did not find 'z'\n");

    orig_result = memchr(s, 'z', sizeof(s));
    if (orig_result != NULL)
        printf("memchr found 'z' at position: %ld\n", orig_result - s);
    else
        printf("memchr did not find 'z'\n");

    // Compare results
    if (ft_result == orig_result) {
        printf(COLOR_GREEN "PASS: ft_memchr matches memchr for 'z'\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_memchr differs from memchr for 'z'\n" COLOR_RESET);
    }
}

void test_memcmp(void) {
    const char s1[] = "Hello, 42 Prague!";
    const char s2[] = "Hello, 42 Paris!";
    int ft_result;
    int orig_result;

    size_t s1_len = strlen(s1); // Get the length of s1 (without null terminator)
    size_t s2_len = strlen(s2); // Get the length of s2 (without null terminator)
    size_t min_len = s1_len < s2_len ? s1_len : s2_len; // Find the smaller length

    printf(COLOR_BLUE "====== Test ft_memcmp vs memcmp ======\n" COLOR_RESET);

    // Test ft_memcmp
    ft_result = ft_memcmp(s1, s2, min_len);  // Compare only up to the smaller length
    if (ft_result == 0)
        printf("ft_memcmp: s1 and s2 are identical.\n");
    else
        printf("ft_memcmp: s1 and s2 differ at result = %d\n", ft_result);

    // Test original memcmp
    orig_result = memcmp(s1, s2, min_len);  // Compare only up to the smaller length
    if (orig_result == 0)
        printf("memcmp: s1 and s2 are identical.\n");
    else
        printf("memcmp: s1 and s2 differ at result = %d\n", orig_result);

    // Compare results
    if (ft_result == orig_result) {
        printf(COLOR_GREEN "PASS: ft_memcmp matches memcmp for min_len\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_memcmp differs from memcmp for min_len\n" COLOR_RESET);
    }

    // Test ft_memcmp with same string
    ft_result = ft_memcmp(s1, s1, s1_len);  // Compare s1 with itself
    if (ft_result == 0)
        printf("ft_memcmp: s1 and s1 are identical.\n");
    else
        printf("ft_memcmp: s1 and s1 differ at result = %d\n", ft_result);

    // Test original memcmp with same string
    orig_result = memcmp(s1, s1, s1_len);  // Compare s1 with itself
    if (orig_result == 0)
        printf("memcmp: s1 and s1 are identical.\n");
    else
        printf("memcmp: s1 and s1 differ at result = %d\n", orig_result);

    // Compare results
    if (ft_result == orig_result) {
        printf(COLOR_GREEN "PASS: ft_memcmp matches memcmp for identical strings\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_memcmp differs from memcmp for identical strings\n" COLOR_RESET);
    }
}

void test_strnstr(void) {
    const char haystack1[] = "Foo Bar";
    const char needle1[] = "Bar";
    const char needle2[] = "Foo";
    const char haystack2[] = "Hello World";
    const char needle3[] = "World";
    const char needle4[] = "";
    char *ft_result;
    char *orig_result;

    printf(COLOR_BLUE "====== Test ft_strnstr vs strnstr ======\n" COLOR_RESET);

    // Test case 1: Search for "Bar" within 7 characters of "Foo Bar"
    ft_result = ft_strnstr(haystack1, needle1, 7);
    orig_result = strnstr(haystack1, needle1, 7);
    printf("ft_strnstr (len=7) found '%s' in '%s': %s\n", needle1, haystack1, ft_result ? ft_result : "Not found");
    printf("strnstr (len=7) found '%s' in '%s': %s\n", needle1, haystack1, orig_result ? orig_result : "Not found");
    if (ft_result == orig_result || (ft_result && orig_result && strcmp(ft_result, orig_result) == 0)) {
        printf(COLOR_GREEN "PASS: ft_strnstr matches strnstr for len=7\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_strnstr differs from strnstr for len=7\n" COLOR_RESET);
    }

    // Test case 2: Search for "Bar" within 6 characters of "Foo Bar"
    ft_result = ft_strnstr(haystack1, needle1, 6);
    orig_result = strnstr(haystack1, needle1, 6);
    printf("ft_strnstr (len=6) found '%s' in '%s': %s\n", needle1, haystack1, ft_result ? ft_result : "Not found");
    printf("strnstr (len=6) found '%s' in '%s': %s\n", needle1, haystack1, orig_result ? orig_result : "Not found");
    if (ft_result == orig_result || (ft_result && orig_result && strcmp(ft_result, orig_result) == 0)) {
        printf(COLOR_GREEN "PASS: ft_strnstr matches strnstr for len=6\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_strnstr differs from strnstr for len=6\n" COLOR_RESET);
    }

    // Test case 3: Search for "Foo" within 3 characters of "Foo Bar"
    ft_result = ft_strnstr(haystack1, needle2, 3);
    orig_result = strnstr(haystack1, needle2, 3);
    printf("ft_strnstr (len=3) found '%s' in '%s': %s\n", needle2, haystack1, ft_result ? ft_result : "Not found");
    printf("strnstr (len=3) found '%s' in '%s': %s\n", needle2, haystack1, orig_result ? orig_result : "Not found");
    if (ft_result == orig_result || (ft_result && orig_result && strcmp(ft_result, orig_result) == 0)) {
        printf(COLOR_GREEN "PASS: ft_strnstr matches strnstr for len=3\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_strnstr differs from strnstr for len=3\n" COLOR_RESET);
    }

    // Test case 4: Search for "World" within 5 characters of "Hello World"
    ft_result = ft_strnstr(haystack2, needle3, 5);
    orig_result = strnstr(haystack2, needle3, 5);
    printf("ft_strnstr (len=5) found '%s' in '%s': %s\n", needle3, haystack2, ft_result ? ft_result : "Not found");
    printf("strnstr (len=5) found '%s' in '%s': %s\n", needle3, haystack2, orig_result ? orig_result : "Not found");
    if (ft_result == orig_result || (ft_result && orig_result && strcmp(ft_result, orig_result) == 0)) {
        printf(COLOR_GREEN "PASS: ft_strnstr matches strnstr for len=5\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_strnstr differs from strnstr for len=5\n" COLOR_RESET);
    }

    // Test case 5: Search for an empty needle within "Foo Bar"
    ft_result = ft_strnstr(haystack1, needle4, 7);
    orig_result = strnstr(haystack1, needle4, 7);
    printf("ft_strnstr (len=7) found '%s' in '%s': %s\n", needle4, haystack1, ft_result ? ft_result : "Not found");
    printf("strnstr (len=7) found '%s' in '%s': %s\n", needle4, haystack1, orig_result ? orig_result : "Not found");
    if (ft_result == orig_result || (ft_result && orig_result && strcmp(ft_result, orig_result) == 0)) {
        printf(COLOR_GREEN "PASS: ft_strnstr matches strnstr for len=7 with empty needle\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_strnstr differs from strnstr for len=7 with empty needle\n" COLOR_RESET);
    }
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
    int ft_result, std_result;

    printf(COLOR_BLUE "====== Test ft_atoi vs atoi ======\n" COLOR_RESET);

    // Test case 1: Simple positive number
    ft_result = ft_atoi(str1);
    std_result = atoi(str1);
    if (ft_result == std_result)
        printf(COLOR_GREEN "PASS: ft_atoi(\"%s\") = %d\n" COLOR_RESET, str1, ft_result);
    else
        printf(COLOR_RED "FAIL: ft_atoi(\"%s\") = %d, expected %d\n" COLOR_RESET, str1, ft_result, std_result);

    // Test case 2: Simple negative number
    ft_result = ft_atoi(str2);
    std_result = atoi(str2);
    if (ft_result == std_result)
        printf(COLOR_GREEN "PASS: ft_atoi(\"%s\") = %d\n" COLOR_RESET, str2, ft_result);
    else
        printf(COLOR_RED "FAIL: ft_atoi(\"%s\") = %d, expected %d\n" COLOR_RESET, str2, ft_result, std_result);

    // Test case 3: Leading spaces and characters after the number
    ft_result = ft_atoi(str3);
    std_result = atoi(str3);
    if (ft_result == std_result)
        printf(COLOR_GREEN "PASS: ft_atoi(\"%s\") = %d\n" COLOR_RESET, str3, ft_result);
    else
        printf(COLOR_RED "FAIL: ft_atoi(\"%s\") = %d, expected %d\n" COLOR_RESET, str3, ft_result, std_result);

    // Test case 4: INT_MAX
    ft_result = ft_atoi(str4);
    std_result = atoi(str4);
    if (ft_result == std_result)
        printf(COLOR_GREEN "PASS: ft_atoi(\"%s\") = %d (INT_MAX is %d)\n" COLOR_RESET, str4, ft_result, INT_MAX);
    else
        printf(COLOR_RED "FAIL: ft_atoi(\"%s\") = %d, expected %d (INT_MAX is %d)\n" COLOR_RESET, str4, ft_result, std_result, INT_MAX);

    // Test case 5: INT_MIN
    ft_result = ft_atoi(str5);
    std_result = atoi(str5);
    if (ft_result == std_result)
        printf(COLOR_GREEN "PASS: ft_atoi(\"%s\") = %d (INT_MIN is %d)\n" COLOR_RESET, str5, ft_result, INT_MIN);
    else
        printf(COLOR_RED "FAIL: ft_atoi(\"%s\") = %d, expected %d (INT_MIN is %d)\n" COLOR_RESET, str5, ft_result, std_result, INT_MIN);

    // Test case 6: Overflow (greater than INT_MAX)
    ft_result = ft_atoi(str6);
    std_result = atoi(str6);
    if (ft_result == std_result)
        printf(COLOR_GREEN "PASS: ft_atoi(\"%s\") = %d (should handle overflow)\n" COLOR_RESET, str6, ft_result);
    else
        printf(COLOR_RED "FAIL: ft_atoi(\"%s\") = %d, expected %d (should handle overflow)\n" COLOR_RESET, str6, ft_result, std_result);

    // Test case 7: Underflow (less than INT_MIN)
    ft_result = ft_atoi(str7);
    std_result = atoi(str7);
    if (ft_result == std_result)
        printf(COLOR_GREEN "PASS: ft_atoi(\"%s\") = %d (should handle underflow)\n" COLOR_RESET, str7, ft_result);
    else
        printf(COLOR_RED "FAIL: ft_atoi(\"%s\") = %d, expected %d (should handle underflow)\n" COLOR_RESET, str7, ft_result, std_result);

    // Test case 8: Positive number with explicit '+'
    ft_result = ft_atoi(str8);
    std_result = atoi(str8);
    if (ft_result == std_result)
        printf(COLOR_GREEN "PASS: ft_atoi(\"%s\") = %d\n" COLOR_RESET, str8, ft_result);
    else
        printf(COLOR_RED "FAIL: ft_atoi(\"%s\") = %d, expected %d\n" COLOR_RESET, str8, ft_result, std_result);

    // Test case 9: Leading spaces and multiple zeros
    ft_result = ft_atoi(str9);
    std_result = atoi(str9);
    if (ft_result == std_result)
        printf(COLOR_GREEN "PASS: ft_atoi(\"%s\") = %d\n" COLOR_RESET, str9, ft_result);
    else
        printf(COLOR_RED "FAIL: ft_atoi(\"%s\") = %d, expected %d\n" COLOR_RESET, str9, ft_result, std_result);
}

void test_calloc(void) {
    int *arr1;
    int *arr2;
    size_t count = 5;
    size_t size = sizeof(int);

    printf(COLOR_BLUE "====== Test ft_calloc ======\n" COLOR_RESET);

    // Test case 1: Using ft_calloc
    arr1 = (int *)ft_calloc(count, size);
    if (arr1 != NULL) {
        assert_all_zeros(arr1, count, "ft_calloc allocated and zeroed memory");
        free(arr1);  // Always free allocated memory after use
    } else {
        printf(COLOR_RED "FAIL: ft_calloc failed to allocate memory.\n" COLOR_RESET);
    }

    // Test case 2: Using standard calloc for comparison
    arr2 = (int *)calloc(count, size);
    if (arr2 != NULL) {
        assert_all_zeros(arr2, count, "calloc allocated and zeroed memory");
        free(arr2);  // Free the memory after use
    } else {
        printf(COLOR_RED "FAIL: calloc failed to allocate memory.\n" COLOR_RESET);
    }
}

void test_strdup(void) {
    const char *str1 = "Hello, 42!";
    const char *str2 = "";
    const char *str3 = "A longer string for testing ft_strdup.";
    char *dup1, *dup2, *dup3;

    printf(COLOR_BLUE "====== Test ft_strdup ======\n" COLOR_RESET);

    // Test case 1: Duplicate a simple string
    dup1 = ft_strdup(str1);
    if (dup1 != NULL) {
        assert_str_equal(dup1, str1, "ft_strdup duplicated simple string");
        free(dup1);
    } else {
        printf(COLOR_RED "FAIL: ft_strdup failed to duplicate \"%s\"\n" COLOR_RESET, str1);
    }

    // Test case 2: Duplicate an empty string
    dup2 = ft_strdup(str2);
    if (dup2 != NULL) {
        assert_str_equal(dup2, str2, "ft_strdup duplicated empty string");
        free(dup2);
    } else {
        printf(COLOR_RED "FAIL: ft_strdup failed to duplicate an empty string.\n" COLOR_RESET);
    }

    // Test case 3: Duplicate a longer string
    dup3 = ft_strdup(str3);
    if (dup3 != NULL) {
        assert_str_equal(dup3, str3, "ft_strdup duplicated longer string");
        free(dup3);
    } else {
        printf(COLOR_RED "FAIL: ft_strdup failed to duplicate \"%s\"\n" COLOR_RESET, str3);
    }

    // Comparison with standard strdup
    printf(COLOR_BLUE "\nComparing with standard strdup:\n" COLOR_RESET);
    char *dup_std = strdup(str1);
    if (dup_std != NULL) {
        assert_str_equal(dup_std, str1, "Standard strdup duplicated string");
        free(dup_std);
    } else {
        printf(COLOR_RED "FAIL: Standard strdup failed to duplicate \"%s\"\n" COLOR_RESET, str1);
    }
}

// ========================================
// ================ PART 2 ================
// ========================================

void test_substr(void) {
    char *substr;
    const char *str1 = "Hello, 42 Prague!";
    const char *str2 = "";
    
    printf(COLOR_BLUE "====== Test ft_substr ======\n" COLOR_RESET);

    // Edge Case 1: Empty string
    substr = ft_substr(str2, 0, 5);
    assert_str_equal(substr, "", "Empty string (start=0, len=5)");
    free(substr);

    // Edge Case 2: Start index beyond string length
    substr = ft_substr(str1, 100, 5);
    assert_str_equal(substr, "", "Start index beyond string length (start=100, len=5)");
    free(substr);

    // Edge Case 3: Substring length greater than remaining characters
    substr = ft_substr(str1, 7, 50);
    assert_str_equal(substr, "42 Prague!", "Substring length greater than remaining characters (start=7, len=50)");
    free(substr);

    // Edge Case 4: Null pointer (if you want to handle it, otherwise can omit)
    // substr = ft_substr(NULL, 0, 5); // Uncomment if you want to test this case
    // printf("ft_substr(NULL): \"%s\"\n", substr);  // Should not crash, but ideally handle NULL case safely

    // Edge Case 5: Zero length
    substr = ft_substr(str1, 5, 0);
    assert_str_equal(substr, "", "Zero length (start=5, len=0)");
    free(substr);

    // Additional Test: Normal case
    substr = ft_substr(str1, 7, 9);
    assert_str_equal(substr, "42 Prague", "Normal case (start=7, len=9)");
    free(substr);
}

void test_strjoin(void) {
    const char *str1 = "Hello, ";
    const char *str2 = "world!";
    char *result;

    printf(COLOR_BLUE "====== Test ft_strjoin ======\n" COLOR_RESET);

    // Normal case
    result = ft_strjoin(str1, str2);
    assert_str_equal(result, "Hello, world!", "Concatenated string");
    free(result);

    // Test with an empty string
    const char *empty = "";
    result = ft_strjoin(empty, str2);
    assert_str_equal(result, "world!", "Concatenated with empty s1");
    free(result);

    result = ft_strjoin(str1, empty);
    assert_str_equal(result, "Hello, ", "Concatenated with empty s2");
    free(result);
}

void test_strtrim(void) {
    printf(COLOR_BLUE "====== Test ft_strtrim ======\n" COLOR_RESET);

    // Test 1
    char *input1 = "   Hello World!   ";
    char *set1 = " ";
    char *expected1 = "Hello World!";
    char *result1 = ft_strtrim(input1, set1);
    if (strcmp(result1, expected1) == 0) {
        printf(COLOR_GREEN "Test 1 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 1 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected1, result1);
    }
    free(result1);

    // Test 2
    char *input2 = "***Hello***";
    char *set2 = "*";
    char *expected2 = "Hello";
    char *result2 = ft_strtrim(input2, set2);
    if (strcmp(result2, expected2) == 0) {
        printf(COLOR_GREEN "Test 2 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 2 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected2, result2);
    }
    free(result2);

    // Test 3
    char *input3 = "abcdef";
    char *set3 = "xyz";
    char *expected3 = "abcdef";
    char *result3 = ft_strtrim(input3, set3);
    if (strcmp(result3, expected3) == 0) {
        printf(COLOR_GREEN "Test 3 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 3 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected3, result3);
    }
    free(result3);

    // Test 4
    char *input4 = "!!!Surprise!!!";
    char *set4 = "!";
    char *expected4 = "Surprise";
    char *result4 = ft_strtrim(input4, set4);
    if (strcmp(result4, expected4) == 0) {
        printf(COLOR_GREEN "Test 4 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 4 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected4, result4);
    }
    free(result4);

    // Test 5
    char *input5 = "123456";
    char *set5 = "123";
    char *expected5 = "456";
    char *result5 = ft_strtrim(input5, set5);
    if (strcmp(result5, expected5) == 0) {
        printf(COLOR_GREEN "Test 5 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 5 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected5, result5);
    }
    free(result5);
}

void test_split(void) {
    printf(COLOR_BLUE "====== Test ft_split ======\n" COLOR_RESET);

    // Test 1
    char **result1 = ft_split("start-middle-end", '-');
    char *expected1[] = {"start", "middle", "end", NULL};
    int i = 0;
    int pass = 1;

    while (expected1[i]) {
        if (result1[i] == NULL || strcmp(result1[i], expected1[i]) != 0) {
            pass = 0;
            break;
        }
        i++;
    }
    if (pass && result1[i] == NULL) {
        printf(COLOR_GREEN "Test 1 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 1 failed\n" COLOR_RESET);
    }
    // Free result1 and individual strings
    i = 0;
    while (result1[i]) free(result1[i++]);
    free(result1);

    // Test 2
    char **result2 = ft_split("foo-bar-baz", '-');
    char *expected2[] = {"foo", "bar", "baz", NULL};
    i = 0;
    pass = 1;

    while (expected2[i]) {
        if (result2[i] == NULL || strcmp(result2[i], expected2[i]) != 0) {
            pass = 0;
            break;
        }
        i++;
    }
    if (pass && result2[i] == NULL) {
        printf(COLOR_GREEN "Test 2 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 2 failed\n" COLOR_RESET);
    }
    // Free result2 and individual strings
    i = 0;
    while (result2[i]) free(result2[i++]);
    free(result2);

    // Test 3
    char **result3 = ft_split("apple,,orange,,banana,", ',');
    char *expected3[] = {"apple", "orange", "banana", NULL};
    i = 0;
    pass = 1;

    while (expected3[i]) {
        if (result3[i] == NULL || strcmp(result3[i], expected3[i]) != 0) {
            pass = 0;
            break;
        }
        i++;
    }
    if (pass && result3[i] == NULL) {
        printf(COLOR_GREEN "Test 3 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 3 failed\n" COLOR_RESET);
    }
    // Free result3 and individual strings
    i = 0;
    while (result3[i]) free(result3[i++]);
    free(result3);

    // Test 4
    char **result4 = ft_split(",,,", ',');
    char *expected4[] = {NULL};
    i = 0;
    pass = 1;

    while (expected4[i]) {
        if (result4[i] == NULL || strcmp(result4[i], expected4[i]) != 0) {
            pass = 0;
            break;
        }
        i++;
    }
    if (pass && result4[i] == NULL) {
        printf(COLOR_GREEN "Test 4 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 4 failed\n" COLOR_RESET);
    }
    // Free result4 and individual strings
    i = 0;
    while (result4[i]) free(result4[i++]);
    free(result4);

    // Test 5
    char **result5 = ft_split(",start-middle-end,", ',');
    char *expected5[] = {"start-middle-end", NULL};
    i = 0;
    pass = 1;

    while (expected5[i]) {
        if (result5[i] == NULL || strcmp(result5[i], expected5[i]) != 0) {
            pass = 0;
            break;
        }
        i++;
    }
    if (pass && result5[i] == NULL) {
        printf(COLOR_GREEN "Test 5 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 5 failed\n" COLOR_RESET);
    }
    // Free result5 and individual strings
    i = 0;
    while (result5[i]) free(result5[i++]);
    free(result5);
}

void test_itoa(void)
{
    printf(COLOR_BLUE "====== Test ft_itoa ======\n" COLOR_RESET);

    // Test 1: Zero
    int num1 = 0;
    char *result1 = ft_itoa(num1);
    char *expected1 = "0";
    if (strcmp(result1, expected1) == 0) {
        printf(COLOR_GREEN "Test 1 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 1 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected1, result1);
    }
    free(result1);

    // Test 2: Positive number
    int num2 = 1234;
    char *result2 = ft_itoa(num2);
    char *expected2 = "1234";
    if (strcmp(result2, expected2) == 0) {
        printf(COLOR_GREEN "Test 2 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 2 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected2, result2);
    }
    free(result2);

    // Test 3: Negative number
    int num3 = -1234;
    char *result3 = ft_itoa(num3);
    char *expected3 = "-1234";
    if (strcmp(result3, expected3) == 0) {
        printf(COLOR_GREEN "Test 3 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 3 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected3, result3);
    }
    free(result3);

    // Test 4: INT_MAX
    int num4 = INT_MAX;
    char *result4 = ft_itoa(num4);
    char *expected4 = "2147483647";
    if (strcmp(result4, expected4) == 0) {
        printf(COLOR_GREEN "Test 4 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 4 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected4, result4);
    }
    free(result4);

    // Test 5: INT_MIN
    int num5 = INT_MIN;
    char *result5 = ft_itoa(num5);
    // Expected result is typically "-2147483648"
    char *expected5 = "-2147483648";
    if (strcmp(result5, expected5) == 0) {
        printf(COLOR_GREEN "Test 5 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 5 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected5, result5);
    }
    free(result5);

    // Test 6: Edge case negative number with a single digit
    int num6 = -1;
    char *result6 = ft_itoa(num6);
    char *expected6 = "-1";
    if (strcmp(result6, expected6) == 0) {
        printf(COLOR_GREEN "Test 6 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 6 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected6, result6);
    }
    free(result6);

    // Test 7: Edge case positive number with a single digit
    int num7 = 1;
    char *result7 = ft_itoa(num7);
    char *expected7 = "1";
    if (strcmp(result7, expected7) == 0) {
        printf(COLOR_GREEN "Test 7 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 7 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected7, result7);
    }
    free(result7);

    // Test 8: Large number with many digits
    int num8 = 987654321;
    char *result8 = ft_itoa(num8);
    char *expected8 = "987654321";
    if (strcmp(result8, expected8) == 0) {
        printf(COLOR_GREEN "Test 8 passed\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "Test 8 failed. Expected: '%s', Got: '%s'\n" COLOR_RESET, expected8, result8);
    }
    free(result8);
}