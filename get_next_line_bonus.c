/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:22:56 by ilasrarf          #+#    #+#             */
/*   Updated: 2022/11/09 16:03:08 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*p;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	p = malloc(i + 2);
	if (!p)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		p[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		p[i++] = '\n';
	p[i] = '\0';
	return (p);
}

char	*ft_remove_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (i >= ft_strlen(str))
		return (free(str), NULL);
	tmp = malloc(ft_strlen(str) - i + 1);
	if (!tmp)
		return (NULL);
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	return (free(str), tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*se[OPEN_MAX];
	char		*buf;
	ssize_t		read_len;

	read_len = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!se[fd])
		se[fd] = ft_strdup("");
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (read_len && (!ft_strchr(se[fd], '\n')))
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0)
			return (free(se[fd]), se[fd] = NULL, free(buf), buf = NULL, NULL);
		buf[read_len] = '\0';
		se[fd] = ft_strjoin(se[fd], buf);
	}
	line = ft_get_line(se[fd]);
	return (se[fd] = ft_remove_line(se[fd]), free(buf), line);
}
