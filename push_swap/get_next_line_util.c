/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:50:40 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 23:26:01 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	int		j;
	int		i;

	i = 0;
	j = ft_strlen(str);
	s = malloc(j + 1);
	if (s == 0)
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strchr(const char *str, int s)
{
	char	*st;
	int		i;

	i = 0;
	st = (char *)str;
	while (st[i] != (char)s)
	{
		if (st[i] == '\0')
			return (NULL);
		i++;
	}
	return (st + i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1);
	i = ft_strlen(s2);
	s = malloc(i + j + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		s[j] = s1[j];
		j++;
	}
	while (s2[i])
		s[j++] = s2[i++];
	s[j] = '\0';
	free((char *)s1);
	return (s);
}
