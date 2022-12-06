/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:30:14 by ccosta-c          #+#    #+#             */
/*   Updated: 2022/12/06 16:37:13 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_dirty_line(char *stash, int fd)
{
	int		bytes_read;
	char	*content_read;
	char	*tmp;

	content_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!content_read)
		return (NULL);
	bytes_read = 1;
	while ((bytes_read != 0) && !(ft_strchr(content_read, '\n')))
	{
		bytes_read = read(fd, content_read, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (stash);
			free (content_read);
			return (NULL);
		}
		*(content_read + bytes_read) = '\0';
		 tmp = ft_strjoin(stash, content_read);
		 free (stash);
		 free(content_read);
		 stash = tmp;
	}
	free(tmp);
	return(stash);
}

char *get_next_line(int fd)
{
	static char	*stash;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	ft_read_dirty_line(stash, fd);
	printf("%s", stash);
	return (stash);
}