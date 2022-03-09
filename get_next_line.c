/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:46:37 by fbouanan          #+#    #+#             */
/*   Updated: 2022/02/20 14:46:39 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*r;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	r = malloc(sizeof(char) * i + 1);
	if (!r)
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_strjoin(char *s, char c)
{
	int		i;
	char	*r;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	r = malloc(sizeof(char) * i + 2);
	if (!r)
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	r[i] = c;
	r[i + 1] = '\0';
	free(s);
	return (r);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buff;
	int		i;

	if (fd < 0)
		return (NULL);
	line = ft_strdup("");
	while (read(fd, &buff, 1) > 0)
	{
		line = ft_strjoin(line, buff);
		if (buff == '\0')
			break ;
	}
	i = 0;
	while (line[i])
		i++;
	if (i == 0 || read(fd, &buff, 1) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	check_new_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			write(1, "INVALID MAP!", 12);
			exit(1);
		}
		i++;
	}
	if (map[i - 1] == '\n')
	{
		write(1, "INVALID MAP!", 12);
		exit(1);
	}
}
