/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movePlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:26:28 by fbouanan          #+#    #+#             */
/*   Updated: 2022/03/02 18:26:30 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_data *pd)
{
	pd->y = 0;
	while (pd->map[pd->y])
	{
		pd->x = 0;
		while (pd->map[pd->y][pd->x])
		{
			if (pd->map[pd->y][pd->x] == 'P')
				break ;
			pd->x++;
		}
		if (pd->map[pd->y][pd->x] == 'P')
			break ;
		pd->y++;
	}
}

void	exit_fun(t_data *pd)
{
	pd->c = 0;
	pd->i = 0;
	while (pd->map[pd->i])
	{
		pd->j = 0;
		while (pd->map[pd->i][pd->j])
		{
			if (pd->map[pd->i][pd->j] == 'C')
				pd->c++;
			pd->j++;
		}
		pd->i++;
	}
}

int	write_exit(t_data *pd)
{
	if (pd->c != 0)
		return (1);
	write(1, "YOU WIN", 7);
	exit(0);
	return (0);
}

int	check_exit(t_data *pd, int key)
{
	exit_fun(pd);
	if (pd->map[pd->y - 1][pd->x] == 'E' && key == 13)
		return (write_exit(pd));
	else if (pd->map[pd->y + 1][pd->x] == 'E' && key == 1)
		return (write_exit(pd));
	else if (pd->map[pd->y][pd->x - 1] == 'E' && key == 0)
		return (write_exit(pd));
	else if (pd->map[pd->y][pd->x + 1] == 'E' && key == 2)
		return (write_exit(pd));
	return (0);
}

int	moveplayer(int key, t_data *pd)
{
	find_player(pd);
	if (key == 53)
		exit(0);
	if (key == 13 && pd->map[pd->y - 1][pd->x] != '1')
		up(pd, key);
	else if (key == 1 && pd->map[pd->y + 1][pd->x] != '1')
		down(pd, key);
	else if (key == 0 && pd->map[pd->y][pd->x - 1] != '1')
		left(pd, key);
	else if (key == 2 && pd->map[pd->y][pd->x + 1] != '1')
		right(pd, key);
	return (0);
}
