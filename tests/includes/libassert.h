/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libassert.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 07:52:22 by susami            #+#    #+#             */
/*   Updated: 2024/10/30 16:06:16 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASSERT_H
# define LIBASSERT_H
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct {
    void *ptr;
    size_t size;
} MemInfo;

#define MAX_ALLOCATIONS 1024
static MemInfo allocations[MAX_ALLOCATIONS];
static size_t allocation_count = 0;

#if defined(__linux__)
    #include <malloc.h>
#endif

void	ASSERT_TRUE(bool actual, char *caller_file, const char *caller_func,
			int caller_line);
void	ASSERT_EQ_I(int actual, int expected, char *caller_file,
			const char *caller_func, int caller_line);
void	ASSERT_EQ_UI(unsigned int actual, unsigned int expected,
			char *caller_file, const char *caller_func, int caller_line);
void	ASSERT_EQ_L(long actual, long expected, char *caller_file,
			const char *caller_func, int caller_line);
void	ASSERT_EQ_UL(unsigned long actual, unsigned long expected,
			char *caller_file, const char *caller_func, int caller_line);
void	ASSERT_EQ_LL(long long actual, long long expected, char *caller_file,
			const char *caller_func, int caller_line);
void	ASSERT_EQ_ULL(unsigned long long actual, unsigned long long expected,
			char *caller_file, const char *caller_func, int caller_line);
void	ASSERT_EQ_SIZE(size_t actual, size_t expected, char *caller_file,
			const char *caller_func, int caller_line);
void	ASSERT_EQ_STR(char *actual, char *expected, char *caller_file,
			const char *caller_func, int caller_line);
void	ASSERT_EQ_MALLOC_SIZE(void *actual, void *expected, char *caller_file,
			const char *caller_func, int caller_line);
void	ASSERT_EQ_MEM(void *actual, void *expected, size_t size,
			char *caller_file, const char *caller_func, int caller_line);
void	ASSERT_EQ_PTR(void *actual, void *expected, char *caller_file,
			const char *caller_func, int caller_line);
# define ASSERT_TRUE(x) ASSERT_TRUE(x, __FILE__, __func__, __LINE__)
# define ASSERT_EQ_I(x, y) ASSERT_EQ_I(x, y, __FILE__, __func__, __LINE__)
# define ASSERT_EQ_UI(x, y) ASSERT_EQ_UI(x, y, __FILE__, __func__, __LINE__)
# define ASSERT_EQ_L(x, y) ASSERT_EQ_L(x, y, __FILE__, __func__, __LINE__)
# define ASSERT_EQ_UL(x, y) ASSERT_EQ_UL(x, y, __FILE__, __func__, __LINE__)
# define ASSERT_EQ_LL(x, y) ASSERT_EQ_LL(x, y, __FILE__, __func__, __LINE__)
# define ASSERT_EQ_ULL(x, y) ASSERT_EQ_ULL(x, y, __FILE__, __func__, __LINE__)
# define ASSERT_EQ_SIZE(x, y) ASSERT_EQ_SIZE(x, y, __FILE__, __func__, __LINE__)
# define ASSERT_EQ_STR(x, y) ASSERT_EQ_STR(x, y, __FILE__, __func__, __LINE__)
# define ASSERT_EQ_MALLOC_SIZE(x, y) ASSERT_EQ_MALLOC_SIZE(x, y, __FILE__,	__func__, __LINE__)
# define ASSERT_EQ_MEM(x, y, z) ASSERT_EQ_MEM(x, y, z, __FILE__, __func__,	__LINE__)
# define ASSERT_EQ_PTR(x, y) ASSERT_EQ_PTR(x, y, __FILE__, __func__, __LINE__)

#endif
