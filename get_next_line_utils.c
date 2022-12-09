/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:30:32 by ccosta-c          #+#    #+#             */
/*   Updated: 2022/12/09 01:12:39 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int chr)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	if (chr == '\0')
		return (str);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	len = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j) && s2)
	{
		*(str + i++) = *(s2 + j++);
	}
	*(str + i) = '\0';
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && *(s + i))
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		x;

	x = nmemb * size;
	ptr = malloc(x);
	if (ptr == NULL)
	{
		return (ptr);
	}
	while (x-- >= 0)
	{
		*(ptr + x) = '\0';
	}
	return ((void *)ptr);
}
