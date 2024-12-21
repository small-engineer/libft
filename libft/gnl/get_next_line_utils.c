/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:34:47 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/13 18:34:52 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;
	const char	*p_s = s;

	i = 0;
	while (*p_s++)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*p_dst;
	const char	*p_src;
	size_t		i;

	p_dst = dst;
	p_src = src;
	i = dstsize;
	if (i == 0)
		return (ft_strlen(src));
	while (i-- > 1 && *p_src)
		*p_dst++ = *p_src++;
	*p_dst = '\0';
	while (*p_src++)
		;
	return (p_src - src - 1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*p_dst;
	const char	*p_src = src;
	size_t		i;
	size_t		d_len;

	p_dst = dst;
	i = dstsize;
	while (i-- != 0 && *p_dst)
		p_dst++;
	d_len = p_dst - dst;
	i = dstsize - d_len;
	if (i == 0)
		return (d_len + ft_strlen(p_src));
	while (*p_src)
	{
		if (i != 1)
		{
			*p_dst++ = *p_src;
			i--;
		}
		p_src++;
	}
	*p_dst = '\0';
	return (d_len + (p_src - src));
}

char	*ft_strdup(const char *s1)
{
	char			*s2;
	const size_t	len = ft_strlen(s1) + 1;

	if (!s1)
		return (NULL);
	s2 = malloc(len * sizeof(char));
	if (s2)
	{
		ft_strlcpy(s2, s1, len);
		return (s2);
	}
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcat(ret, s2, s1_len + s2_len + 1);
	return (ret);
}
