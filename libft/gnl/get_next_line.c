/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:34:28 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/14 21:27:22 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*safe_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

static ssize_t	find_newline(const char *s)
{
	ssize_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*extract_line(char **keep)
{
	char	*line;
	char	*new_keep;
	ssize_t	nl_index;

	if (!*keep || **keep == '\0')
		return (NULL);
	nl_index = find_newline(*keep);
	if (nl_index == -1)
	{
		line = ft_strdup(*keep);
		safe_free((void **)keep);
		return (line);
	}
	line = (char *)malloc((nl_index + 2) * sizeof(char));
	if (!line)
		return (safe_free((void **)keep));
	ft_strlcpy(line, *keep, nl_index + 2);
	new_keep = ft_strdup(*keep + nl_index + 1);
	if (!new_keep)
		return (safe_free((void **)keep), safe_free((void **)&line));
	safe_free((void **)keep);
	*keep = new_keep;
	return (line);
}

static int	read_fd_into_keep(int fd, char **keep)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*tmp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	while (find_newline(*keep) == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (safe_free((void **)&buffer), -1);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(*keep, buffer);
		safe_free((void **)keep);
		if (!tmp)
			return (safe_free((void **)&buffer), -1);
		*keep = tmp;
	}
	return (safe_free((void **)&buffer), 0);
}

char	*get_next_line(int fd)
{
	static char	*keeps[FD_SETSIZE] = {NULL};
	char		*line;

	if (fd < 0 || fd >= FD_SETSIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!keeps[fd])
	{
		keeps[fd] = ft_strdup("");
		if (!keeps[fd])
			return (NULL);
	}
	if (read_fd_into_keep(fd, &keeps[fd]) == -1)
		return (safe_free((void **)&keeps[fd]));
	line = extract_line(&keeps[fd]);
	if (!line)
		safe_free((void **)&keeps[fd]);
	return (line);
}
