/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:15:42 by fbouanan          #+#    #+#             */
/*   Updated: 2022/03/02 17:15:44 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		ss1;
	int		ss2;
	char	*m;

	if (!s1 || !s2)
		return (NULL);
	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	m = malloc(sizeof(char) * (ss1 + ss2 + 1));
	if (!m)
		return (0);
	i = 0;
	while (i <= ss1)
	{
		m[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ss2)
		m[ss1++] = s2[i++];
	m[ss1] = '\0';
	free(s1);
	return (m);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*string;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		string = malloc(sizeof(char));
	else if (len > ft_strlen(s))
		string = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		string = malloc(sizeof (char) * (len + 1));
	if (!string)
		return (NULL);
	while (s[i] && i < len && i + start < ft_strlen(s))
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (char )c)
		{
			return (s + i);
		}
		i--;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
