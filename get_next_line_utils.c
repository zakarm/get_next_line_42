/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:32:27 by zmrabet           #+#    #+#             */
/*   Updated: 2022/10/30 00:50:29 by zmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check_nl(const char *s)
{
	char	*st;

	st = (char *)s;
	while (*st != '\n')
	{
		if (*st == '\0')
			return (NULL);
		st++;
	}
	return (st);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
			i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	char	*s;
	int		i;

	s = (char *)s1;
	i = ft_strlen(s);
	p = (char *)malloc((sizeof(char) * i) + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
			p[i] = s[i];
			i++;
	}
	p[i] = '\0';
	return (p);
}

char	*test_zero(char *p)
{
	if (p[0] == '\0')
	{
		free(p);
		return (NULL);
	}
	else
		return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	free((char *)s1);
	return (test_zero(p));
}
