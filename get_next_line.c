/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:30:14 by ccosta-c          #+#    #+#             */
/*   Updated: 2022/12/06 21:47:37 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_dirty_line(char *stash, int fd)
{
	int		bytes_read;
	char	*content_read;
	char	*tmp;

	content_read = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	bytes_read = 1;
	while ((bytes_read > 0) && !(ft_strchr(content_read, '\n')))
	{
		bytes_read = read(fd, content_read, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (stash);
			free (content_read);
			return (NULL);
		}
		*(content_read + bytes_read) = '\0';
		 tmp = ft_strjoin(stash, content_read);
		 free (stash);
		 stash = tmp;
	}
	free (content_read);
	return (stash);
}

char *get_next_line(int fd)
{
	static char	*stash;
	
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	stash = ft_read_dirty_line(stash, fd);
	printf("%s", stash);
	return (stash);
}