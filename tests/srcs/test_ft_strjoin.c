/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:20:37 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:09:15 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_STR(ft_strjoin("hello", "world"), "helloworld");
	/* 2 */ ASSERT_EQ_STR(ft_strjoin("", "world"), "world");
	/* 3 */ ASSERT_EQ_STR(ft_strjoin("hello", ""), "hello");
	/* 4 */ ASSERT_EQ_STR(ft_strjoin("", ""), "");
}
