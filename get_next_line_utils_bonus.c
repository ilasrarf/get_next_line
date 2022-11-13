/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:28:41 by ilasrarf          #+#    #+#             */
/*   Updated: 2022/11/09 16:16:59 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (s[0] && (s[0] != (char)c))
		s++;
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*alloc;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(str);
	i = 0;
	alloc = (char *)malloc((str_len + 1) * sizeof(char));
	if (!alloc)
		return (0);
	return (ft_memcpy(alloc, str, str_len + 1));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*alloc;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	alloc = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!alloc)
		return (0);
	while (s1[i])
	{
		alloc[i] = s1[i];
		i++;
	}
	while (s2[j])
		alloc[i++] = s2[j++];
	alloc[i] = '\0';
	return (free((char *)s1), alloc);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
