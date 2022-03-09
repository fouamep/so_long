/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:46:25 by fbouanan          #+#    #+#             */
/*   Updated: 2022/02/19 21:46:29 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd)
{
	char	**map;
	char	*ret;

	ret = get_next_line(fd);
	if (!ret)
	{
		write(1, "there is no map!\n", 17);
		exit(1);
	}
	check_new_line(ret);
	map = ft_split(ret, '\n');
	return (map);
}

void	check_ber(char *path)
{
	char	*ext;

	ext = ft_strrchr(path, '.');
	if (ext == NULL || ft_strcmp(".ber", ext) != 0)
	{
		write(1, "There is not a file .ber", 23);
		exit(1);
	}
}

int	destroynotify(int des)
{
	(void)des;
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	pd;
	int		fd;

	if (ac == 2)
	{
		pd.count = 1;
		check_ber(av[1]);
		fd = open(av[1], O_RDONLY);
		pd.map = read_map(fd);
		check_map(pd.map);
		pd.i = 0;
		while (pd.map[pd.i])
		{
			pd.j = 0;
			while (pd.map[pd.i][pd.j])
				pd.j++;
			pd.i++;
		}
		pd.mlx = mlx_init();
		pd.mlx_wind = mlx_new_window(pd.mlx, pd.j * 50, pd.i * 50, "So_Long");
		render_map(pd.mlx, pd.mlx_wind, &pd);
		mlx_key_hook(pd.mlx_wind, moveplayer, &pd);
		mlx_loop(pd.mlx);
	}
	write(1, "error\n", 6);
}
