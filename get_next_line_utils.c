/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuramat <smuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:17:41 by smuramat          #+#    #+#             */
/*   Updated: 2022/05/27 11:58:50 by smuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;
	size_t	i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*new_p;

	new_p = malloc(count * size);
	if (new_p == NULL)
		return (NULL);
	ft_bzero(new_p, size * count);
	return (new_p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}

void	*ft_free(char *str, char *str2)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	if (str2)
	{
		free(str2);
		str2 = NULL;
	}
	return (NULL);
}
