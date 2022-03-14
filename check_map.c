/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 08:30:51 by fbouanan          #+#    #+#             */
/*   Updated: 2022/03/04 08:30:53 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_width(char **map)
{
	t_data	k;

	k.i = 0;
	k.len = ft_strlen(map[k.i]);
	while (map[k.i])
	{
		k.j = 0;
		while (map[k.i][k.j])
			k.j++;
		if (k.j != k.len)
		{
			write(1, "INVALID MAP!\n", 13);
			exit(1);
		}
		k.i++;
	}
}

void	check_walls(char **map)
{
	t_data	f;

	f.j = 0;
	while (map[0][f.j])
	{
		if (map[0][f.j] != '1')
		{
			write(1, "error\n", 6);
			exit(1);
		}
		f.j++;
	}
	f.j = 0;
	while (map[f.i - 1][f.j])
	{
		if (map[f.i - 1][f.j] != '1')
		{
			write(1, "error\n", 6);
			exit(1);
		}
		f.j++;
	}
	f.i = 1;
	f.len = ft_strlen(map[f.i]) - 1;
	rest_check_walls(f.len, f.i, map);
}

void	elem_vld(char *join)
{
	int			i;
	t_element	elm;

	elm.mashroom = 0;
	elm.exit = 0;
	elm.player = 0;
	i = 0;
	while (join[i])
	{
		if (join[i] == 'C')
			elm.mashroom++;
		else if (join[i] == 'P')
			elm.player++;
		else if (join[i] == 'E')
			elm.exit++;
		i++;
	}
	rest_elem_vld(elm.mashroom, elm.player, elm.exit);
}

void	check_elements(char **map)
{
	t_data		e;
	char		*join;

	join = ft_strdup("");
	e.i = 0;
	while (map[e.i])
	{
		join = ft_strjoin2(join, map[e.i]);
		e.i++;
	}
	e.i = 0;
	while (join[e.i])
	{
		if (!(join[e.i] == '1' || join[e.i] == '0'
				|| join[e.i] == 'P' || join[e.i] == 'C' || join[e.i] == 'E'))
		{
			write(1, "INVALID MAP!\n", 13);
			exit(1);
		}
		e.i++;
	}
	elem_vld(join);
}

void	check_map(char **map)
{
	check_width(map);
	check_walls(map);
	check_elements(map);
}
