/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:23:37 by fbouanan          #+#    #+#             */
/*   Updated: 2022/03/08 15:23:39 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up(t_data *pd, int key)
{
	if (check_exit(pd, key))
		return (0);
	ft_putnbr(pd->count++);
	ft_putchar('\n');
	pd->map[pd->y - 1][pd->x] = 'P';
	pd->map[pd->y][pd->x] = '0';
	mlx_clear_window(pd->mlx, pd->mlx_wind);
	render_map(pd->mlx, pd->mlx_wind, pd);
	return (0);
}

int	down(t_data *pd, int key)
{
	if (check_exit(pd, key))
		return (0);
	ft_putnbr(pd->count++);
	ft_putchar('\n');
	pd->map[pd->y + 1][pd->x] = 'P';
	pd->map[pd->y][pd->x] = '0';
	mlx_clear_window(pd->mlx, pd->mlx_wind);
	render_map(pd->mlx, pd->mlx_wind, pd);
	return (0);
}

int	left(t_data *pd, int key)
{
	if (check_exit(pd, key))
		return (0);
	ft_putnbr(pd->count++);
	ft_putchar('\n');
	pd->map[pd->y][pd->x - 1] = 'P';
	pd->map[pd->y][pd->x] = '0';
	mlx_clear_window(pd->mlx, pd->mlx_wind);
	render_map(pd->mlx, pd->mlx_wind, pd);
	return (0);
}

int	right(t_data *pd, int key)
{
	if (check_exit(pd, key))
		return (0);
	ft_putnbr(pd->count++);
	ft_putchar('\n');
	pd->map[pd->y][pd->x + 1] = 'P';
	pd->map[pd->y][pd->x] = '0';
	mlx_clear_window(pd->mlx, pd->mlx_wind);
	render_map(pd->mlx, pd->mlx_wind, pd);
	return (0);
}
