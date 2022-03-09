/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:52:26 by fbouanan          #+#    #+#             */
/*   Updated: 2022/03/08 13:52:28 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rest_check_walls(int len, int i, char **map)
{
	while (map[i])
	{
		if ((map[i][0] != '1') || (map[i][len] != '1'))
		{
			write(1, "error\n", 7);
			exit(1);
		}
		i++;
	}
}

void	rest_elem_vld(int m, int p, int e)
{
	if (m <= 0)
	{
		write(1, "there is no mashrooms!\n", 23);
		exit(1);
	}
	else if (p != 1)
	{
		write(1, "there is no player or more then one!\n", 37);
		exit(1);
	}
	else if (e <= 0)
	{
		write(1, "Where is the door!\n", 20);
		exit(1);
	}
}
