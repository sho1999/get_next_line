/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuramat <smuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:14:31 by smuramat          #+#    #+#             */
/*   Updated: 2022/05/28 12:45:31 by smuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_str_join(char *old_buff, char *read_str)
{
	size_t		total;
	size_t		i;
	size_t		j;
	char		*res;

	i = 0;
	total = ft_strlen(old_buff) + ft_strlen(read_str);
	res = ft_calloc(total + 1, sizeof(char));
	if (!res || !old_buff)
		return (ft_free(old_buff, read_str));
	while (old_buff[i])
	{
		res[i] = old_buff[i];
		i++;
	}
	j = 0;
	while (read_str[j])
	{
		res[i] = read_str[j];
		i++;
		j++;
	}
	res[total] = '\0';
	free(old_buff);
	return (res);
}

static char	*ft_rest_str(char *buff)
{
	char		*rest_str;
	size_t		i;
	size_t		j;

	j = 0;
	while (buff[j] && buff[j] != '\n')
		j++;
	if (!buff[j])
		return (ft_free(buff, NULL));
	rest_str = ft_calloc((ft_strlen(buff) - j + 1), sizeof(char));
	if (!rest_str)
		return (ft_free(buff, NULL));
	i = 0;
	j++;
	while (buff[j])
		rest_str[i++] = buff[j++];
	free(buff);
	return (rest_str);
}

static char	*ft_put_one_line(char *buff)
{
	char	*one_line;
	size_t	i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	one_line = ft_calloc(i + 2, sizeof(char));
	if (!one_line)
		return (ft_free(buff, NULL));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		one_line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		one_line[i] = buff[i];
		i++;
	}
	one_line[i] = '\0';
	return (one_line);
}

static char	*ft_read_file(char *buff, int fd)
{
	char	*read_str;
	ssize_t	read_flag;

	if (!buff)
		buff = ft_calloc(1, 1);
	read_str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_str)
		return (ft_free(buff, NULL));
	read_flag = 1;
	while (!ft_strchr(read_str, '\n') && read_flag > 0)
	{
		read_flag = read(fd, read_str, BUFFER_SIZE);
		if (read_flag == -1)
			return (ft_free(read_str, buff));
		read_str[read_flag] = '\0';
		buff = ft_str_join(buff, read_str);
	}
	ft_free(read_str, NULL);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[256];
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 255 || read(fd, 0, 0) < 0)
		return (NULL);
	buff[fd] = ft_read_file(buff[fd], fd);
	if (!buff[fd])
		return (NULL);
	one_line = ft_put_one_line(buff[fd]);
	buff[fd] = ft_rest_str(buff[fd]);
	return (one_line);
}
