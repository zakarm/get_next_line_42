/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:53:54 by zmrabet           #+#    #+#             */
/*   Updated: 2022/10/30 18:41:50 by zmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_line(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			len++;
			break ;
		}
		i++;
		len++;
	}
	return (len);
}

char	*get_buffer(char *st)
{
	int		i;
	char	*data;
	char	*tmp;

	i = 0;
	tmp = st;
	while (*st != '\n')
	{
		if (*st == '\0')
		{
			free(tmp);
			return (NULL);
		}
		st++;
	}
	st++;
	data = (char *)malloc(sizeof(char) * (ft_strlen(st) + 1));
	if (!data)
		return (NULL);
	while (*st)
		data[i++] = *st++;
	data[i] = '\0';
	free(tmp);
	return (data);
}

char	*line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(sizeof(char) * (len_line(str) + 1));
	if (!line)
		return (NULL);
	while (*str && *str != '\n')
	{
		line[i] = *str;
		i++;
		str++;
	}
	if (*str == '\n')
	{
		line[i] = *str;
		i++;
		str++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_file(char *str, int fd)
{
	char	*buffer;
	int		read_f;

	read_f = 1;
	if (!str)
		str = ft_strdup("");
	while (!ft_check_nl(str) && read_f > 0)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		read_f = read(fd, buffer, BUFFER_SIZE);
		if (read_f == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[read_f] = '\0';
		str = ft_strjoin(str, buffer);
		free(buffer);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*nxtline;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = read_file(buffer, fd);
	if (!buffer)
		return (NULL);
	nxtline = line(buffer);
	buffer = get_buffer(buffer);
	if (nxtline[0] == 0)
		return (free(nxtline), NULL);
	return (nxtline);
}
