/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:10:34 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/10 20:54:23 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "main.h"

bool assert_str_equal(const char *result, const char *expected, const char *msg)
{
    bool passed = strcmp(result, expected) == 0;
    printf(passed ? COLOR_GREEN "PASS: " : COLOR_RED "FAIL: ");
    printf("%s\n", msg);
    printf(COLOR_RESET);
    return passed;
}

bool assert_all_zeros(int *arr, size_t count, const char *msg)
{
    bool passed = true;
    for (size_t i = 0; i < count; i++) {
        if (arr[i] != 0) {
            passed = false;
            break;
        }
    }
    printf(passed ? COLOR_GREEN "PASS: " : COLOR_RED "FAIL: ");
    printf("%s\n", msg);
    printf(COLOR_RESET);
    return passed;
}

bool assert_int_equal(int result, int expected, const char *msg)
{
    bool passed = result == expected;
    printf(passed ? COLOR_GREEN "PASS: " : COLOR_RED "FAIL: ");
    printf("%s\n", msg);
    printf(COLOR_RESET);
    return passed;
}

void print_memory(const void *ptr, size_t size) 
{
    const unsigned char *byte = (const unsigned char *)ptr;
    printf(COLOR_BLUE "Memory: " COLOR_RESET);
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", byte[i]);
    }
    printf("\n");
}

void print_split_result(char **result)
{
    if (result == NULL) {
        printf("NULL\n");
        return;
    }
    for (int i = 0; result[i] != NULL; i++) {
        printf("\"%s\"\n", result[i]);
    }
}
