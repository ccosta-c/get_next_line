/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:30:14 by ccosta-c          #+#    #+#             */
/*   Updated: 2022/12/09 16:39:09 by ccosta-c         ###   ########.fr       */
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
			if (stash)
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

static char	*ft_clean_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!(*(stash + i)))
		return (NULL);
	while ((*(stash + i) != '\n') && (*(stash + i) != '\0'))
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while ((*(stash + i) != '\n' && (*(stash + i) != '\0')))
	{
		*(line + i) = *(stash + i);
		i++;
	}
	*(line + i) = *(stash + i);
	i++;
	*(line + i) = '\0';
	return (line);
}

static char	*ft_get_trash(char *stash)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*(stash + i) != '\n') && (*(stash + i) != '\0'))
		i++;
	if (!(*(stash + i)))
	{
		free(stash);
		return (NULL);
	}
	tmp = ft_calloc(sizeof(char), ((ft_strlen(stash) - i)));
	if (!tmp)
		return (NULL);
	i++;
	while ((*(stash + i)) != '\0')
		*(tmp + j++) = *(stash + i++);
	free (stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*clean_line;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	stash = ft_read_dirty_line(stash, fd);
	if (!stash)
		return (NULL);
	//printf("stash - %s\n", stash);
	clean_line = ft_clean_line(stash);
	//printf("clean line - %s", clean_line);
	stash = ft_get_trash(stash);
	//printf("stash - %s", stash);
	return (clean_line);
}
