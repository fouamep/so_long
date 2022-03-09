/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:55:04 by fbouanan          #+#    #+#             */
/*   Updated: 2022/02/22 17:55:06 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	*send_elements(char **map, int x, int y, void *mlx)
{
	t_element	e;

	if (map[y][x] == '1')
	{
		e.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &e.a, &e.b);
		return (e.wall);
	}
	else if (map[y][x] == '0')
	{
		e.floor = mlx_xpm_file_to_image(mlx, "./images/floor.xpm", &e.a, &e.b);
		return (e.floor);
	}
	else if (map[y][x] == 'P')
	{
		e.mario = mlx_xpm_file_to_image(mlx, "./images/mario.xpm", &e.a, &e.b);
		return (e.mario);
	}
	else if (map[y][x] == 'C')
	{
		e.col = mlx_xpm_file_to_image(mlx, "./images/mashroom.xpm", &e.a, &e.b);
		return (e.col);
	}
	e.door = mlx_xpm_file_to_image(mlx, "./images/door.xpm", &e.a, &e.b);
	return (e.door);
}

void	render_map(void *mlx, void *mlx_wind, t_data *dt)
{
	void	*el;

	dt->y = 0;
	while (dt->map[dt->y])
	{
		dt->x = 0;
		while (dt->map[dt->y][dt->x])
		{
			el = send_elements(dt->map, dt->x, dt->y, mlx);
			mlx_put_image_to_window(mlx, mlx_wind, el, dt->x * 50, dt->y * 50);
			mlx_hook(mlx_wind, 17, 0, destroynotify, 0);
			dt->x++;
		}
		dt->y++;
	}
}
