/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:47:02 by mmravec           #+#    #+#             */
/*   Updated: 2024/09/12 12:22:09 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED "\033[0;31m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_RESET "\033[0m"
#define COLOR_YELLOW "\x1b[33m"

void test_isalpha(void);
void test_isdigit(void);
void test_isalnum(void);
void test_isascii(void);
void test_isprint(void);
void test_strlen(void);
void test_toupper(void);
void test_tolower(void);
void test_strchr(void);
void test_strrchr(void);
void test_strncmp(void);
void test_memset(void);
void test_bzero(void);
void test_memcpy(void);
void test_memmove(void);
void test_strlcpy(void);
void test_strlcat(void);
void test_memchr(void);
void test_memcmp(void);
void test_strnstr(void);
void test_atoi(void);
void test_calloc(void);
void test_strdup(void);
void test_substr(void);
void test_strjoin(void);
void test_strtrim(void);
void test_split(void);
void test_itoa(void);
void test_strmapi(void);
void test_striteri(void);
void test_putchar_fd(void);
void test_putstr_fd(void);
void test_putendl_fd(void);
void test_putnbr_fd(void);

// ============= Bonus =============

void test_lstnew(void);
void test_lstadd_front(void);
void test_lstsize(void);
void test_lstlast(void);


#endif
