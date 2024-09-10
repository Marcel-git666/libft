/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:11:17 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/10 20:52:41 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool assert_str_equal(const char *result, const char *expected, const char *msg);
bool assert_all_zeros(int *arr, size_t count, const char *msg);
bool assert_int_equal(int result, int expected, const char *msg);
void print_memory(const void *ptr, size_t size);
void print_split_result(char **result);