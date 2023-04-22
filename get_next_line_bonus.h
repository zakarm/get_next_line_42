/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:18:29 by zmrabet           #+#    #+#             */
/*   Updated: 2022/10/30 17:49:52 by zmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*includes*/
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*prototypes*/
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_check_nl(const char *s);
char	*test_zero(char *p);
int		len_line(char *str);
char	*line(char *str);
char	*read_file(char *str, int fd);
char	*get_buffer(char *st);
size_t	ft_strlen(const char *s);

#endif