/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:01:30 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/21 15:04:37 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	length;
	char	*dup;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	dup = malloc(length + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	ft_copy(char *new_str, char *str1, char *str2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str1[i])
	{
		new_str[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		new_str[i] = str2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		str1 = ft_strdup("");
	new_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new_str)
		return (NULL);
	ft_copy(new_str, str1, str2);
	free(str1);
	return (new_str);
}
